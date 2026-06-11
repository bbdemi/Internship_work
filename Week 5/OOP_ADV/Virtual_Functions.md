Virtual Functions:
Virtual functions are functions in a base class that can be overridden by child classes.

They are used when you want this behavior:

Base pointer/reference
        ↓
Actual child function runs

class Animal {
public:
    virtual void sound() {
        cout << "Animal sound\n";
    }
};

class Dog : public Animal {
public:
    void sound() override {
        cout << "Bark\n";
    }
};

Now:

Animal* a = new Dog();
a->sound();

Output:

Bark