Inheritance:
Inheritance means one class takes properties/functions from another class.

It is an IS-A relationship.

class Animal {
public:
    void eat() {
        cout << "Eating\n";
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "Barking\n";
    }
};
Dog IS-A Animal

Multilevel inheritance
class A {};
class B : public A {};
class C : public B {};

Multiple inheritance
class C : public A, public B {};
