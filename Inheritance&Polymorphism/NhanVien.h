#pragma once
#include <iostream>
#include <string>
#include <cstring>
using namespace std; 

class NhanVien {
protected: 
	string Ma; 
	string HoTen, DiaChi; 
	int Luong; 
public: 
	void Nhap(); 
	long long TinhLuong(); 
};