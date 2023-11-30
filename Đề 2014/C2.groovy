#include <math.h>
#include <stdio.h>

class Function {
public:
    //phương thức ảo tính giá trị của hàm tại x
    virtual double Value(double x) = 0;

    //phương thức ảo tính đạo hàm của hàm tại x
    virtual double Derive(double x) = 0;
};

//định nghĩa lớp Sin kế thừa từ lớp Function
class Sin : public Function {
private:
    static Sin* instance;
    //hàm tạo ẩn đi để không thể tạo đối tượng từ bên ngoài
    Sin() {}

public:
    //hàm lấy đối tượng duy nhất của lớp Sin
    static Sin* GetInstance() {
        //kiểm tra xem instance đã được khởi tạo chưa
        if (instance == nullptr) {
            //nếu instance chưa được khởi tạo, tạo một đối tượng Sin mới
            instance = new Sin();
        }
        //trả về đối tượng Sin (đối tượng duy nhất)
        return instance;
    }
    //phương thức tính giá trị của hàm sin(x)
    double Value(double x) override {
        return sin(x);
    }
    //phương thức tính đạo hàm của hàm sin(x)
    double Derive(double x) override {
        return cos(x);
    }
};
//khởi tạo biến tĩnh instance của lớp Sin
Sin* Sin::instance = nullptr;
//hàm chính
int main() {
    //khai báo biến x và gán giá trị PI/6
    double x = 3.14 / 6; // PI/6
    //sử dụng hàm GetInstance() để lấy đối tượng duy nhất của lớp Sin
    Sin* s = Sin::GetInstance();
    //gọi hàm DeriveProduct để tính đạo hàm tích của hàm sin(x) với nó tại x
    double y = DeriveProduct(s, s, x);
    //in ra giá trị của sin(x), đạo hàm của sin(x), và đạo hàm tích của sin(x)
    printf("sin(x) = %f; sin'(x) = %f\n", s->Value(x), s->Derive(x));
    printf("y = %f\n", y);
    // Kết thúc chương trình, đối tượng Sin được giải phóng tự động
    return 0;
}









