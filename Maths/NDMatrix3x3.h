/////////////////////////////////////////////////////////////////////
//  Vectors.h
//  Created by NickDavies on 5/08/2018.
//  Copyright © 2018 NickDavies. All rights reserved.
/////////////////////////////////////////////////////////////////////

#pragma once

class NDVector;

class NDMatrix3x3
{
public:

	NDMatrix3x3()
	{}

	static NDVector Multiply(const NDVector& Vector, const NDMatrix3x3& MultiplyMatrix);

	static NDVector Rotate(NDVector RotateVector, NDVector Origin, float Angle, int Axis = 0);

public:
	float m11, m12, m13 = 0.f;
	float m21, m22, m23 = 0.f;
	float m31, m32, m33 = 0.f;
};