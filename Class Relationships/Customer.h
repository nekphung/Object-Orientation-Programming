#pragma once
#include <iostream>
#include <iostream>
#include <vector>
using namespace std;

class Customer {
private:
	int id;
	string name;
	int discount;
public:
	Customer(int id, string name, int discount);
	int getID();
	string getName();
	int getDiscount();
	void setDiscount(int discount);
	string toString();
};