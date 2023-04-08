#include <cstdio>

class MyClass {
public:
    MyClass(int num) : number(num) {}

    MyClass operator+(const MyClass& rhs) const {
        return MyClass(number + rhs.number);
    }

  	void operator+=(const MyClass& rhs) {
        number += rhs.number;
        // return *this;
    }

    int getNumber() const { return number; }

private:
    int number;
};


int main() {
    MyClass a(5);
    MyClass b(10);
    MyClass c = a + b;   // c = MyClass(15)
    c += MyClass(20);    // c = MyClass(35)
    printf("%d\n", (0x00000001 << 8));
    int result = c.getNumber();  // result = 35
    return 0;
}