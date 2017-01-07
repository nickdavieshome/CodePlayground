//
//  main.cpp
//  CodeTests
//
//  Created by NickDavies on 27/12/2016.
//  Copyright © 2016 NickDavies. All rights reserved.
//

#include <iostream>
#include "Widget.hpp"
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


int main(int argc, const char * argv[]) {
	// insert code here...
	std::cout << "Hello, World test!\n";
	Widget{10, true};
	Widget W2({});
	std::cout << "Completed!\n";


	// Variadic Template example
	// Pass in any intrinsic type

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


    return 0;
}
