#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BankAccount {
private:
	string id;
	string cusID;
	string number;
	string pin;
	long long balance;
public:
	BankAccount() : balance(0) {}
	BankAccount(string, string, string, string, long long);
	void printInformation();
	void setBalance(long long);
	string getNumber();
	long long getBalance();
};

BankAccount::BankAccount(string id, string cusID, string number, string pin, long long balance) {
	this->id = id;
	this->cusID = cusID;
	this->number = number;
	this->pin = pin;
	this->balance = balance;
}

void BankAccount::setBalance(long long money) {
	balance = money;
}

string BankAccount::getNumber() {
	return number;
}

long long BankAccount::getBalance() {
	return balance;
}

void BankAccount::printInformation() {
	cout << "ID : " << id << endl;
	cout << "CusID : " << cusID << endl;
	cout << "Number : " << number << endl;
	cout << "PIN : " << pin << endl;
	cout << "Balance : " << balance << "VND" << endl;
	cout << "-------------------" << endl;
}

int main() {
	int n; cin >> n;
	//cin.ignore();
	vector<BankAccount> list;
	for (int i = 0; i < n; i++)
	{
		string id, cusID, number, pin;
		long long balance;
		cin >> id >> cusID >> number >> pin >> balance;
		BankAccount bankAccount(id, cusID, number, pin, balance);
		list.push_back(bankAccount);
	}
	int t; cin >> t;
	//cin.ignore();
	for (int i = 0; i < t; i++) {
		string mode;
		cin >> mode;
		if (mode == "deposit") { // nap tien 
			string x; int y; cin >> x >> y;
			for (int j = 0; j < n; j++) {
				if (x == list[j].getNumber()) {
					list[j].setBalance(list[j].getBalance() + y);
					break;
				}
			}
		}
		else if (mode == "withdraw") { // rut tien
			string x; long long y; cin >> x >> y;
			for (int j = 0; j < n; j++) {
				if (x == list[j].getNumber()) {
					if (y <= list[j].getBalance() && (list[j].getBalance() - y) >= 50000) {
						list[j].setBalance(list[j].getBalance() - y);
						break;
					}
				}
			}
		}
		else { // chuyen tien 
			string x, y; long long z;
			cin >> x >> y >> z;
			int index1 = -1, index2 = -1;
			for (int j = 0; j < n; j++) {

				if (x == list[j].getNumber())   index1 = j;
				if (y == list[j].getNumber())   index2 = j;
			}
			if (index1 != -1 && index2 != -1) {
				if (z <= list[index1].getBalance() && (list[index1].getBalance() - z) >= 50000) {
					list[index1].setBalance(list[index1].getBalance() - z);
					list[index2].setBalance(list[index2].getBalance() + z);
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		list[i].printInformation();
	}
	return 0;
}