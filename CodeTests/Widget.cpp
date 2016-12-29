//
//  Widget.cpp
//  CodeTests
//
//  Created by NickDavies on 27/12/2016.
//  Copyright © 2016 NickDavies. All rights reserved.
//

#include "Widget.hpp"
#include <iostream>


Widget::Widget(int i, bool b)
{
	std::cout << "Contructor 1!\n";
}
                           // as before
Widget::Widget(int i, double d)
{
	std::cout << "Contructor 2!\n";
}

Widget::Widget(std::initializer_list<long double> il)
{
	std::cout << "Contructor 3!\n";
}
