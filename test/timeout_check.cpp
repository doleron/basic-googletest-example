#include <future>

#include "gtest/gtest.h"

#include "very_important_operations.h"

/**
 * so far google testing fw doesn' t provide a TIMEOUT utility. 
 * As workaround it is widely adopted the use of std::async and std::future solutions
 * Here we apply the solution found here: http://antonlipov.blogspot.com.br/2015/08/how-to-timeout-tests-in-gtest.html 
 * */
#define TEST_TIMEOUT_BEGIN                           \
  std::promise<bool> promisedFinished;               \
  auto futureResult = promisedFinished.get_future(); \
                              std::thread([](std::promise<bool>& finished) {

#define TEST_TIMEOUT_FAIL_END(X)                                            \
  finished.set_value(true);                                                 \
  }, std::ref(promisedFinished)).detach(); \
  EXPECT_TRUE(futureResult.wait_for(std::chrono::milliseconds(X)) != std::future_status::timeout);

#define TEST_TIMEOUT_SUCCESS_END(X)                                         \
  finished.set_value(true);                                                 \
  }, std::ref(promisedFinished)).detach(); \
  EXPECT_FALSE(futureResult.wait_for(std::chrono::milliseconds(X)) != std::future_status::timeout);

TEST(Timeout, UnderTimeout)
{
  TEST_TIMEOUT_BEGIN
  mySlowOperation(500);
  TEST_TIMEOUT_FAIL_END(1000)
}

TEST(Timeout, OverTimeout)
{
  TEST_TIMEOUT_BEGIN
  mySlowOperation(2000);
  TEST_TIMEOUT_SUCCESS_END(1000)
}
