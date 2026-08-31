// file: vtable.cpp

#include <iostream>

using namespace std;

class Base {
public:
    virtual void foo() { cout << "Base::foo" << endl; }
    virtual void bar() { cout << "Base::bar" << endl; }
};

class Derived : public Base {
public:
    void foo() override { cout << "Derived::foo" << endl; } // Overridden
};

int main() {
    Derived d; // Instantiation ensures the layout gets generated

    Base *p = &d; // Base pointer to Derived object
    p->foo(); // Calls Derived::foo due to vtable
    p->bar(); // Calls Base::bar since it's not overridden in Derived

    return 0;
}

/* 

OUTPUT

$ g++ vtable.cpp
$ ./a.out 
Derived::foo
Base::bar

*/
