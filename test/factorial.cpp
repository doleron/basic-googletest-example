#include <vector>
#include <future>

#include "gtest/gtest.h"

#include "very_important_operations.h"
#include "functional_helpers.h"

/**
* EXPECT_EQ is a macro, not a real function.
* The workaround is to enclosed it in a local function
* in order to pass it as parameter.
* */
auto call_EXPECT_EQ = [](int a, int b) {
	EXPECT_EQ(a, b);
};

TEST(FactorialTest, BaseCases)
{
	std::vector<int> inputs{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	std::vector<int> expectedResults{1, 1, 2, 6, 24, 120, 720, 5040, 40320, 
		362880, 3628800, 39916800, 479001600};

	std::vector<int> actuallResults = map(inputs, int_factorial);

	iterativeCall(expectedResults, actuallResults, call_EXPECT_EQ);
}

TEST(FactorialTest, PreConditionCheck)
{
	ASSERT_THROW(int_factorial(-1), std::out_of_range);
}

TEST(FactorialTest, OverflowCheck)
{
	ASSERT_THROW(int_factorial(13), std::overflow_error);
}
