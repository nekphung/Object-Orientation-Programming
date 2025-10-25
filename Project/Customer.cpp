#include <iostream>
#include <string>

using namespace std;

class Customer {
private:
	string maKhachHang;
	string hoTen;
	string diaChi;
	string phone;
	string email;
public: 
	Customer() {} // default constructor
	Customer(string, string, string, string, string);
	void printInformation();
};

Customer::Customer(string maKhachHang, string hoTen, string diaChi, string phone, string email) {
	this->maKhachHang = maKhachHang;
	this->hoTen = hoTen;
	this->diaChi = diaChi;
	this->phone = phone;
	this->email = email;
}

void Customer::printInformation() {
	cout << maKhachHang << " " << hoTen << " " << diaChi << " " << phone << " " << email;
}

int main() {
	string maKhachHang, hoTen, diaChi, phone, email;
	getline(cin, maKhachHang);
	getline(cin, hoTen);
	getline(cin, diaChi);
	getline(cin, phone);
	getline(cin, email);
	Customer customer(maKhachHang, hoTen, diaChi, phone, email);
	customer.printInformation();
	return 0;
}