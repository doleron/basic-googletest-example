#include <vector>
#include <future>
#include <algorithm>

#include "gtest/gtest.h"

#include "very_important_operations.h"

/**
 * check the factorial table at https://www.rapidtables.com/math/algebra/Factorial.html
 * */
TEST(FactorialTest, BaseCases)
{
	std::vector<int> inputs{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	std::vector<int> expectedResults{1, 1, 2, 6, 24, 120, 720, 5040, 40320, 
		362880, 3628800, 39916800, 479001600};

	unsigned int size = inputs.size();

	for(unsigned int index = 0; index < size; index++) {
		auto n = inputs[index];
		auto actualResult = int_factorial(n);
		auto expectedValue = expectedResults[index];
		EXPECT_EQ(expectedValue, actualResult);
	}

}

TEST(FactorialTest, PreConditionCheck)
{
	ASSERT_THROW(int_factorial(-1), std::out_of_range);
}

TEST(FactorialTest, OverflowCheck)
{
	ASSERT_THROW(int_factorial(13), std::overflow_error);
}
