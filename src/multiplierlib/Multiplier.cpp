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

#include <stdexcept>

double Multiplier::invoke(double left, double right) const
{
	if (left == 10)
	{
		throw std::invalid_argument("Wrong left argument");
	}
	return internalInvoke(left, right);
}

double Multiplier::internalInvoke(double left, double right) const
{
	return left * right;
}

void Multiplier::setup()
{  // Nothing to do
}
void Multiplier::clear()
{  // Nothing to do
}
