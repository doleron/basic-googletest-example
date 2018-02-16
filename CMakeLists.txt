cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME basic_googletest_example)
project(${PROJECT_NAME} CXX)

find_package(Threads REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")

include_directories(include)

add_library(very_important_operations_lib ${PROJECT_SOURCE_DIR}/src/very_important_operations.cpp)

file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} very_important_operations_lib)

option(BUILD_TESTS "Build the tests" OFF)

if(BUILD_TESTS)

  add_subdirectory(libs/googletest)

  enable_testing()

  set(PROJECT_TEST_NAME ${PROJECT_NAME}_test)

  include_directories(${GTEST_INCLUDE_DIRS})

  file(GLOB TEST_SRC_FILES "${PROJECT_SOURCE_DIR}/test/*.cpp")
  add_executable(${PROJECT_TEST_NAME} ${TEST_SRC_FILES})

  add_dependencies(${PROJECT_TEST_NAME} googletest)

  target_link_libraries(${PROJECT_TEST_NAME}
    ${GTEST_LIBS_DIR}/libgtest.a
    ${GTEST_LIBS_DIR}/libgtest_main.a
  )

  target_link_libraries(${PROJECT_TEST_NAME} very_important_operations_lib)

  target_link_libraries(${PROJECT_TEST_NAME} ${CMAKE_THREAD_LIBS_INIT})

  add_test(NAME project_test COMMAND ${PROJECT_TEST_NAME})

endif()