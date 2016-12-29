//
//  Widget.hpp
//  CodeTests
//
//  Created by NickDavies on 27/12/2016.
//  Copyright © 2016 NickDavies. All rights reserved.
//

#ifndef Widget_hpp
#define Widget_hpp

#include <stdio.h>
#include <initializer_list>

class Widget {
public:
  Widget(int i, bool b);                           // as before
  Widget(int i, double d);                         // as before
  Widget(std::initializer_list<long double> il);   // as before

//  operator float() const;                          // convert
};

#endif /* Widget_hpp */
