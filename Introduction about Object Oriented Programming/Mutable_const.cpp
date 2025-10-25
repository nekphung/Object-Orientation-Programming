#include <iostream>
using namespace std;

class Logger {
	int data;
	mutable int accessCount; // cho phep thay doi ngay ca trong ham const 
public: 
	Logger(int d) : data(d), accessCount(0) {}
	
	int getData() const {
		accessCount++; // duoc phep vi accessCount la mutable 
		return data;
	}

	int getAccessCount() const {
		return accessCount; // const method 
	}
};

int main() {
	const Logger log(100);

	cout << log.getData() << endl; // Lan 1: accessCount = 1;
	cout << log.getData() << endl; // Lan 2: accessCount = 2;
	cout << "Access Count: " << log.getAccessCount() << endl; 
	return 0;
}