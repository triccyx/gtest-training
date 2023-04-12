
/******************************************************************************
 *                                                                            *
 * Copyright (C) 2023 Luca Tricerri        *
 * All Rights Reserved.                                                       *
 *                                                                            *
 ******************************************************************************/

/**
 * @luca.triceri@iit.it
 */


#pragma once

//interface to motor
class Motor
{
   public:
	virtual bool apply(double pwm) const
	{
        //...
		return true;
	};
};