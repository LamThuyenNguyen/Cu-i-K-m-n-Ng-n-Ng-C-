//Đề 2011 Câu 3b
#include <iostream>
#include <vector>
using namespace std;

//lớp cơ sở máy lọc
class MayLoc{
protected:
    float congSuat;//công suất của máy lọc
    float tgian;//thời gian sử dụng máy
public:
    virtual void nhap() = 0;//phương thức nhập thông tin máy
    virtual float tinhLuongNuoc() = 0;//phương thức tính lượng nước được lọc
    virtual float tinhChiPhi() = 0;//phương thức tính chi phí sử dụng máy
    virtual ~MayLoc(){};//hàm hủy đảm bảo việc giải phóng bộ nhớ
};

//lớp con MayLyTam kế thừa từ lớp cơ sở MayLoc
class MayLyTam : public MayLoc{
private:
    float m_cs;//công suất của máy lọc ly tâm
public:
    //hàm nhập
    void nhap() override{
        cout << "Nhap cong suat may: ";
        cin >> m_cs;
        cout << "Nhap thoi gian su dung may: ";
        cin >> tgian;
    }
    //hàm tính lượng nước
    float tinhLuongNuoc() override{
        return congSuat * tgian;
    }
    //hàm tính chi phí 
    float tinhChiPhi() override{
        return 20000 * tgian;
    }
};

//lớp con MayXucTac kế thừa từ lớp cơ sở MayLoc
class MayXucTac : public MayLoc{
private:
    float lHoaChat;//lượng hóa chất sử dụng cho máy lọc xuất tác
public:
    //hàm nhập
    void nhap() override{
        cout << "Nhap luong hoa chat (gram): ";
        cin >> lHoaChat;
        cout << "Nhap thoi gian su dung may: ";
        cin >> tgian;
    }
    //hàm tính lượng nước
    float tinhLuongNuoc() override{
        return congSuat * tgian;
    }
    //hàm tính chi phí
    float tinhChiPhi() override{
        return 80000 * tgian + 10000 * lHoaChat;
    }
};

//lớp Ao đại diện cho ao nước, chứa các máy lọc và thực hiện việc quản lý
class Ao{
private:
    float luongNuoc;//lượng nước trong ao
    vector<MayLoc*> mayLocs;//vector chứa các đối tượng máy lọc
public:
    //hàm nhập
    void nhap(){
        cout << "Nhap luong nuoc trong ao (m3): ";
        cin >> luongNuoc;
        int n;
        cout << "Nhap so luong may loc: ";
        cin >> n;
        //nhập vào danh sách các máy lọc
        for (int i = 0; i < n; ++i){
            cout << "Nhap loai may loc (1: Ly Tam, 2: Xuc Tac): ";
            int choice;
            cin >> choice;
            MayLoc* mayLoc = nullptr;
            if (choice == 1){
                mayLoc = new MayLyTam();
            } else if (choice == 2){
                mayLoc = new MayXucTac();
            }
            if (mayLoc != nullptr){
                mayLoc->nhap();
                mayLocs.push_back(mayLoc);
            } else {
                cout << "Lua chon khong hop le." << endl;
            }
        }
    }
    //hàm kiểm tra xem ao có hết nước không
    bool aoDuocLocHet() const{
        float luongNuocLocDuoc = 0;
        for (const auto& mayLoc : mayLocs) {
            luongNuocLocDuoc += mayLoc->tinhLuongNuoc();
        }
        return luongNuocLocDuoc >= luongNuoc;
    }
    //hàm tính tổng chi phí sử dụng tất cả các máy lọc trong ao
    long tongChiPhi() const{
        long totalCost = 0;
        for (const auto& mayLoc : mayLocs) {
            totalCost += mayLoc->tinhChiPhi();
        }
        return totalCost;
    }
    //hàm hủy giải phòng bộ nhớ của các máy lọc khi đối tượng ao bị hủy 
    ~Ao(){
        for (const auto& mayLoc : mayLocs) {
            delete mayLoc;
        }
    }
};

//hàm chính
int main(){
    Ao ao;
    ao.nhap();
    if (ao.aoDuocLocHet()){
        cout << "Ao loc het nuoc." << endl;
    } else {
        cout << "Ao chua loc het nuoc." << endl;
    }
    cout << "Tong chi phi su dung may loc: " << ao.tongChiPhi() << endl;
    return 0;
}





