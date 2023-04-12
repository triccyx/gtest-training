/******************************************************************************
 *                                                                            *
 * Copyright (C) 2023 Luca Tricerri        *
 * All Rights Reserved.                                                       *
 *                                                                            *
 ******************************************************************************/

/**
 * @luca.triceri@iit.it
 */

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "motor.h"
#include "pwm.h"

using namespace testing;
using ::testing::_;
using ::testing::An;
using ::testing::Gt;
using ::testing::InSequence;
using ::testing::InvokeArgument;
using ::testing::Matcher;
using ::testing::TypedEq;

class Motor_Mock : public Motor
{
   //...
};

TEST(MotorFile, Test_base_001)
{
	Motor_Mock motor;

	//...

}