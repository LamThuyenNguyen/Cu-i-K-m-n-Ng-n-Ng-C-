// Tập tin PhanSo.h
#ifndef _PhanSo_h
#define _PhanSo_h
#include <iostream>
using namespace std;

class PhanSo {
private:
    int tu, mau;
public:
    PhanSo();
    PhanSo(int tu, int mau);//phương thức tạo với tham số
    PhanSo operator+(const PhanSo& other) const;//toán tử cộng
    PhanSo& operator++();//toán tử ++ tiền tố
    PhanSo operator+=(const PhanSo& other);//toán tử cộng và gán
    operator int() const;//toán tử chuyển đổi kiểu
    friend ostream& operator<<(ostream& os, const PhanSo& ps);//toán tử xuất
};

#endif
