/******************************************************************************
 *                                                                            *
 * Copyright (C) 2023 Luca Tricerri                                           *
 * All Rights Reserved.                                                       *
 *                                                                            *
 ******************************************************************************/

/**
 * @triccyx@gmail.com
 */

#include "Multiplier.h"
#include "gtest/gtest.h"

// Simple UT with internal functions

class TestMultiplier : public Multiplier
{
   public:
	using Multiplier::internalInvoke;
};

TEST(InternalMultiplier, internal_method_simple001)
{
	TestMultiplier mult;
	EXPECT_EQ(2, mult.internalInvoke(1, 2));
	EXPECT_TRUE(mult.internalInvoke(1, 2) == 2);
	EXPECT_FALSE(mult.internalInvoke(1, 2) == 3);
}

TEST(InternalMultiplier, internal_method_simple002)
{
	TestMultiplier mult;
	EXPECT_TRUE(mult.internalInvoke(1, 2) == 2);
	EXPECT_FALSE(mult.internalInvoke(1, 2) == 3);
}
