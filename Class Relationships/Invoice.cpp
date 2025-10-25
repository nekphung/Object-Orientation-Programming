#include "Customer.h"
#include "Invoice.h"

Invoice::Invoice(int id, Customer customer, double amount) 
{
	this->id = id;
	this->customer = customer;
	this->amount = amount;
}

int Invoice::getID() {
	return id;
}

Customer Invoice::getCustomer() {
	return customer;
}

void Invoice::setCustomer(Customer customer) {
	this->customer = customer;
}

double Invoice::getAmount() {
	return amount;
}

void Invoice::setAmount(double amount) {
	this->amount = amount;
}

int Invoice::getCustomerID() {
	return customer.getID();
}

string Invoice::getCustomerName() {
	return customer.getName();
}

int Invoice::getCustomerDiscount() {
	return customer.getDiscount();
}

double Invoice::getAmountAfterDiscount() {
	return 0;
}

string Invoice::toString() {
	return "";
}