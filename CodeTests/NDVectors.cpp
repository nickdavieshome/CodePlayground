//
//  VectorTest.cpp
//
//  Created by NickDavies on 21/07/2018.
//  Copyright © 2018 NickDavies. All rights reserved.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <functional>
#include "NDVectors.h"

using namespace std;

void NDVector::PrintVector() const
{
	std::cout << "Vector: " << x << "," << y << "," <<  z << "\n";
}

float NDVector::DotProd(const NDVector& A, const NDVector& V)
{
	return A|V;
}

float NDVector::operator|(const NDVector& V) const
{
	return (x * V.x) + (y * V.y) + (z * V.z);
}

float NDVector::GetAngle(const NDVector& V) const
{
	NDVector NormalA = Normalize();
	NDVector NormalB = V.Normalize();
	return acos(NormalA|NormalB) * (180.0/3.141592653589793238463);
}

NDVector NDVector::CrossProd(const NDVector& V) const
{
	return NDVector(((y * V.z) - (z * V.y)), ((z * V.x) - (x * V.z)), ((x * V.y) - (y * V.x)));
}

NDVector NDVector::Normalize() const
{
	float fSize = Size();
	return NDVector(x/fSize, y/fSize, z/fSize);
}

NDVector NDVector::Add(const NDVector& V) const
{
	return NDVector(x + V.x, y + V.y, z + V.z);
}

NDVector NDVector::Subtract(const NDVector& V) const
{
	return NDVector(x - V.x, y - V.y, z - V.z);
}

float NDVector::Size() const
{
	return sqrt((x*x) + (y*y) + (z*z));
}

float NDVector::SizeSq() const
{
	return (x*x) + (y*y) + (z*z);
}

NDVector NDVector::Project(const NDVector& V) const
{
	NDVector Local = NDVector(x,y,z);
	return Local * ((Local | V) / SizeSq());
}
