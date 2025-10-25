/*
Hủy bỏ
Nạp chồng toán tử nhập >>
Nạp chồng toán tử xuất <<
Nạp chồng toán tử so sánh > (một vận động viên là lớn hơn nếu chiều cao lớn hơn,
	trong trường hợp chiều cao bằng nhau thì xét cân nặng lớn hơn)
	Xây dựng chương trình chính :

Khai báo p là đối tượng lớp Vandongvien(sử dụng hàm thiết lập 5 tham số), hiển thị thông tin của p ra màn hình.
Nhập vào một mảng gồm n vận động viên.
Hiển thị danh sách đã nhập ra màn hình.
Sắp xếp mảng đã nhập theo thứ tự tăng dần, hiển thị danh sách đã sắp ra màn hình.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class VanDongVien {
//private: 
protected:
	string hoten;
	int tuoi;
	string monthidau;
	float cannang, chieucao;
public: 
	// Khong tham so 
	VanDongVien() {
		this->hoten = this->monthidau = "";
		this->tuoi = 0;
		this->cannang = this->chieucao = 0;
	}

	// 5 tham so truyen vao constructor 
	VanDongVien(string hoten, string monthidau, int tuoi, float cannang, float chieucao) {
		this->hoten = hoten;
		this->tuoi = tuoi;
		this->monthidau = monthidau;
		this->cannang = cannang;
		this->chieucao = chieucao;
	}

	// Huy bo 
	~VanDongVien() {
		this->hoten = this->monthidau = "";
		this->tuoi = 0;
		this->cannang = this->chieucao = 0;
	}

	//----------------------------------------------//
	// Nhap du lieu tu inDev
	friend istream& operator >> (istream& inDev, VanDongVien& obj) {
		cin.ignore(); // bo qua ky tu xuong dong khi nhap cin 
		cout << "Nhap Ho Ten: "; getline(inDev, obj.hoten);
		cout << "Nhap Mon Thi Dau: "; getline(inDev, obj.monthidau);
		cout << "Nhap Tuoi: "; inDev >> obj.tuoi;
		cout << "Nhap Can Nang: "; inDev >> obj.cannang;
		cout << "Nhap Chieu Cao: "; inDev >> obj.chieucao;
		return inDev;
	}

	// Xuat du lieu ra inDev
	friend ostream& operator << (ostream& onDev, VanDongVien obj) {
		onDev << "Ho Ten: " << obj.hoten << endl;
		onDev << "Mon Thi Dau: " << obj.monthidau << endl;
		onDev << "Tuoi: " << obj.tuoi << endl;
		onDev << "Can Nang: " << obj.cannang << endl;
		onDev << "Chieu Cao: " << obj.chieucao << endl;
		return onDev;
	}

	bool operator > (const VanDongVien& obj) {
		if (this->chieucao > obj.chieucao) return true;
		else if (this->chieucao < obj.chieucao) return false;
		else if (this->cannang > obj.cannang)  return true;
		else
			return false;
	}
};

void swap(VanDongVien& a, VanDongVien& b) {
	VanDongVien temp = a;
	a = b;
	b = temp;
}

void BubbleSort(VanDongVien arr[], int n) 
{
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) { // phai nap chong toan tu > 
				swap(arr[j], arr[j + 1]); // hoan vi 2 VanDongVien
			}
		}
	}
}


int main() {
	VanDongVien p("Nguyen Van A", "Bong Da", 20, 178, 70.5);
	cout << p;

	cout << "Nhap so luong: "; int n; cin >> n;
	VanDongVien* arr = new VanDongVien[n];
	for (int i = 0; i < n; i++) cin >> arr[i]; // neu nhap thi phai xoa ky tu xuong dong
	
	cout << endl << endl;

	for (int i = 0; i < n; i++) cout << arr[i] << endl;
	 
	cout << "Sort: " << endl;
	BubbleSort(arr, n);
	for (int i = 0; i < n; i++) cout << arr[i] << endl;

	return 0;
}