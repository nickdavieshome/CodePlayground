//
//  InitializerTest.cpp
//  CodeTests
//
//  Created by NickDavies on 09/01/2017.
//  Copyright © 2017 NickDavies. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <initializer_list>
#include "InitializerTest.h"

class Widget {
public:
	Widget(int i, bool b)
	{
		std::cout << "Contructor 1!\n";
	}

	Widget(int i, double d)
	{
		std::cout << "Contructor 2!\n";
	}

	Widget(std::initializer_list<long double> il)   // This changes the braced initializer list
	{
		std::cout << "Contructor 3!\n";
	}
};

void InitializerTest::TestInitializer()
{
	std::cout << "Initializer Test\n";

	Widget{10, true};
	Widget{10,10.1};

	Widget W2({}); // Use empty initializer list
}
