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
	int balance;
public:
	BankAccount(): balance(0) {}
	BankAccount(string, string, string, string, int);
};

BankAccount::BankAccount(string id, string cusID, string number, string pin, int balance) {
	this->id = id;
	this->cusID = cusID;
	this->number = number;
	this->pin = pin;
	this->balance = balance;
}

int main() {
	int n; cin >> n;
	cin.ignore();
	vector<BankAccount> list;
	for (int i = 0; i < n; i++)
	{

	}
	return 0;
}