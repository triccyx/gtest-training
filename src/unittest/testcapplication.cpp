/******************************************************************************
 *                                                                            *
 * Copyright (C) 2023 Luca Tricerri                                           *
 * All Rights Reserved.                                                       *
 *                                                                            *
 ******************************************************************************/

/**
 * @triccyx@gmail.com
 */

#include "capplication.h"
#include "gtest/gtest.h"
#include "fff.h"
#include <functional>
// Simple UT

DEFINE_FFF_GLOBALS;
FAKE_VALUE_FUNC(FILE*, fopen_mock, const char*, const char*);

FILE *fopen_custom(const char *filename, const char *mode)
{
	FILE a;
    std::cout<<"xxxxxxxxxxxxxxxxxxxx"<<std::endl;
	return &a;
	// write code here for mock function implementation...
}

/*
TEST(test_group_name, test_name)
{
	int (*temp_holder)(void) = A1;	// hold the original pointer in a temp pointer
	// setting customized mock function for this test
	A1_mock_fake.custom_fake = A1_custom;
	A1 = A1_mock;

	// simple example of a test using the the FFF framework:
	int x;
	x = A1();
	ASSERT_EQ(A1_mock_fake.call_count, 1);

	// assign A1 to call the original function back again so that the mock function exists only in the scope of this test
	A1 = temp_holder;
	RESET_FAKE(A1_mock);  // reset all parameters of the mock function used so when used in a subsequent test we will start "clean"
}*/

TEST(capplication, 001)
{
    std::function<FILE*(const char *, const char *)> temp_fopen=fopen;
	//FILE* (*temp_fopen)(const char *, const char *) = fopen;
	fopen_mock_fake.custom_fake = fopen_custom;
	//FILE*(*fopen)(const char*, const char*) = fopen_mock;
    fopen= &fopen_mock;

	double res = doSomething(1, 2);
	EXPECT_EQ(2, res);
	EXPECT_EQ(fopen_mock_fake.call_count, 1);

	FILE*(*fopen)(const char*, const char*) = &temp_fopen;
	//RESET_FAKE(fopen_mock);
}