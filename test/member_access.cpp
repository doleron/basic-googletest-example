#include "gtest/gtest.h"

#include "very_important_operations.h"

class SomeEntityTest : public ::testing::Test {
protected:

	virtual void SetUp() {
		anEntity.setX(10);
	}

	virtual void TearDown() {
	}

	SomeEntity anEntity;
};

TEST_F(SomeEntityTest, CheckSetUP) {
	int value = anEntity.getX();
	EXPECT_EQ(10, value);
}

TEST_F(SomeEntityTest, ParamReferenceTest) {
	int value = 20;
	anEntity.operationOnReference(value);
	EXPECT_EQ(1, value);
}

TEST_F(SomeEntityTest, ParamValueTest) {
	int value = 20;
	anEntity.operationOnValue(value);
	EXPECT_EQ(20, value);
}

TEST_F(SomeEntityTest, ParamPointerTest) {
	int* pointer = new int;
	*pointer = 20;
	anEntity.operationOnPointer(pointer);
	EXPECT_EQ(1, *pointer);
	delete pointer;
}
