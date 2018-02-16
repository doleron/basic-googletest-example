#ifndef VERY_IMPORTANT_OPERATIONS_H_
#define VERY_IMPORTANT_OPERATIONS_H_

class SomeEntity {

public:
	
	void operationOnReference(int & param);
	void operationOnValue(int param);
	void operationOnPointer(int * param);

	void setX(int x) {
		this->x = x;
	}

	int getX() {
		return x;
	}

private:
	int x;

};

int int_factorial(int n );

int mySlowOperation(int sleepTimeInMills);

#endif /* VERY_IMPORTANT_OPERATIONS_H_ */