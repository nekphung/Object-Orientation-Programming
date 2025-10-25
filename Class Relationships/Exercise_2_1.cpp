#include <iostream>
#include <string.h>
#include <stdio.h>
#include <conio.h> // thu vien nay de lam gi 

using namespace std;

// May tinh: toc do, dung luong RAM, dung luong HDD --> void input(), output() 
// | --> quan he ke thua 
// May: nhan hieu, nha san xuat, gia thanh --> input, output 
// | --> quan he thu nhap 
// Nha san xuat: private ten NSX, dia chi 

// Yeu cau: nhap vao n may tinh, in ra thong tin cac may tinh cua nha san xuat IBM
// Sap xep danh sach cac may tinh theo chieu tang dan cua gia thanh va in danh sach da sap ra man hinh.
// Xoa moi may tinh cua hang Intel san xuat va in ra danh sach ket qua ra man hinh

class NhaSX {
	char TenNSX[30];
	char DC[30];

};

class May {
private: 
	char NH[30];
	NhaSX NSX;
	float GT;
public: 
	void input();
	void output();
};

class MayTinh : public May {
	float TD;
	int DLR;
	int DLHDD;
public: 
	void input();
	void output();
};

void May::input() {

}

void May::output() {

}

void MayTinh::input() {

}

void MayTinh::output() {


}

void In(MayTinh a[100], int n)  {

}

void SapXep(MayTinh a[100], int n)  {


}

void Xoa(MayTinh a[100], int& n) {


}

int main() {


	return 0;
}