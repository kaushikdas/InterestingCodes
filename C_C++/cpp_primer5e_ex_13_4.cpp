#include <iostream>

using namespace std;

class Point {
    int x_ , y_ ;
public:
    static int cp_count_obj ;
    Point() : x_{0}, y_{0} {}

    Point(int x, int y) : x_{x}, y_{y} {}

    Point(const Point &point) : x_{point.x_}, y_{point.y_} {
        cout << "Inside Copy Constructor" << endl;
        ++cp_count_obj ;
    }

    Point& operator=(const Point &point) {
        cout << "Inside Copy Assignment Operator" << endl;
        x_ = point.x_;
        y_ = point.y_;
        return *this;
    }

    void setPoint(int x, int y) {
        x_ = x;
        y_ = y;
    }

    friend ostream &operator<<(ostream &os, const Point &point) {
        os << "(" << point.x_ << ", " << point.y_ << ")";
        return os;
    }
};

int Point::cp_count_obj = 0 ;

Point global;

Point foo_bar(Point arg)
{
    Point local = arg;
    cout << "After 1" << "\n";
    Point *heap = new Point(global);
    cout << "After 2" << "\n";
    *heap = local;
    cout << "After 3" << "\n";
    Point pa[ 4 ] = { local, *heap };
    cout << "After 4" << "\n";
    return *heap;
}   

int main() {
    auto fb = foo_bar(global);
    cout << "Total Copy constructor called : " << Point::cp_count_obj << endl ;

    #if defined(_MSVC_LANG)
        long version = _MSVC_LANG;
    #else
        long version = __cplusplus;
    #endif

    std::cout << "C++ Standard Value: " << version << "\n";

    if (version == 202612L) std::cout << "Using C++26\n";
    else if (version == 202302L) std::cout << "Using C++23\n";
    else if (version == 202002L) std::cout << "Using C++20\n";
    else if (version == 201703L) std::cout << "Using C++17\n";
    else if (version == 201402L) std::cout << "Using C++14\n";
    else if (version == 201103L) std::cout << "Using C++11\n";
    else if (version == 199711L) std::cout << "Using C++98\n";
    else std::cout << "Using Pre-C++98 or non-standard version\n";

    return 0;
}
