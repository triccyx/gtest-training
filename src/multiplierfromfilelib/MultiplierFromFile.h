
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

#include <string>

class MultiplierFromFile
{
   public:
	explicit MultiplierFromFile(const std::string& fileName) : fileName_(fileName){};
	double invoke(unsigned int leftIndex, unsigned int rightIndex) const;
	double invoke2(unsigned int leftIndex, unsigned int rightIndex) const;
	double invoke3(unsigned int leftIndex, unsigned int rightIndex) const;

   private:
	virtual double getDataFromFile(unsigned int index) const;
	virtual double getDataFromFile(unsigned int index, double* out) const;
	virtual double getDataFromFile(unsigned int index, double& out) const;
	const std::string fileName_;
};