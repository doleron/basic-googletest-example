# basic-googletest-example

## Description

This project is an example how to use google testing framework, one of the most popular framework for unit test C++ projects.

As usual, cmake is used for build generation. The google test (or just gtest) library github repository is cloned in build time.

Some features applied in this example:

- Fixtures
- Parametized build for test/non test
- Several .cpp test files
- Different directories for src and test
- std::future tasks for timeout checking
- Exception thrown assertion

Instead of perform a long jorney along all gtest features, this spike is focused into how to build your project with cmake/gtest. It is strongly recommended to read the Google Testing Premier at https://github.com/google/googletest/blob/master/googletest/docs/Primer.md

## build instructions

The truth is in the commands:

```
git clone https://github.com/doleron/basic-googletest-example.git
cd basic-googletest-example
mkdir build
cd build
cmake -DBUILD_TESTS=ON ..
make
```

In the first time ```make``` is called, gtest is cloned/build from its repository on github. cmake/make do it for you without actually install gtest in your system. Just the required files are stored into build/libs folder. 

It is pretty desirable to control when your build for testing purpose or release. If you didn't want to build the test artifacts just call

```cmake ..```

instead of ```cmake -DBUILD_TESTS=ON ..```. Optionally you can run cmake as follow ```cmake -DBUILD_TESTS=OFF ..```

## running test and other stuff

If you decided build with -DBUILD_TESTS=ON you have two options to run the tests:

### using make test

Is just it, call ```make test``` and let make run the tests. The output is really poor. Just says if the tests passed or not.

### Running the tests like a regular cpp aplication

The tests are build into a single executable called "basic_googletest_example_test". Thus, if you like to see a bit more informations about the test execution, just type:

cd build
./basic_googletest_example_test

## Requirements

I ran this example into an Ubuntu 16.04 virtual machine. Make sure that you have a c++11 compliant compiler. My current compiler/version is the g++/5.4.

