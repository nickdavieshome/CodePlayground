//
//  main.cpp
//  CodeTests
//
//  Created by NickDavies on 27/12/2016.
//  Copyright © 2016 NickDavies. All rights reserved.
//

#include <iostream>
#include "Widget.hpp"

int main(int argc, const char * argv[]) {
	// insert code here...
	std::cout << "Hello, World test!\n";
	Widget{10, true};
	Widget W2({});
	std::cout << "Completed!\n";

    return 0;
}
