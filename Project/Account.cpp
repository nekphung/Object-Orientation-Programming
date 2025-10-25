#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Account {
private:
	string id;
	string customerID;
	string userName;
	string passWord;
public: 
	Account() {}
	Account(string id, string customerID, string userName, string passWord) {
		this->id = id;
		this->customerID = customerID;
		this->userName = userName;
		this->passWord = passWord;
	}
	string getUserName() {
		return userName;
	}
	string getPassWord() {
		return passWord;
	}
};



int main() {
	int n; cin >> n;
	cin.ignore();
	Account* list = new Account[n];
	for (int i = 0; i < n; i++) {
		string id, customerID, userName, passWord;
		getline(cin, id);
		getline(cin, customerID);
		getline(cin, userName);
		getline(cin, passWord);
		list[i] = Account(id, customerID, userName, passWord);
	}
	int q;  cin >> q;
	cin.ignore();
	for (int i = 0; i < q; i++) {
		string userName, passWord;
		getline(cin, userName);
		getline(cin, passWord);
		bool check = false;
		for (int i = 0; i < n; i++) {
			if (list[i].getUserName() == userName && list[i].getPassWord() == passWord) {
				check = true;
			}
		}
		if (check) cout << "Login Successful" << endl;
		else cout << "Login Failed" << endl;
	}
	delete[] list;
	return 0;
}