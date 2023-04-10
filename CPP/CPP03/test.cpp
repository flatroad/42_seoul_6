#include <iostream>
using namespace std;

class A {
public:
    A() { cout << "A constructor" << endl; }
};

class B {
public:
    B() { cout << "B constructor" << endl; }
};

class C : public A, public A {
public:
    C() : A() { cout << "C constructor" << endl; }
};

int main() {
    C c;
    return 0;
}