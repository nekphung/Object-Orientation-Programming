#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Author {
private: 
	string name;
	string email;
	char gender;
public: 
	Author(string, string, char);
	string getName();
	string getEmail();
	void setEmail(string);
	char getGender();
	string toString();
};


class Book {
private:
	string name;
	Author* author;
	double price;
	int qty = 0;
public:
	Book(string, Author*, double);
	Book(string, Author*, double, int);
	string getName();
	Author* getAuthor();
	double getPrice();
	void setPrice(double);
	int getQty();
	void setQty(int);
	string toString();
	void printInformation();
};

Author::Author(string name, string email, char gender) {
	this->name = name;
	this->email = email;
	this->gender = gender;
}
string Author::getName() {
	return name;
}
string Author::getEmail() {
	return email;
}
void Author::setEmail(string email) {
	this->email = email;
}
char Author::getGender() {
	return gender;
}
string Author::toString() {
	return "";
}

Book::Book(string name, Author* author, double price) {
	this->name = name;
	this->author = author;
	this->price = price;
}
Book::Book(string name, Author* author, double price, int qty) {
	this->name = name;
	this->author = author;
	this->price = price;
	this->qty = qty;
}

string Book::getName() {
	return name;
}
Author* Book::getAuthor() {
	return author;
}
double Book::getPrice() {
	return price;
}
void Book::setPrice(double price) {
	this->price = price;
}
int Book::getQty() {
	return qty;
}
void Book::setQty(int qty) {
	this->qty = qty;
}
string Book::toString() {
	
	return "";
}
void Book::printInformation()
{
	cout << "Book Details : " << endl;
	cout << name << endl;
	cout << price << endl;
	cout << qty << endl;
	cout << "Author Information : " << endl;
	cout << author->getName() << endl;
	cout << author->getEmail() << endl;
	cout << author->getGender() << endl;
	cout << "--------------------" << endl;
}

bool cmp(Book& a, Book& b) 
{
	if (a.getPrice() != b.getPrice()) {
		return a.getPrice() > b.getPrice();
	}
	else
		return a.getName() < b.getName();
}

int main() {
	int n; cin >> n; // so luong cuon sach
	cin.ignore();
	vector<Book> listBook;
	vector<Author> listAuthor;
	for (int i = 0; i < n; i++) {
		string nameBook, nameAuthor, email;
		char gender; 
		double price; 
		int qty;

		getline(cin, nameBook);
		cin >> price >> qty;
		cin.ignore();
		getline(cin, nameAuthor);
		getline(cin, email);
		cin >> gender;
		cin.ignore();

		listAuthor.push_back(Author(nameAuthor, email, gender)); // tao o ngoai roi moi dua vao trong process 
		Author* author = &listAuthor.back(); // lay dia chi thang cuoi cung
		listBook.push_back(Book(nameBook, author, price, qty));
	}
	sort(listBook.begin(), listBook.end(), cmp);
	for (int i = 0; i < n; i++) {
		listBook[i].printInformation();
	}

	return 0;
}