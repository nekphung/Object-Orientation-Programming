#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Employee {
protected: 
	string ma; 
	string ten; 
	string diaChi; 
	int luong; 
public: 

	void InputFromKeyBoard() {
		getline(cin, ma);
		getline(cin, ten);
		getline(cin, diaChi);
		luong = 0; 
	}

	string toString() {
		return ma + " " + ten + " " + diaChi + to_string(luong); 
	}
};

class NVSanXuat : public Employee {
private: 
	int soLuongSP;
public: 
	void InputFromKeyBoard() {
		Employee::InputFromKeyBoard(); 
		cin >> soLuongSP;
	}

	void TinhLuong() {
		luong = soLuongSP * 1000;
	}
	string toString() {
		TinhLuong();
		return ma + " " + ten + " " + diaChi + " " + to_string(luong);
	}
};


class NVCongNhat : public Employee {
private: 
	int soNgayDiLam;
public: 
	void TinhLuong() {
		luong = soNgayDiLam * 300000;
	}

	void InputFromKeyBoard() {
		Employee::InputFromKeyBoard();
		cin >> soNgayDiLam;
	}

	string toString() {
		TinhLuong();
		return ma + " " + ten + " " + diaChi + " " + to_string(luong);
	}
};

int main() {
	NVSanXuat n1;
	n1.InputFromKeyBoard();
	cout << n1.toString() << endl; 
	NVCongNhat n2;
	n2.InputFromKeyBoard();
	cout << n2.toString() << endl;
	Employee n3;
	n3.InputFromKeyBoard();
	cout << n3.toString() << endl; 
	return 0;
}