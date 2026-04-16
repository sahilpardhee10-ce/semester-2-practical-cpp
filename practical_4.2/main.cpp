#include <iostream>
using namespace std;

class Point {
    int x, y;

public:
    Point() : x(0), y(0) {}
    Point(int x, int y) : x(x), y(y) {}

    // make move chainable by returning a reference to *this
    Point& move(int dx, int dy) {
        x += dx;
        y += dy;
        return *this;
    }

    void display() const {
        cout << "Point(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Point p1; // Default constructor
    Point p2(3, 4); // Parameterized constructor

    cout << "Initial points:" << endl;
    p1.display();
    p2.display();

    // chained moves
    p1.move(1, 2).move(3, 3); // Move p1 by (1,2) then (3,3)
    p2.move(-1, -1).move(2, 0); // Move p2 by (-1,-1) then (2,0)

    cout << "After moving points:" << endl;
    p1.display();
    p2.display();

    return 0;
}