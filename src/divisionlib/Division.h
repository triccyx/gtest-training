
/******************************************************************************
 *                                                                            *
 * Copyright (C) 2022 Fondazione Istituto Italiano di Tecnologia (IIT)        *
 * All Rights Reserved.                                                       *
 *                                                                            *
 ******************************************************************************/

/**
 * @triccyx@gmail.com
 */

#pragma once

class Division
{
   public:
	double invoke(double, double) const;

   protected:
	virtual double internalInvoke(double, double) const;
};