Object Composition:
Has a relationship
1.Composition
One classes object is used in another class and it will have the original class's features
Strong Has a Relationship
class Room {
};

class House {
private:
    Room bedroom;
    Room kitchen;
};

2.Aggregation
Composition via pointer
The parent object only refers to another object; it does not own it.

class Student {
};

class Department {
private:
    Student* student;  // pointer to existing student
public:
    Department(Student* s) : student(s) {}
};

Department does not own these objects. If Department is destroyed student continue to exist.

Aggregation is used when a class needs to use another object, but should not own it.
