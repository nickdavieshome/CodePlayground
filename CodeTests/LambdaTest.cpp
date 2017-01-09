//
//  LamdaTest.cpp
//  CodeTests
//
//  Created by NickDavies on 09/01/2017.
//  Copyright © 2017 NickDavies. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <functional>
#include "LambdaTest.h"

using namespace std;

void run_within_for_each(std::function<void (int)> func)
{
    vector<int> numbers{ 1, 2, 3, 4, 5, 10, 15, 20, 25, 35, 45, 50 };
 
    for_each(numbers.begin(), numbers.end(), func);
}

std::function<bool(int)> create_function()
{
	return [](int x)
	{
		return (x < 100);
	};
};

void LambdaTest::TestLambdas()
{
	cout << "LambdaTest\n";
	auto lambda = []() { cout << "Code within a lambda expression" << endl; };
	lambda();

///////

	auto sum = [](int x, int y) { return x + y; };
	cout << sum(5, 2) << endl;
	cout << sum(10, 5) << endl;

///////

	vector<int> numbers { 1, 2, 3, 4, 5, 10, 15, 20, 25, 35, 45, 50 };

//////

	auto greater_than_5_count = count_if(numbers.begin(), numbers.end(), [](int x) { return (x > 5); });
	cout << "The number of elements greater than 5 is: "
		<< greater_than_5_count << "." << endl;

//////

	for_each(numbers.begin(), numbers.end(), [] (int y)
	{
		cout << y << endl;
	});

///////

	int divisor = 3;
//////
	for_each(numbers.begin(), numbers.end(), [divisor] (int y)
	{
		if (y % divisor == 0)
		{
			cout << y << endl;
		}
	});

/////

	for_each(numbers.begin(), numbers.end(), [=] (int y)
	{
		if (y % divisor == 0)
    	{
        	cout << y << endl;
    	}
	});

/////

	int NewSum = 0;
	for_each(numbers.begin(), numbers.end(), [divisor, &NewSum] (int y)
	{
		if (y % divisor == 0)
		{
			cout << y << endl;
			NewSum += y;
		}
	});
 
	cout << NewSum << endl;

////////

	auto func1 = [](int y)
	{
		cout << y << endl;
	};
 
	auto func2 = [](int z)
	{
		cout << z * 2 << endl;
	};
 
	run_within_for_each(func1);
    run_within_for_each(func2);

//////////

	run_within_for_each(create_function());

}
