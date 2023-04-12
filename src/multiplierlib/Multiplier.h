
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

class Multiplier
{
   public:
	double invoke(double, double) const;

   protected:
	virtual double internalInvoke(double, double) const;
};