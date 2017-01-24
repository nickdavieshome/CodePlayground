//
//  QuickCheckAlgorithm.cpp
//  CodeTests
//
//  Created by NickDavies on 24/01/2017.
//  Copyright © 2017 NickDavies. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "QuickCheckAlgorithm.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

void QuickInsertCheck::QuickInsertExample()
{
	vector<int> numbers{ 7, 2, 5, 4, 1, 9, 3, 6};

	map<int, int> InsertMap;

	int MatchNumber = 10;
	cout << "Test Quick Insert Algorithm \n";
	int Index = 1;
	for(const auto number : numbers)
	{
		if(InsertMap[MatchNumber - number])
		{
			cout << "Match Found " << number << " " << MatchNumber - number;
			cout << " Indexes " << Index << " " << InsertMap[MatchNumber - number] << "\n";
		}
		InsertMap[number] = Index;
		Index++;
	}
}
