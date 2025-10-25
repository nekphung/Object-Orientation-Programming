#include <iostream>
using namespace std;

class Box {
private:
	int width;
public: 
	Box(int w) : width(w){}
	friend void printWidth(const Box& b); // no khong phai la mot phuong thuc cua Box ma chi la mot ham o ngoai, muon su dung cac behaviour cua Box trong private  
};

void printWidth(const Box& b) // Neu no la member function thi phai la Box::printWidth(const Box& b) 
{ 
	cout << "Width: " << b.width << endl;
}

class Engine {
private: 
	int power;
public: 
	Engine(int p) : power(p) {}

	friend class Car; // class Car is not a method of Engine 
};

//Reason: class Car want to use these behaviour of class Engine
class Car {
public:
	void showEnginePower(const Engine& e) {
		cout << "Engine power: " << e.power << " HP" << endl;
	}
};

int main() {
	Box b(10);
	printWidth(b);
	Engine e(159);
	Car c; // tu tao va tu xoa trong stack 
	c.showEnginePower(e);
	return 0;
}