//
//  VectorTest.cpp
//
//  Created by NickDavies on 21/07/2018.
//  Copyright © 2018 NickDavies. All rights reserved.
//

#include <math.h>
#include "NDMatrix3x3.h"
#include "NDVectors.h"

NDVector NDMatrix3x3::Multiply(const NDVector& Vector, const NDMatrix3x3& MultiplyMatrix)
{
	NDVector TempVector;
	TempVector.x = (MultiplyMatrix.m11 * Vector.x) + (MultiplyMatrix.m21 * Vector.y) + (MultiplyMatrix.m31 * Vector.z);
	TempVector.y = (MultiplyMatrix.m12 * Vector.x) + (MultiplyMatrix.m22 * Vector.y) + (MultiplyMatrix.m32 * Vector.z);
	TempVector.z = (MultiplyMatrix.m13 * Vector.x) + (MultiplyMatrix.m23 * Vector.y) + (MultiplyMatrix.m33 * Vector.z);

	return TempVector;
}

NDVector NDMatrix3x3::Rotate(NDVector RotateVector, NDVector Origin, float Angle, int Axis)
{
	// Set up rotation maxtix

	NDVector Temp = RotateVector - Origin;

	NDMatrix3x3 TempMatrix;

	if(Axis == 0)
	{
		TempMatrix.m11 = cos(Angle);
		TempMatrix.m12 = sin(Angle);
		TempMatrix.m13 = 0;

		TempMatrix.m21 = -sin(Angle);
		TempMatrix.m22 = cos(Angle);
		TempMatrix.m23 = 0;

		TempMatrix.m31 = 0;
		TempMatrix.m32 = 0;
		TempMatrix.m33 = 1;
	}
	else if(Axis == 1)
	{
		TempMatrix.m11 = cos(Angle);
		TempMatrix.m12 = 0;
		TempMatrix.m13 = -sin(Angle);

		TempMatrix.m21 = 0;
		TempMatrix.m22 = 1;
		TempMatrix.m23 = 0;

		TempMatrix.m31 = sin(Angle);
		TempMatrix.m32 = 0;
		TempMatrix.m33 = cos(Angle);
	}
	else
	{
		TempMatrix.m11 = 1;
		TempMatrix.m12 = 0;
		TempMatrix.m13 = 0;

		TempMatrix.m21 = 0;
		TempMatrix.m22 = cos(Angle);
		TempMatrix.m23 = sin(Angle);

		TempMatrix.m31 = 0;
		TempMatrix.m32 = -sin(Angle);
		TempMatrix.m33 = cos(Angle);
	}

	Temp = NDMatrix3x3::Multiply(Temp, TempMatrix);

	return Temp + Origin;


	/*
	float TempX = (cos(angle) * x) - (sin(angle) * y);
	float TempY = (sin(angle) * x) + (cos(angle) * y);
	return NDVector(TempX, TempY, 0);
	*/
}
