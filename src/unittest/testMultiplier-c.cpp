/******************************************************************************
 *                                                                            *
 * Copyright (C) 2023 Luca Tricerri                                           *
 * All Rights Reserved.                                                       *
 *                                                                            *
 ******************************************************************************/

/**
 * @triccyx@gmail.com
 */

#include <tuple>

#include "multiplier-c.h"
#include "gtest/gtest.h"
// Simple UT

TEST(Multiplier, multiply_check_positive_for_c_code_001)
{
	// EXPECT_EQ(expected,actual);<<<----expected,actual
	EXPECT_EQ(2, mult((double)1,(double) 2));
	ASSERT_EQ(2, mult((double)1, (double)2));
	// ASSERT_FALSE(mult.invoke(1, 2) == 2);
}
