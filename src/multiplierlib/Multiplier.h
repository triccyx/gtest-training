
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

class Multiplier
{
   public:
	double invoke(double, double) const;

   void setup();
   void clear();

   protected:
	virtual double internalInvoke(double, double) const;
};
