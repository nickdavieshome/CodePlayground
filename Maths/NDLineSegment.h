/////////////////////////////////////////////////////////////////////
//  NDLineSegment.h
//  Created by NickDavies on 05/08/2018.
//  Copyright © 2018 NickDavies. All rights reserved.
/////////////////////////////////////////////////////////////////////

#pragma once

#include "NDVectors.h"

class NDLineSegment
{
public:

	NDLineSegment(NDVector inStartLocation, NDVector inEndLocation)
		: StartLocation(inStartLocation)
		, EndLocation(inEndLocation)

	{}


	NDLineSegment()
	{}

public:
	NDVector StartLocation, EndLocation;
};