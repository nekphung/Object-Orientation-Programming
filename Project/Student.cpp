#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class Student {
private:
	string maSinhVien;
	string hoTen;
	string ngaySinh;
	string lop;
	double gpa;
	int DiemRenLuyen; // behavior 
public: 
	Student(): gpa(0) {}
	Student(string, string, string, string, double, int);
	void chuanHoaTen();
	void chuanHoaNgaySinh();
	string getLop();
	double getGpa();
	string getMa();
	string getNgaySinh();
	string getSortedName();
	int getDiemRenLuyen();
	bool checkDob(string);
	void printInformation();
};

Student::Student(string maSinhVien, string hoTen, string ngaySinh, string lop, double gpa, int DiemRenLuyen) {
	this->maSinhVien = maSinhVien;
	this->hoTen = hoTen;
	this->ngaySinh = ngaySinh;
	this->lop = lop;
	this->gpa = gpa;
	this->DiemRenLuyen = DiemRenLuyen;
}

void Student::chuanHoaTen()
{
	string hoTen = this->hoTen;
	string word = "";
	vector<string> v;
	stringstream ss(hoTen);
	while (ss >> word) {
		v.push_back(word);
	}
	for (string &x : v) {
		for (int i = 0; i < x.size(); i++) {
			if (i == 0) {
				if (islower(x[i]))  x[i] = toupper(x[i]);
			}
			else {
				if (isupper(x[i]))  x[i] = tolower(x[i]);
			}
		}
	}
	string temp = "";
	for (int i = 0; i < v.size(); i++) {
		if (i != v.size() - 1) {
			temp += v[i] + " ";
		}
		else {
			temp += v[i];
		}
	}
	this->hoTen = temp;
}

void Student::chuanHoaNgaySinh() 
{
	string ngaySinh = this->ngaySinh;
	vector<string> v;
	string word = "";
	stringstream ss(ngaySinh);
	while (getline(ss, word, '/')) {
		v.push_back(word);
	}
	string temp = "";
	for (int i = 0; i < v.size() - 1; i++) {
		if (v[i].size() == 1) {
			temp += "0" + v[i] + "/";
		}
		else temp += v[i] + "/";
	}
	temp += v[2];
	this->ngaySinh = temp;
}

string Student::getLop() {
	return lop;
}

double Student::getGpa() {
	return gpa;
}

string Student::getNgaySinh() {
	return ngaySinh;
}

string Student::getMa() {
	return maSinhVien;
}

bool Student::checkDob(string date)
{
	string day = date.substr(0, 2);
	date.erase(0, 3);
	string month = date.substr(0, 2);
	date.erase(0, 3);
	string year = date.substr(0);
	chuanHoaNgaySinh();
	string ngaySinh = this->ngaySinh;
	vector<string> v;
	string word = "";
	stringstream ss(ngaySinh);
	while (getline(ss, word, '/')) {
		v.push_back(word);
	}
	string thisDay = v[0], thisMonth = v[1], thisYear = v[2];
	if (thisYear < year) return true;
	else if (thisYear == year && thisMonth < month) return true;
	else if (thisYear == year && thisMonth == month && thisDay < day) return true;
	else return false;
}

void Student::printInformation() {
	cout << maSinhVien << " " << hoTen << " " << ngaySinh << " " << lop << " ";
	printf("%.2f ", gpa);
	cout << DiemRenLuyen;
}

string Student::getSortedName() {
	return hoTen;
}

int Student::getDiemRenLuyen() {
	return DiemRenLuyen;
}

bool cmp1(Student a, Student b) {
	if (a.getGpa() != b.getGpa()) {
		return a.getGpa() > b.getGpa();
	}
	else {
		return a.getMa() < b.getMa();
	}
}

bool cmp2(Student a, Student b) {
	// neu bang nhau thi xep theo ma sinh vien tang dan
    // Nguoc lai thi xep theo gia toi tre 
	a.chuanHoaNgaySinh(), b.chuanHoaNgaySinh();
	if (a.getNgaySinh() == b.getNgaySinh()) {
		return a.getMa() < b.getMa();
	}
	else {
		string ngaySinhA = a.getNgaySinh(), ngaySinhB = b.getNgaySinh();
		int dayA = stoi(ngaySinhA.substr(0, 2));
		int monthA = stoi(ngaySinhA.substr(3, 2));
		int yearA = stoi(ngaySinhA.substr(6));

		int dayB = stoi(ngaySinhB.substr(0, 2));
		int monthB = stoi(ngaySinhB.substr(3, 2));
		int yearB = stoi(ngaySinhB.substr(6));

		if (yearA != yearB) return yearA < yearB;
		if (monthA != monthB) return monthA < monthB;
		return dayA < dayB;
	}
}

bool cmp3(Student a, Student b) {
	// Neu khac lop thi sap xep theo lop tang dan ve thu tu tu dien 
	if (a.getLop() != b.getLop()) {
		return a.getLop() < b.getLop();
	}
	else {
		// sap xep ten truoc sau do moi toi ho va dem sau 
		a.chuanHoaTen(), b.chuanHoaTen();
	    // tach ra cac thanh phan cua ten trong 2 Student 
		vector<string> v1, v2;
		stringstream ss1(a.getSortedName());
		string word1;
		while (ss1 >> word1) v1.push_back(word1);
		stringstream ss(b.getSortedName());
		string word;
		while (ss >> word) v2.push_back(word);
		if (v1[v1.size() - 1] != v2[v2.size() - 1]) {
			return v1[v1.size() - 1] < v2[v2.size() - 1];
		}
		else {
			int n = v1.size() < v2.size() ? v1.size() - 1 : v2.size() - 1; // toan tu 3 ngoi 
			for (int i = 0; i < n; i++) {
				if (v1[i] < v2[i]) return true;
				if (v1[i] > v2[i]) return false;
				// Neu no bang nhau thi tiep tuc so sanh 
			}
		} 

		// Neu nhu nhung phan tren deu giong nhau 
		if (v1.size() != v2.size()) return v1.size() < v2.size();
	}
	// Nguoc lai, sap xep theo ten roi toi ho va dem 
}

bool cmp4(Student a, Student b) {
	// so sanh diem gpa truoc sau do moi toi drl 
	if (a.getGpa() != b.getGpa()) return a.getGpa() > b.getGpa();
	else {
		return a.getDiemRenLuyen() > b.getDiemRenLuyen();
	}
}

int main() {
	int n;
	cin >> n;
	Student* listStudent = new Student[n];
	for (int i = 0; i < n; i++) {
		string maSinhVien, hoTen, ngaySinh, lop;
		double gpa; int diemRenLuyen;
		cin.ignore();
		getline(cin, maSinhVien);
		getline(cin, hoTen);
		getline(cin, ngaySinh);
		getline(cin, lop);
		cin >> gpa; cin >> diemRenLuyen;
		listStudent[i] = Student(maSinhVien, hoTen, ngaySinh, lop, gpa, diemRenLuyen);
	}
	sort(listStudent, listStudent + n, cmp4);
	for (int i = 0; i < n; i++) {
		listStudent[i].chuanHoaNgaySinh();
		listStudent[i].chuanHoaTen();
		listStudent[i].printInformation();
		cout << endl;
	}
	delete[] listStudent;
	return 0;
}