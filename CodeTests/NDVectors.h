/////////////////////////////////////////////////////////////////////
//  Vectors.h
//  Created by NickDavies on 21/07/2018.
//  Copyright © 2018 NickDavies. All rights reserved.
/////////////////////////////////////////////////////////////////////

#pragma once

class NDVector
{
public:

	NDVector(float inX, float inY, float inZ)
		: x(inX)
		, y(inY)
		, z(inZ)
	{}

	NDVector()
		: x(0), y(0), z(0)
	{}


	void PrintVector() const;
	float DotProd(const NDVector& CompareVector) const;
	float GetAngle(const NDVector& CompareVector) const;
	NDVector CrossProd(const NDVector& CompareVector) const;
	NDVector Normalize() const;
	NDVector Add(const NDVector& CompareVector) const;
	NDVector Subtract(const NDVector& CompareVector) const;
	float Size() const;
	float SizeSq() const;
	NDVector Project(const NDVector& CompareVector) const;

	NDVector operator*(float Size)
	{
		return NDVector(x * Size, y * Size, z * Size);
	}

public:
	float x = 0.f;
	float y = 0.f;
	float z = 0.f;
};