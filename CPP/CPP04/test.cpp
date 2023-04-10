#include <iostream>

class Base {
public:
    virtual void foo() {
        std::cout << "Base::foo()" << std::endl;
    }
};

class Derived : public Base {
public:
    void foo() {
        std::cout << "Derived::foo()" << std::endl;
    }
};

int main() {
    Base* basePtr = new Derived();
    basePtr->foo(); // Derived::foo()
    delete basePtr;
    return 0;
}