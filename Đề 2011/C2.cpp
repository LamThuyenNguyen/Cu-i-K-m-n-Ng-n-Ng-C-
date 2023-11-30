//Đề 2011 Câu 2
#include <iostream>
using namespace std;

class MayLoc {
private:
    float m_tgian;

protected:
    virtual float congSuat();
    void setTgian(float t);

public:
    MayLoc();
    float tinhLuongNuoc();
    friend ostream& operator << (ostream& os, MayLoc loc);
};

MayLoc::MayLoc() {
    this->m_tgian = 0;
}

void MayLoc::setTgian(float t) {
    this->m_tgian = t;
}

float MayLoc::tinhLuongNuoc() {
    return congSuat() * m_tgian;
}

float MayLoc::congSuat() {
    return 0;
}

ostream& operator << (ostream& os, MayLoc loc) {
    os << "Luong nuoc loc duoc: " << loc.tinhLuongNuoc();
    return os;
}

class MayXucTac : public MayLoc {
private:
    float m_cs;

protected:
    float congSuat();

public:
    static const int DON_GIA_HOA_CHAT = 10000;
    static const int DON_GIA_THUE=80000;
    MayXucTac(float cs, float t);
    void nhap();
    float tinhChiPhi();
};
MayXucTac::MayXucTac(float cs, float t) {
    this->m_cs = cs;
    this->setTgian(t);
}

float MayXucTac::congSuat() {
    return this->m_cs;
}

void MayXucTac::nhap() {
    cout << "Nhap cong suat may: ";
    cin >> m_cs;
    cout << "Nhap thoi gian su dung may: ";
    float tg;
    cin >> tg;
    setTgian(tg);
}

float MayXucTac::tinhChiPhi() {
    return tinhLuongNuoc() * DON_GIA_HOA_CHAT;
}

int main() {
    cout << "Don gia hoa chat: " << MayXucTac::DON_GIA_HOA_CHAT << endl;
    MayXucTac m(0,0); // Assuming initial values for congSuat and tgian
    m.nhap();
    cout << "Chi phi su dung may: " << m.tinhChiPhi() << endl;
    cout << "Luong nuoc loc duoc: " << m.tinhLuongNuoc() << endl;
    return 0;
}

