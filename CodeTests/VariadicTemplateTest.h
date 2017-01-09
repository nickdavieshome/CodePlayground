//
//  VariadicTemplateTest.h
//  CodeTests
//
//  Created by NickDavies on 06/01/2017.
//  Copyright © 2017 NickDavies. All rights reserved.
//

#include <sstream>
#include <iostream>
#include <vector>

#ifndef VariadicTemplateTest_h
#define VariadicTemplateTest_h

template<typename T>
std::string to_string_impl(const T& t)
{
	std::stringstream ss;
	ss << t;
	return ss.str();
}

template<typename ... Param>
std::vector<std::string> to_string(const Param& ... param)
{
	return {to_string_impl(param)...};
}


template<typename T>
std::string to_string_mytypes_impl(const T& t)
{
	return t.ToString();
}

template<typename ... Param>
std::vector<std::string> to_string_mytypes(const Param& ... param)
{
	return {to_string_mytypes_impl(param)...};
}

class VariadicTemplateTest
{
public:
	static void TestVariadicTemplate();
};

#endif /* VariadicTemplateTest_h */
