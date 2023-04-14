|                    |                                  |
| :----------------- | :------------------------------- |
| **Objectives**     | Increase code quality by example |
| **Teacher**        | Luca Tricerri                    |
| **Duration**       | 3 sessions each of 2 hours       |
| **Prerequisites**  | basic C++11 or Java              |
| **Class Max Size** | 10                               |
| **Target**         | PhD students                     |

# 1. Reading Note 
This file can be read using
- VisualStudio code
- Markdown Preview Github Styling
  
Launch VS Code Quick Open (Ctrl+P), paste the following command, and press enter. 
``` 
ext install bierner.markdown-preview-github-styles
```
# 2. Description
Increase code quality using unit tests via gtest and gmock.

## 2.1. Main Topics
- Unit test introduction
- How to unit test with gtest
- What is moking?
- How to mock with gmock

## 2.2. When
End of April, if possible in presence.

## 2.3. Prerequisite
- Create a Github account (https://github.com/)
- Create a Gitpod account (https://www.gitpod.io/) using Github credentials.
- Install Chrome extension: https://chrome.google.com/webstore/detail/gitpod-always-ready-to-co/dodmmooeoklaejobgleioelladacbeki
- Fork this repository:  
    go to [this repo](https://github.com/triccyx/gtest-training)  
    and use the `fork button` upper right.  

    ![alt](img/gitpod001.png)

    
- Go to `your` Github account and select repo `gtest-training`
- Use the `GitPod button`. It will take a while the first time.


[What is Gitpod?](https://www.gitpod.io/docs/getting-started)


## 2.4. Disclaimer
Please note the following:
- All in this document is copied from internet site and book
- Do not pretend to remember the syntax, just remember that something can be done

# 3. WHY UNIT TEST
:question: So how can I test my software? `There are several ways to do that`.  

UNIT TESTING is a type of software testing where individual units or components of the software are tested. The purpose is to validate that each unit of the software code performs as expected. Unit Testing is done during the development (coding phase) of an application by the developers. Unit Tests isolate a section of code and verify its correctness. A unit may be an individual function, method, procedure, module, or object.

![alt text](img/ut004.png)
<p style="text-align: center;"><i> The so called tests pyramid</i></p>


:question: What are the advantages to write unit tests?  
## 3.1. Early debug
Unit tests help to fix bugs early in the development cycle and save costs.
In this stage, the software is easier to debug:
- It is smaller.
- It is less interdependent on other parts.

___
:pushpin: **Marconi's approach to software testing (2004).**  
Marconi was a large company that developed a particular mobile phone technology called TETRA. It was a kind of GSM / UMTS / 4G mobile phone network for police and military forces.  
They had created a test group in Florence with about 20 telecommunications engineers, but they had poor results.  
The head of the test group decided to take 20 philosophy graduates instead of engineers. I was among the ones that developed the TETRA, I was there in that mess.  In the beginning, the so-called monkey tests were an incredible success. Bug after bug, but... as the testers were not technicians they report on the tests were almost impossible to reproduce. So in the end, the 20 philosophy graduates went back to their studies.  
<img src="img/marconi.jpg" width="400"/>  
**The system was simply too complex to be tested all together.**
___


## 3.2. Avoid regressions so you can refactor your code
When you have a suite of unit tests, you can run it iteratively to ensure that everything keeps working correctly every time you add new functionality or introduce changes. This helps **refactoring** a lot.

![alt text](img/ut002.jpg)

:question: What is refactoring?  
 Using an Agile methodology we continuously develop new and unplanned features from the beginning. In this context, the application architecture may become unstable. Periodic refactoring is important.

 :pushpin: **Siemens's approach to non-regression tests (2010).**  
 <img src="img/coke.jpg" width="300"/>  
 One of the most important customers of Siemens in Genoa was the Coca-cola company.
 The company wanted always new features, very well paid. Siemens was releasing new versions one after the other testing only the new features.
 A simple bug due to the addition of a new feature, but in a very old and important part of the code, stopped two factories for 1 week.  
 Siemens in the end lost its client.  
**The system does have not unit tests for non-regression purposes.**

## 3.3. Document your code
Running, debugging, or even just reading tests can give a lot of information about how the original code works, so you can use them as implicit documentation.  
Note that in this way the code documentation is always updated (otherwise the code does not compile)

![alt text](img/ut003.jpeg)

## 3.4. Unit testing improves code coverage 

Unit testing helps to improve code coverage.  
:question: What is test coverage?  
It is a technique to ensure that your tests are testing your code or how much of your code you exercised by running the test. Are there code parts not tested?

## 3.5. Unit Testing Myth
- It requires time, and I am always overscheduled
My code is rock solid! I do not need unit tests.
- Programmers think that Integration Testing will catch all errors and do not execute the unit test. Once units are integrated, very simple errors which could have been very easily found and fixed in units test take a very long time to be traced and fixed.

The truth is Unit testing increases the speed of development.

![alt text](img/ut001.png)

# 4. HOW TO UNIT TEST

## 4.1. Good practices for unit testing include
- Creating tests for all **publicly exposed** functions, including class constructors and operators.
- Covering all code paths and checking both trivial and **edge cases**, including those with incorrect input data (negative testing).
- Assuring that each test works independently and does not prevent other tests from execution.
- Organizing tests in a way that the order in which you run them does not affect the results.

![alt text](img/ut005.jpg)

## 4.2. A single test
A single unit test is a method that checks some specific functionality and has clear pass/fail criteria. The generalized structure of a single test looks like this:

Test (TestGroupName, TestName)   {
- setup block
- running the under-test functionality
- checking the results (assertions block)
}


## 4.3. Modularize your code
As code's testability depends on its design, unit tests facilitate breaking it into specialized easy-to-test pieces.
An easy way to do this is to use self-consistent classes.  
Another useful technique is the so-called **dependence injection**.
It is a technique in which an object receives other objects. The receiving object is called a client and the passed-in (`injected`) object is called a service.   


![alt text](img/ut006.jpg)

With no partcular tecnique:  
```c++
class MyClass
{
    private:
        Database mydatabase_;
    public:
        int getIntFromDatabase(const std::string& query)
        {
            ...
            return mydatabase_.get(query);
        }
};
```  
With inheritance  
```c++
class MyClass: public Database
{
    public:
        int getIntFromDatabase(const std::string& query)
        {
            ...
            return get(query);
        }
};
```

With dependency injection  
```c++
class MyClass
{
    private:
        Database& mydatabase_;
    public:
        MyClass(Database &mydatabase):mydatabase_(mydatabase)
        {}
        int getIntFromDatabase(const std::string& query)
        {
            ...
            return mydatabase_.get(query);
        }
};
```


The use of the inheritance technique tightly couples parent class with child class. It is harder to reuse the code and write units.  
<h3>Best choice: dependency injection.</h3>

![alt text](img/ut007.png)


## 4.4. Reference for Unittest
- https://www.jetbrains.com/help/clion/unit-testing-tutorial.html#basics  
- https://www.guru99.com/unit-testing-guide.html  
- Test coverage: https://www.guru99.com/test-coverage-in-software-testing.html#1
- https://betterprogramming.pub/13-tips-for-writing-useful-unit-tests-ca20706b5368

# 5. GTEST
googletest is a testing framework developed by the Testing Technology team with Google’s specific requirements and constraints in mind. Whether you work on Linux, Windows, or a Mac.
- very well done
- very well supported
- cmake friend
- visual studio code friend
- cross-platform
- works also with C language (with limitations)

## 5.1. The tests are simple

```c++
TEST(Multiplier, check_multiply_001)
{
    Multiplier mult;
    EXPECT_EQ(8/*expected*/, mult.invoke(4, 2)/*current*/);
}
```

**CODE**: See code:multiplierlib and test:testMultiplier.cpp

## 5.2. Small important details

![alt text](img/ut008.png)

### 5.2.1. Expected and current order
This is only a note to remember to correctly order the expected and current values.
```c++
    EXPECT_EQ(8/*expected*/, mult.invoke(4, 2)/*current*/);
```
The unit test framework usually gives the error log based on this assumption.

```
./training-programming-best-practices/unittest-course-part/src/unittest/testMultiplier.cpp:21: Failure
Expected equality of these values:
  8
  mult.invoke(4, 2)
    Which is: 7
[  FAILED  ] Multiplier.Test_simple001 (0 ms)
```

### 5.2.2. Name

Choose good names for tests, see for reference:https://dev.to/canro91/unit-testing-best-practices-6-tips-for-better-names-524m.


- Choose a naming convention for your test names and stick to it.
- Every test name should tell the scenario under test and the expected result. Do not worry about long test names. But, do not name your tests: Test1, Test2, and so on.
- Describe in your test names what you are testing, in a language easy to understand even for non-programmers.

❌ Do not prefix your test names with "Test". If you're using a testing framework that does not need keywords in your test names, don't do that.  

![alt text](img/ut009.jpg)

___
:pushpin:   
By Joel:  
the infamous Hungarian naming convention:  
https://www.joelonsoftware.com/2005/05/11/making-wrong-code-look-wrong/

### 5.2.3. Test in code

Don't mix test code with production code (never):

```c++
class WinterAssistant {
  public:
    bool isTest_ = false;

    bool needWinterJacket() {
        Thermometer *thermometer;
        if( isTest_ )
        {
            thermometer = new FakeThermometer();
        } else 
        {
            thermometer = new Thermometer();
        }

        return thermometer->getTemperature() < 40;
  }
}
```
In this case, you can use easily the code injection technique.

### 5.2.4. Run Your Tests as Part of Every Automated Build

Just as you should be running your tests as you develop, they should also be an integral part of your continuous integration process. A failed test should mean that your build is broken.

### 5.2.5. Keep test code simple

Avoid in test, when possible:
- for loop
- if/case statement
- function call (excluding the tested function of course)
- ...

## 5.3. Check macro
Other EXPECT and ASSERT macro exist:  
```c++
EXPECT_TRUE
EXPECT_FALSE
EXPECT_EQ  
EXPECT_NE
EXPECT_GT
...
ASSERT_TRUE
ASSERT_FALSE
ASSERT_EQ  
ASSERT_NE
ASSERT_GT
...
FAIL
```

See also:  
https://github.com/google/googletest/blob/main/docs/reference/assertions.md


## 5.4. Check fatal/non-fatal macro
ASSERT vs EXPECT  
```c++
    EXPECT_EQ(8/*expected*/, mult.invoke(4, 2)/*current*/
    ASSERT_EQ(8/*expected*/, mult.invoke(4, 2)/*current*/
```
Assert abort the current test while Expect gives only the error but goes on.
Expect is preferred.

## 5.5. Test with Fixtures
If you find yourself writing two or more tests that operate on similar data, you can use a test fixture. This allows you to reuse the same configuration of objects for several different tests.


**CODE**: See test:testMultiplierParamAndFixture.cpp

## 5.6. Test with Parameters

**CODE**: See code:multiplierlib and   test:testMultiplierParamAndFixture.cpp

## 5.7. Test private members

For testing private members we can use one of the C++ `most hidden` features.
It is possible to change visibility over inherited members.

```c++
class Multiplier
{
    protected:
        virtual void internalInvoke();//To be tested
};


class TestMultiplier : public Multiplier
{
   public:
        using Multiplier::internalInvoke;
};
```

The only prerequisite is that the method should be `virtual`.

**CODE**: See code:multiplierlib and test:testMultiplierInternal.cpp

## 5.8. Test exceptions
Also thrown exceptions can be tested.
```c++
EXPECT_THROW(mult.invoke(10, 2), std::invalid_argument);
```

**CODE**: See code:multiplierlib and test:testMultiplier.cpp

## 5.9. Test death

If we expect that a function closes the program with an error that contains "must be true".

```c++
TEST(MyDeathTest, Exit) 
{
  MyClass myclass();
  EXPECT_DEATH( { myclass.foo(); }, "must be true");
}
```
Plain exits:

```c++
TEST(MyDeathTest, NormalExit) 
{
  EXPECT_EXIT(NormalExit(), testing::ExitedWithCode(0), "Success");
}
```

Exit due to a signal and an error that matches "Sending myself unblockable signal"

```c++
TEST(MyDeathTest, KillProcess) 
{
  EXPECT_EXIT(KillProcess(), testing::KilledBySignal(SIGKILL),"Sending myself unblockable signal");
}
```

## 5.10. The main
Quite easy to write:
```c++
#include "gtest/gtest.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
     return RUN_ALL_TESTS();
}
```

For filtering the tests add:
```c++
   ::testing::GTEST_FLAG(filter) = "Test.Test_003";
```
or you can use a wildcard:
```c++
   ::testing::GTEST_FLAG(filter) = "Test.T*";
```

## 5.11. Visual studio code
VC is perfectly integrated with gtest, install the test explorer extension see:  
https://marketplace.visualstudio.com/items?itemName=matepek.vscode-catch2-test-adapter

The test explorer:  

![alt text](img/vc001.png)

:heavy_check_mark:
It could be necessary to add in settings.json:
```
testMate.cpp.test.executables": "${workspaceFolder}/install/bin/unittest"
```
With your install path.

## 5.12. How to cmake

```cmake
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
```

## 5.13. References for gtest
https://google.github.io/googletest/primer.html

# 6. Unit Testing C code
Is it possible UT for the C code? Yes, it is possible and it is widely done.
There are some limitations to using gtest with C code.
-  You cannot create an instance of the code under test
-  You should take care of the initialization

**CODE**: See code:multiplierlib and test:testMultiplier-c.cpp
## 6.1. Reference
Refer to:  
- https://moderncprogramming.com/what-is-the-best-unit-testing-framework-in-c-for-you/
- https://moderncprogramming.com/is-unit-testing-in-c-with-google-test-possible/

# 7. ChatGpt
You can also start to ask ChatGpt to write  UT for you. Sometimes you will need to correct them but the result could be amazing:

```c++

#include <gtest/gtest.h>
#include "Multiplier.h"

TEST(MultiplierTest, ValidArguments)
{
    Multiplier multiplier;
    double result = multiplier.invoke(2, 3);
    EXPECT_DOUBLE_EQ(result, 6);
}

TEST(MultiplierTest, InvalidArgument)
{
    Multiplier multiplier;
    EXPECT_THROW(multiplier.invoke(10, 3), std::invalid_argument);
}
```

# 8. Exercises

## 8.1. Injection

Change this code using the code injection technique.

```c++
class CanSenderScheduler {
  public:
#ifndef TEST    
    bool isTest_ = false;
#else
    bool isTest_ = true;
#endif

    bool sendData(const std::vector<unsigned char>  &data)
    {
        CanServer *server;
        if( isTest_ )
        {
            server = new FakeCanServer(12);
        } else 
        {
            server = new CanServer(12);
        }

        return server->send(data);
    }
};

class CanServer
{
    public:
        CanServer(unsigned int address);
        bool send(const std::vector<unsigned char>  &data);
}

```

## 8.2. The division class 
- Complete the division class in `divisionlib` (take a look at the Multiplier class)
- As input, the method invokes, can have only numbers > -30.
- Add the unit test for the class. Be careful with the edge cases.

The skeleton is in `testDivision.cpp`

# 9. Testing complex objects

To test your complex class without the connected/related classes, you could use a mocking framework.
Not always is possible to obtain the desired result, it depends mainly on how your code is written.
If you are using dependency injection, the testability of the code is much better since you can inject mocks as well.

## 9.1. MOCK
A mock object implements the same interface as a real object (so it can be used as one), but lets you specify at run time how it will be used and what it should do (which methods will be called? in which order? how many times? with what arguments? what will they return? etc...).

![alt text](img/ut010.jpg)


## 9.2. MOCK vs STUB

Mocking is a way to replace a dependency in a unit under test with a stand-in for that dependency. The stand-in allows the unit under test to be tested without invoking the real dependency. 

**Stub**: Stub is an object that holds predefined data and uses it to answer calls during tests. Such as an object that needs to grab some data from the database to respond to a method call.

**Mocks**: Mocks are objects that register calls they receive. In test assertion, we can verify on Mocks that all expected actions were performed. A mock is like a stub but, the test will also verify that the object under test calls the mock as expected. Part of the test is verifying that the mock was used correctly.  
Also, the mocks can be `programmed` to give certain result values or behaviours.

## 9.3. How to
We are using gmock which is the moking library for gtest.  

When using gMock,

- first, you use some simple macros to describe the interface you want to mock, and they will expand to the implementation of your mock class.
- next, you create some mock objects and specify their expectations and behaviour using an intuitive syntax.
- then you exercise code that uses the mock objects. gMock will catch any violation of the expectations as soon as it arises.  

## 9.4. Dependency injection.

Mocking needs dependency injection to work better.
[See above](#33-modularize-your-code)

## 9.5. Disclaimer
This part of the course will be done by examples.


## 9.6. Simple mock
First of all, you need to mock the class and method we do not want to test directly.
```c++
class ...
{
    ...
    MOCK_METHOD(double, getDataFromFile, (unsigned int), (const, override));  // note the parentesis
}
```
**CODE**: See test:testMultiplierFromFile.cpp

## 9.7. Simple tests

**CODE**: See test:testMultiplierFromFile.cpp

## 9.8. Test c std API
In this case, is necessary to write a class to overlap the c API.  
See file: InterfaceForCApi.h

**CODE**: See test:testMediaScanner.cpp

## 9.9. Reference for gmock
http://google.github.io/googletest/gmock_cook_book.html

# 10. Exercises              

## 10.1. Pwm
Mock and write unit tests for `pwmlib`. You can find the skeleton in `testPwm.cpp`.

# 11. GitPod
How to:
- Fork the [training repo](https://github.com/icub-tech-iit/training-programming-best-practices/blob/master/unittest-course-part/README.md)  
![alt](img/gitpod001.png)
- Only for Visual Studio Code users. Install the extension on Visual Studio Code. This step is not mandatory.  
![alt](img/gitpod002.png)
- Enter GitPod with the button (the first time it will take 5 minutes).  

[![Open in Gitpod](https://gitpod.io/button/open-in-gitpod.svg)](https://gitpod.io/from-referrer/)
- Create a build folder, create a makefile and compile
  ```bash
  cd /workspace/training-programming-best-practices/src
  mkdir build
  cd build
  cmake -DCMAKE_INSTALL_PREFIX=/workspace/training-programming-best-practices/install ..
  make install
  ```

- Execute UT
```bash
cd /workspace/training-programming-best-practices/install/bin
./unittest
```
   
# 12. Feedback

For future training ...  
Please send me feedback with all the critical points that can be done better and the things that are good.   
Luca.tricerri@gru.bitron-ind.com
