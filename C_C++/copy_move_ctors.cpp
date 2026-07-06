#include <iostream>
#include <utility>                                    // for move

using std::cout;
using std::move;

class A {
public:
    A() { cout << "Defa Ctor" << std::endl; }         // Default ctor
    A(const A &other) {                               // Copy ctor
        cout << "Copy Ctor" << std::endl;
    }
    A(A &&other) noexcept {                           // Move ctor
        cout << "Move Ctor" << std::endl;
    }
    A &operator=(const A &other) {                    // Copy assignment
        cout << "Copy Asgn" << std::endl;
        return *this;
    }
    A &operator=(A &&other) noexcept {                // Move assignment
        cout << "Move Asgn" << std::endl;
        return *this;
    }

    ~A() = default;

    friend A operator+(const A &lhs, const A &rhs) {  
        A t;
        return t;                                     // Temp. object ret by val                                          
    }

private:
    // int value;
};

int main() {
    cout << "  [1]\n"; A a;                          // lvalue
    cout << "  [2]\n"; A b = a;                      // lvalue  
    cout << "  [3]\n"; A c = a + b;                  // rvalue, a + b is temp.
    cout << "  [4]\n"; A d = move(a);                // rvalue
    cout << "  [5]\n"; b = a;                        // lvalue
    cout << "  [6]\n"; c = a + b;                    // rvalue
}