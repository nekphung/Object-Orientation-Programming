#include <iostream>
using namespace std;

class Fish
{
public: 
	// neu khong co virtual thi no se chi goi ham cha ma khong goi dung ham con
	virtual void Swim() {
		cout << "Fish swims!" << endl;
	}
};

class Tuna:public Fish
{
public: 
	void Swim() {
		cout << "Tuna swims!" << endl;
	}
};

class Carp :public Fish
{
public: 
	// override Fish::Swim(), variant: bien the
	void Swim() {
		cout << "Carp swims!" << endl;
	}
};

void MakeFishSwim(Fish& InputFish) // Co the nhan biet bat ky loai ca nao ma khong can phai tao tung ham rieng biet
{
	// calling Fish::Swim
	InputFish.Swim();
}

int main()
{
	Tuna myDinner;
	Carp myLunch;

	//myDinner.Swim();
	MakeFishSwim(myDinner);
	MakeFishSwim(myLunch);
	return 0;
}