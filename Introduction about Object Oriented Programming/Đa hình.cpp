/*#include <iostream>
using namespace std;

class Base {
public:
    Base() { cout << "Base::Base() called\n"; }
    ~Base() { cout << "Base::~Base() called\n"; }
};

class Derived : public Base {
public:
    Derived() { cout << "Derived::Derived() called\n"; }
    ~Derived() { cout << "Derived::~Derived() called\n"; }
};

int main() {
    cout << "Creating Derived d;\n";
    Derived d;
    cout << "Exiting main (stack unwind)\n";
    return 0;
}
*/

//Output: 
//Creating Derived d;
//Base::Base() called
//Derived::Derived() called
//Exiting main(stack unwind)
//Derived::~Derived() called
//Base::~Base() called

/*
#include <iostream>
using namespace std;

class Animal {
public:
    Animal() { cout << "Animal constructed\n"; }
    virtual ~Animal() { cout << "Animal destroyed\n"; } // <<--- virtual!
    virtual void speak() const { cout << "Animal sound\n"; }
};

class Dog : public Animal {
public:
    Dog() { cout << "Dog constructed\n"; }
    ~Dog() override { cout << "Dog destroyed\n"; }
    void speak() const override { cout << "Woof\n"; }
};

int main() {
    Animal* a = new Dog();
    cout << "Calling a->speak()\n";
    a->speak(); 
    cout << "Deleting a\n";
    delete a; // sẽ gọi Dog::~Dog() rồi Animal::~Animal()
    return 0;
}*/


#include <iostream>
using namespace std;

class Abstract {
public:
    Abstract() { cout << "Abstract constructed\n"; }
    virtual ~Abstract() = 0; // pure virtual destructor
};

// tai sao bo no lai bi loi 
Abstract::~Abstract() {
    cout << "Abstract destroyed (base impl)\n";
}

class Impl : public Abstract {
public:
    Impl() { cout << "Impl constructed\n"; }
    ~Impl() override { cout << "Impl destroyed\n"; }
};

int main() {
    Abstract* p = new Impl();
    delete p; // sẽ gọi Impl::~Impl() rồi Abstract::~Abstract()
    return 0;
}
