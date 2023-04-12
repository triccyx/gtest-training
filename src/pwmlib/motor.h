
/******************************************************************************
 *                                                                            *
 * Copyright (C) 2023 Luca Tricerri                                           *
 * All Rights Reserved.                                                       *
 *                                                                            *
 ******************************************************************************/

/**
 * @triccyx@gmail.com
 */

#pragma once

// interface to motor
class Motor
{
   public:
	virtual bool apply(double pwm) const
	{
		//...
		return true;
	};
};