//
//  LamdaTest.cpp
//  CodeTests
//
//  Created by NickDavies on 09/01/2017.
//  Copyright © 2017 NickDavies. All rights reserved.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <functional>
#include "LambdaTest.h"

using namespace std;

void run_within_for_each(std::function<void (int)> func)
{
    vector<int> numbers{ 1, 2, 3, 4, 5, 10, 15, 20, 25, 35, 45, 50 };
 
//    for_each(numbers.begin(), numbers.end(), func);
}

std::function<bool(int)> create_function()
{
	return [](int x)
	{
		return (x < 100);
	};
};

class TestClass{
public:
	void SetTrue(bool bNewValue)
	{
		Visible = bNewValue;
	}

	bool GetVisibility()
	{
		return Visible;
	}

	private:
	bool Visible{true};
};


void LambdaTest::TestLambdas()
{

	// Simple lambda. Takes nothing, and just prints withing the function.
	cout << "LambdaTest\n";
	auto lambda = []() { cout << "Code within a lambda expression" << endl; };
	lambda();

///////

	// Lambda that takes 2 ints, and returns a value
	auto sum = [](int x, int y) { return x + y; };
	cout << sum(5, 2) << endl;
	cout << sum(10, 5) << endl;

///////

	vector<int> numbers { 1, 2, 3, 4, 5, 10, 15, 20, 25, 35, 45, 50 };

//////

	// lambda used in count_if function. Takes int from iterator
/*	auto greater_than_5_count = count_if(numbers.begin(), numbers.end(), [](int x) { return (x > 5); });
	cout << "The number of elements greater than 5 is: "
		<< greater_than_5_count << "." << endl;
		*/
//////

/*	// for_each that takes a simple lambda that just returns the value passed in
	cout << "for_each that takes a simple lambda that just returns the value passed in: ";
	for_each(numbers.begin(), numbers.end(), [] (int y)
	{
		cout << y << endl;
	});
	*/
///////

	int divisor = 3;
//////
	// Lambda that captures divisor
/*	for_each(numbers.begin(), numbers.end(), [divisor] (int y)
	{
		if (y % divisor == 0)
		{
			cout << y << endl;
		}
	});*/

/////

	// lambda that captures all vars by value
/*	for_each(numbers.begin(), numbers.end(), [=] (int y)
	{
		if (y % divisor == 0)
    	{
        	cout << y << endl;
    	}
	});*/

/////

	// lamda that captures divisor, and ref to NewSum.
	int NewSum = 0;
/*	for_each(numbers.begin(), numbers.end(), [divisor, &NewSum] (int y)
	{
		if (y % divisor == 0)
		{
			cout << y << endl;
			NewSum += y;
		}
	});*/
 
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

 	// passing lambda
	run_within_for_each(func1);
    run_within_for_each(func2);

	auto TestClassInst = TestClass();

	auto VisibilityLambda = [](bool Visibility){ Visibility ? cout << "Visible\n" : cout << "Hidden\n";};

	VisibilityLambda(TestClassInst.GetVisibility());

	TestClassInst.SetTrue(false);

	VisibilityLambda(TestClassInst.GetVisibility());

//////////

	// creating a lamda from a function

	run_within_for_each(create_function());

}
