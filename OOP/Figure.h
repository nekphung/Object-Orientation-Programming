#pragma once
#include <iostream>
using namespace std;

class Figure {
public: 
	virtual void Input(istream& inDev);
	virtual float Area();
};