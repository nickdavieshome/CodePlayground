//
//  VariadicTemplateTest.cpp
//  CodeTests
//
//  Created by NickDavies on 09/01/2017.
//  Copyright © 2017 NickDavies. All rights reserved.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include "VariadicTemplateTest.h"

class FTestClass1
{
	public:
	const std::string ToString() const
	{
		return "hello";
	}
};

class FTestClass2
{
	public:
	const std::string ToString() const
	{
		return "hello 2";
	}
};

void VariadicTemplateTest::TestVariadicTemplate()
{
	std::cout << "Variadic Template Test\n";

	const auto vec = to_string("Hello", 1, 5.3, "World", 1.3, true);

	for (const auto &o : vec)
	{
		std::cout << o << "\n";
	}

	const FTestClass1 TestClass1 = FTestClass1();
	const FTestClass2 TestClass2 = FTestClass2();

	const auto vec2 = to_string_mytypes(TestClass1, TestClass2);

	for (const auto &o : vec2)
	{
		std::cout << o << "\n";
	}
}
