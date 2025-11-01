#include <iostream>
#include <string>
using namespace std;


// Đây là lớp độc lập ban đầu
class Animal {
protected:
    string name;
public:
    Animal(string n) : name(n) {}

    void eat() {
        cout << name << " is eating.\n";
    }

    void sleep() {
        cout << name << " is sleeping.\n";
    }
};

// Lớp Dog kế thừa lớp độc lập Animal
class Dog : public Animal {
public:
    Dog(string n) : Animal(n) {}

    void bark() {
        cout << name << " is barking: Woof woof!\n";
    }
};

int main() {
    Dog d("Buddy");
    d.eat();   // kế thừa từ Animal
    d.sleep(); // kế thừa từ Animal
    d.bark();  // phương thức riêng của Dog
}




//// Abstract class
//class Shape {
//protected:
//    string color; // Field (thuộc tính)
//
//public:
//    Shape(const string& c) : color(c) {} // Constructor
//
//    virtual void draw() = 0; // Pure virtual function
//
//    void displayColor() { // Hàm bình thường
//        cout << "Color: " << color << endl;
//    }
//};
//
//// Concrete class kế thừa và triển khai draw()
//class Circle : public Shape {
//private:
//    double radius;
//
//public:
//    Circle(const string& c, double r) : Shape(c), radius(r) {}
//
//    void draw() override {
//        cout << "Drawing a " << color << " circle with radius " << radius << endl;
//    }
//};
//
//int main() {
//    // Shape s("red"); // không thể tạo đối tượng từ abstract class
//
//    Circle c("blue", 5.0);
//    c.displayColor(); // Gọi hàm có sẵn trong abstract class
//    c.draw();         // Gọi hàm override
//
//    return 0;
//}



//#include <iostream>
//#include <string>
//
//using namespace std;
//
//// Component interface - defines the basic ice cream
//// operations.
//class IceCream {
//public:
//    virtual string getDescription() const = 0;
//    virtual double cost() const = 0;
//};
//
//// Concrete Component - the basic ice cream class.
//class VanillaIceCream : public IceCream {
//public:
//    string getDescription() const override
//    {
//        return "Vanilla Ice Cream";
//    }
//
//    double cost() const override { return 160.0; }
//};
//
//// Decorator - abstract class that extends IceCream.
//class IceCreamDecorator : public IceCream {
//protected:
//    IceCream* iceCream;
//
//public:
//    IceCreamDecorator(IceCream* ic)
//        : iceCream(ic)
//    {
//    }
//
//    string getDescription() const override
//    {
//        return iceCream->getDescription();
//    }
//
//    double cost() const override
//    {
//        return iceCream->cost();
//    }
//};
//
//// Concrete Decorator - adds chocolate topping.
//class ChocolateDecorator : public IceCreamDecorator {
//public:
//    ChocolateDecorator(IceCream* ic)
//        : IceCreamDecorator(ic)
//    {
//    }
//
//    string getDescription() const override
//    {
//        return iceCream->getDescription()
//            + " with Chocolate";
//    }
//
//    double cost() const override
//    {
//        return iceCream->cost() + 100.0;
//    }
//};
//
//// Concrete Decorator - adds caramel topping.
//class CaramelDecorator : public IceCreamDecorator {
//public:
//    CaramelDecorator(IceCream* ic)
//        : IceCreamDecorator(ic)
//    {
//    }
//
//    string getDescription() const override
//    {
//        return iceCream->getDescription() + " with Caramel";
//    }
//
//    double cost() const override
//    {
//        return iceCream->cost() + 150.0;
//    }
//};
//
//int main()
//{
//    // Create a vanilla ice cream
//    IceCream* vanillaIceCream = new VanillaIceCream();
//    cout << "Order: " << vanillaIceCream->getDescription()
//        << ", Cost: Rs." << vanillaIceCream->cost()
//        << endl;
//
//    // Wrap it with ChocolateDecorator
//    IceCream* chocolateIceCream
//        = new ChocolateDecorator(vanillaIceCream);
//    cout << "Order: " << chocolateIceCream->getDescription()
//        << ", Cost: Rs." << chocolateIceCream->cost()
//        << endl;
//
//    // Wrap it with CaramelDecorator
//    IceCream* caramelIceCream
//        = new CaramelDecorator(chocolateIceCream);
//    cout << "Order: " << caramelIceCream->getDescription()
//        << ", Cost: Rs." << caramelIceCream->cost()
//        << endl;
//
//    delete vanillaIceCream;
//    delete chocolateIceCream;
//    delete caramelIceCream;
//
//    return 0;
//}