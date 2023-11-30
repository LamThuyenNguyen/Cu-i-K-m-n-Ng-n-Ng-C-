class Cos : public Function {
public:
    //phương thức tính giá trị của hàm cos(x)
    double Value(double x) override {
        return cos(x);
    }
    //phương thức tính đạo hàm của hàm cos(x)
    double Derive(double x) override {
        return -sin(x);
    }
};

//hàm tính đạo hàm của hàm thương
double DaoHamThuong(Function* f, Function* g, double x) {
    //kiểm tra điều kiện f và g khác NULL
    if (g != NULL) {
        //tính tử số và mẫu số của đạo hàm thương
        double numerator = f->Derive(x) * g->Value(x) - f->Value(x) * g->Derive(x);
        double denominator = g->Value(x) * g->Value(x);
        //kiểm tra mẫu số khác 0 để tránh chia cho 0
        if (denominator != 0) {
            //trả về kết quả của đạo hàm thương
            return numerator / denominator;
        }
    }
    //trả về 0 nếu g là NULL hoặc mẫu số bằng 0
    return 0;
}

//hàm tính đạo hàm của hàm hợp
double DaoHamCuaHamHop(Function* f, Function* g, double x) {
    //kiểm tra điều kiện f và g khác NULL
    if (f != NULL && g != NULL) {
        //tính đạo hàm của hàm hợp theo công thức 
        return f->Derive(g->Value(x)) * g->Derive(x);
    }
    //trả về 0 nếu f hoặc g là NULL
    return 0;
}




























