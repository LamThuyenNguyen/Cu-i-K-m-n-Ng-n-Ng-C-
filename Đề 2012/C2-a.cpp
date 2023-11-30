#include <iostream>
using namespace std;
//lớp cơ sở
class Shape {
public:
    virtual void draw() {
        cout << "Drawing a generic shape." << endl;
    }
};

//lớp con kế thừa từ lớp cơ sở
class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a circle." << endl;
    }
};

//lớp con khác kế thừa từ lớp cơ sở
class Square : public Shape {
public:
    void draw() override {
        cout << "Drawing a square." << endl;
    }
};

int main() {
    Shape* shape1 = new Circle();
    Shape* shape2 = new Square();
    shape1->draw();  //gọi phương thức của lớp Circle
    shape2->draw();  //gọi phương thức của lớp Square
    delete shape1;
    delete shape2;
    return 0;
}

