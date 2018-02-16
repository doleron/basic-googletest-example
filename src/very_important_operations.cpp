#include "very_important_operations.h"
#include <chrono>
#include <thread>
#include <string>

void SomeEntity::operationOnReference(int & param) {
	param = 1;
}

void SomeEntity::operationOnValue(int param) {
	param = 1;
}

void SomeEntity::operationOnPointer(int * param) {
	*param = 1;
}

int int_factorial(int n) {
    if(n < 0) {
        throw std::out_of_range("Factorial is not defined for negative numbers");
    }

    int result = 1;
    if(n > 1) { 
        int previous = int_factorial(n - 1);
        result = previous * n;
        if (result / n != previous) {
            std::string message = "Factorial of " + std::to_string(n) + " overflow the int range";
            throw std::overflow_error(message);
        }
    }

    return result;
}

int mySlowOperation(int sleepTimeInMills) {
    if(sleepTimeInMills <= 0) {
        throw std::out_of_range("mySlowOperation doesn' t accept negative inputs");
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(sleepTimeInMills));
    return 0;
}
