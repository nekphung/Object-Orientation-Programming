#include "Person.h"

Person::Person() {
	name = new char[1];
	name[0] = '\0';
	birthDay = new char[1];
	birthDay[0] = '\0';
	address = new char[1];
	address[0] = '\0';
}


void Person::chuanHoaTen() {
	// tach ten ra thanh cac token 
	for (int i = 0; i < strlen(name); i++) {
		if (isupper(name[i])) {
			name[i] = char(name[i] + 32); // de chuyen thanh chu thuong 
		}
	}
	size_t length = strlen(name);
	char* temp = nullptr; 
	const char* delimiters = " "; // dau cach 
	char* token = strtok_s(name, delimiters, &temp);
	// lay ra token dau tien
	// tao ra mot xau de luu ten sau khi chuan hoa 
	char* newStr = new char[length + 50]; 
	int cnt = 0; 
	while (token != nullptr) {
		size_t len = strlen(token); 
		if (len > 0) {
			newStr[cnt++] = char(token[0] - 32);
			for (int i = 1; i < strlen(token); i++) {
				newStr[cnt++] = token[i];
			}
		}
		// lay token tiep theo 
		char* next = strtok_s(nullptr, delimiters, &temp);
		if (next != nullptr) {
			newStr[cnt++] = ' ';
		}
		token = next; // gan lai 
	}
	newStr[cnt] = '\0'; // ket thuc chuoi 
	delete[] name;  // xoa bo nho cu 
	name = new char[strlen(newStr) + 1];
	strcpy(name, newStr); 
	delete[] newStr; 
}

void Person::chuanHoaNgaySinh() {
	// tach ra lam 3 phan 
	char* temp = nullptr; 
	const char* delimiters = "/"; 
	char* token = strtok_s(birthDay, delimiters, &temp);
	char* result = new char[11];
	int cnt = 0; 
	

}


Person::Person(const char* ten, const char* ns, const char* diaChi) {
	name = new char[strlen(ten) + 1];
	birthDay = new char[strlen(ns) + 1];
	address = new char[strlen(diaChi) + 1];
	strcpy(name, ten);
	strcpy(birthDay, ns);
	strcpy(address, diaChi);
}

char* Person::toString() {
	chuanHoaTen(); 
	size_t size = strlen(name) + strlen(birthDay) + strlen(address) + 50;
	char* res = new char[size];
	sprintf(res, "%s %s %s", name, birthDay, address); 
	return res; 
}

Person& Person::operator=(const Person& other) {
	if (this != &other) {
		delete[] name; 
		delete[] birthDay; 
		delete[] address;
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
		birthDay = new char[strlen(other.birthDay) + 1];
		strcpy(birthDay, other.birthDay);
		address = new char[strlen(other.address) + 1];
		strcpy(address, other.address); 
	}
	return *this; 
}

Person::~Person() {
	delete[] name;
	name = nullptr; 
	delete[] birthDay; 
	birthDay = nullptr; 
	delete[] address;
	address = nullptr; 
}