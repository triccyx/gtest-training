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

#include <errno.h>
#include <fcntl.h>
#include <libudev.h>
#include <linux/media.h>
#include <linux/v4l2-subdev.h>
#include <linux/videodev2.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

struct udev
{
};

// Wraper for unittest use of c style API
class InterfaceForCApi
{
   public:
	virtual int open_c(const char *path, int oflag)
	{
		return open(path, oflag);  // Linux API
	}

	virtual struct udev *udev_new_c()
	{
		return udev_new();	// Linux API
	}

	//...

	virtual ~InterfaceForCApi(){};
};
