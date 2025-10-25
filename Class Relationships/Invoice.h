#pragma once
#include <iostream>
#include <iostream>
#include <vector>
#include "Customer.h"

using namespace std;

class Invoice {
private:
	int id;
	Customer customer;
	double amount;
public:
	Invoice(int id, Customer customer, double amount);
	int getID();
	Customer getCustomer();
	void setCustomer(Customer customer);
	double getAmount();
	void setAmount(double amount);
	int getCustomerID();
	string getCustomerName();
	int getCustomerDiscount();
	double getAmountAfterDiscount();
	string toString();
};