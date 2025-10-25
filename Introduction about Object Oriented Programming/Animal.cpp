#include <iostream>
using namespace std;

class Animal 
{
private: 
    bool bietBoi;
    int Weight;
    int Age;
public:
    Animal():Age(0), Weight(0), bietBoi(false) // Khoi tao 
    {
        cout << "Animal constructor" << endl;

    }
    void setAge(int Age) {
        this->Age = Age;
    }

    int getAge() {
        return Age;
    }

    void setWeight(int Weight)
    {
        this->Weight = Weight;
    }

    int getWeight() {
        return Weight;
    }

    void Swim(bool);
    // sample method 
    //int Age; 
};

void Animal::Swim(bool bietBoi) {
    if (bietBoi) cout << "Animal can swim!" << endl;
    else cout << "Animal can't swim!" << endl;
}

class Mammal : public virtual Animal {};
class Bird: public virtual Animal {};
class Reptile: public virtual Animal {};

class Platypus : public Mammal, public Bird, public Reptile 
{
public:
    Platypus()
    {
        cout << "Platypus constructor" << endl;
    }
    
};

int main() {
    Platypus duckBilledP;
    duckBilledP.setAge(5);
    duckBilledP.setWeight(30);
    cout << "Age = " << duckBilledP.getAge() << ", Weight = " << duckBilledP.getWeight() << endl;
    duckBilledP.Swim(true);
    return 0;
}