#include "Customer.h"

Customer::Customer(int id, string name, int discount) {
	this->id = id;
	this->name = name;
	this->discount = discount;
}

int Customer::getID() {
	return id;
}

string Customer::getName() {
	return name;
}

int Customer::getDiscount() {
	return discount;
}

void Customer::setDiscount(int discount) {
	this->discount = discount;
}

string Customer::toString() {
	return "";
}

