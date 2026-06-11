Polymorphism:
Polymorphism literally means:

"Many forms."

In C++, polymorphism means:

The same interface can behave differently depending on the actual object being used.

It is built using inheritance + virtual functions.

Base class
class Animal {
public:
    virtual void sound() {
        cout << "Animal sound\n";
    }
};
Child classes
class Dog : public Animal {
public:
    void sound() override {
        cout << "Bark\n";
    }
};

class Cat : public Animal {
public:
    void sound() override {
        cout << "Meow\n";
    }
};
Using polymorphism
Animal* a1 = new Dog();
Animal* a2 = new Cat();

a1->sound();
a2->sound();

Output:

Bark
Meow