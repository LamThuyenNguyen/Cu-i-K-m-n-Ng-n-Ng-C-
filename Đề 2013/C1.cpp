#include <iostream>
using namespace std;
class ComplexNumber {
private:
    int a, b;

public:
    ComplexNumber(int a, int b) : a(a), b(b) {}

    void display() const {
        if (b >= 0)
            std::cout << a << " + " << b << "√7";
        else
            std::cout << a << " - " << -b << "√7";
    }

    ComplexNumber operator-() const {
        return ComplexNumber(-a, -b);
    }

    ComplexNumber operator+(const ComplexNumber& other) const {
        return ComplexNumber(a + other.a, b + other.b);
    }

    ComplexNumber operator-(const ComplexNumber& other) const {
        return ComplexNumber(a - other.a, b - other.b);
    }

    ComplexNumber operator*(const ComplexNumber& other) const {
        int resultA = a * other.a + 7 * b * other.b;
        int resultB = a * other.b + b * other.a;
        return ComplexNumber(resultA, resultB);
    }

    // Nạp chồng toán tử so sánh
    bool operator==(const ComplexNumber& other) const {
        return (a == other.a) && (b == other.b);
    }

    // Nạp chồng toán tử nhập
    friend std::istream& operator>>(std::istream& is, ComplexNumber& complex) {
        std::cout << "Enter real part (a): ";
        is >> complex.a;
        std::cout << "Enter imaginary part (b): ";
        is >> complex.b;
        return is;
    }

    // Nạp chồng toán tử xuất
    friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& complex) {
        if (complex.b >= 0)
            os << complex.a << " + " << complex.b << "√7";
        else
            os << complex.a << " - " << -complex.b << "√7";
        return os;
    }
};

int main() {
    ComplexNumber num1(3, 2);
    ComplexNumber num2(1, -4);

    ComplexNumber sum = num1 + num2;
    ComplexNumber diff = num1 - num2;
    ComplexNumber neg = -num1;
    ComplexNumber prod = num1 * num2;

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Difference: " << diff << std::endl;
    std::cout << "Negation: " << neg << std::endl;
    std::cout << "Product: " << prod << std::endl;

    // Nạp chồng toán tử nhập
    ComplexNumber num3();
    std::cin >> num3;
    std::cout << "You entered: " << num3 << std::endl;

    return 0;
}