// Tập tin PhanSo.cpp
#include "PhanSo.h"

PhanSo::PhanSo() {
    tu = 0;
    mau = 1;
}
PhanSo::PhanSo(int tu, int mau) {
    this->tu = tu;
    this->mau = mau;
}
PhanSo PhanSo::operator+(const PhanSo& other) const {
    PhanSo result;
    result.tu = tu * other.mau + other.tu * mau;
    result.mau = mau * other.mau;
    return result;
}
PhanSo& PhanSo::operator++() {
    tu += mau;
    return *this;
}
PhanSo PhanSo::operator+=(const PhanSo& other) {
    tu = tu * other.mau + other.tu * mau;
    mau *= other.mau;
    return *this;
}
PhanSo::operator int() const {
    return tu / mau;
}
ostream& operator<<(ostream& os, const PhanSo& ps) {
    os << ps.tu << '/' << ps.mau;
    return os;
}




