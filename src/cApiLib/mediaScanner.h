
/******************************************************************************
 *                                                                            *
 * Copyright (C) 2023 Luca Tricerri                                           *
 * All Rights Reserved.                                                       *
 *                                                                            *
 ******************************************************************************/

/**
 * @triccyx@gmail.com
 */

#include <string>

class InterfaceForCApi;

class MediaScanner
{
   public:
	MediaScanner(InterfaceForCApi& interface);
	bool scan(const std::string& media);  // method under test

	InterfaceForCApi& interfaceCApi_;
};