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
#include "VectorTest.h"

using namespace std;

void VectorTest::TestVectors()
{
	std::cout << "Vector Test\n";

	NDVector NewVector(2, 3, 0);
	NewVector.PrintVector();

	std::cout << "Size: " << NewVector.Size() << "\n";

	NDVector Normalized = NewVector.Normalize();
	Normalized.PrintVector();
	std::cout << "Size: " << Normalized.Size() << "\n";

	NDVector VectorB(2,-2,0);

	std::cout << "Angle: " << Normalized.GetAngle(VectorB.Normalize()) << "\n";

	std::cout << "DotProd: " << (NewVector | VectorB) << "\n";
	{
	NDVector Vector1(0,1,0), VectorT(1,1,0);
	VectorT.PrintVector();
	NDVector Vector2 = VectorT.Normalize();
	std::cout << "Angle: " << Vector2.GetAngle(Vector1) << "\n";
	std::cout << "Dot: " << NDVector::DotProd(Vector2, Vector1) << "\n";
	std::cout << "\n";
	}

	{
	NDVector Vector1(0,1,0), VectorT(1,-1,0);
	VectorT.PrintVector();
	NDVector Vector2 = VectorT.Normalize();
	std::cout << "Angle: " << Vector2.GetAngle(Vector1) << "\n";
	std::cout << "Dot: " << (Vector2|Vector1) << "\n";
	std::cout << "\n";
	}

	{
	NDVector Vector1(0,1,0), VectorT(-1,-1,0);
	VectorT.PrintVector();
	NDVector Vector2 = VectorT.Normalize();
	std::cout << "Angle: " << Vector2.GetAngle(Vector1) << "\n";
	std::cout << "Dot: " << (Vector2 | Vector1) << "\n";
	std::cout << "\n";
	}

	{
	NDVector Vector1(0,1,0), Vector2(-1,1,0);
	Vector2.PrintVector();
	std::cout << "Angle: " << Vector1.GetAngle(Vector2) << "\n";
	std::cout << "Dot: " << (Vector1|Vector2.Normalize()) << "\n";
	NDVector Vector1Perp = Vector1.CrossProd(NDVector(0,0,1));
	Vector1Perp.PrintVector();
	std::cout << "Dot: " << (Vector1Perp|Vector2.Normalize()) << "\n";
	std::cout << "\n";
	}

	{
		NDVector U(1,3,0);
		NDVector V(3,2,0);
		NDVector Projected = V.Project(U);
		Projected.PrintVector();
	}
}
