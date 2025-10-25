#include <iostream>
#include <string>
using namespace std;

class HoangTu 
{
private:
	int power;
	int blood;
	string alive;
public: 
	HoangTu(): power(0), blood(0), alive("") {}
	HoangTu(int, int, string);
	int getPower();
	int getBlood();
	string getAlive();
	void setPower(int);
	void setBlood(int);
	void setAlive(string);
	void printInformation();
};

HoangTu::HoangTu(int power, int blood, string alive) {
	this->power = power;
	this->blood = blood;
	this->alive = alive;
}

int HoangTu::getPower() {
	return power;
}

int HoangTu::getBlood() {
	return blood;
}

string HoangTu::getAlive() {
	return alive;
}

void HoangTu::setPower(int power) {
	this->power = power;
}

void HoangTu::setBlood(int blood) {
	this->blood = blood;
}

void HoangTu::setAlive(string alive) {
	this->alive = alive;
}

void HoangTu::printInformation() {
	cout << "POWER : " << power << endl;
	cout << "BLOOD : " << blood << endl;
	cout << alive << endl;
	cout << "--------------------" << endl;
}

int main() {
	string Power, Blood, alive;
	int power, blood;
	getline(cin, Power);
	getline(cin, Blood);
	cin >> alive;
	power = stoi(Power.substr(8));
	blood = stoi(Blood.substr(8));
	HoangTu hoangtu(power, blood, alive);
	int n; 
	cin >> n;
	for (int i = 0; i < n; i++) {
		string event;
		cin >> event;
		if (hoangtu.getAlive() == "ALIVE" && event == "mushroom") { // gap nam doc
			hoangtu.setPower(hoangtu.getPower() - 2);
			hoangtu.setBlood(hoangtu.getBlood() - 15);
		}
		else if (hoangtu.getAlive() == "ALIVE" && event == "witch") { // gap phu thuy
			int powerWitch; cin >> powerWitch;
			if (powerWitch >= hoangtu.getPower()) {
				hoangtu.setPower(0);
				hoangtu.setBlood(0);
				hoangtu.setAlive("DEAD");
			}
			else {
				hoangtu.setPower(hoangtu.getPower() + 5);
			}
		}
		else if (hoangtu.getAlive() == "ALIVE" && event == "pea") { // gap cay dau than
			hoangtu.setPower(hoangtu.getPower() + 2);
			hoangtu.setBlood(hoangtu.getBlood() + 10);
		}
		else {  // gag quan linh
			int powerSoldier; cin >> powerSoldier;
			if (powerSoldier >= hoangtu.getPower()) {
				hoangtu.setPower(0);
				hoangtu.setBlood(0);
				hoangtu.setAlive("DEAD");
			}
			else {
				hoangtu.setPower(hoangtu.getPower() + 7);
				hoangtu.setBlood(hoangtu.getBlood() + 5);
			}
		}
		hoangtu.printInformation();
	}


	return 0;
}