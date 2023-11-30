#include <iostream>
using namespace std;

//lớp trừu tượng
class Shape {
public:
    //phương thức thuần ảo (pure virtual method)
    virtual void draw() = 0;

    //phương thức bình thường
    void commonOperation() {
        cout << "Common operation for all shapes." << endl;
    }

    //hàm thành viên không phải là phương thức thuần ảo
    void nonVirtualFunction() {
        cout << "Non-virtual function in the abstract class." << endl;
    }

    //hàm thành viên staticFunction
    static void staticFunction() {
        cout << "Static function in the abstract class." << endl;
    }

    //hàm thành viên constFuntion
    void constFunction() const {
        cout << "Const function in the abstract class." << endl;
    }

    //hàm thành viên parameterizedFunction
    void parameterizedFunction(int value) {
        cout << "Parameterized function in the abstract class. Value: " << value << endl;
    }
};

//lớp con kế thừa từ lớp trừu tượng
class Circle : public Shape {
public:
    //triển khai phương thức thuần ảo từ lớp cơ sở
    void draw() override {
        cout << "Drawing a circle." << endl;
    }
};

int main() {
    Circle circle;
    circle.draw();//triển khai phương thức draw() của lớp con
    circle.commonOperation();//sử dụng phương thức từ lớp cơ sở
    circle.nonVirtualFunction();//sử dụng hàm nonVirtualFunction
    Shape::staticFunction();//sử dụng hàm staticFuntion
    circle.constFunction();//sử dụng hàm constFution
    circle.parameterizedFunction(42);//sử dụng hàm parameterizedFunction
    return 0;
}