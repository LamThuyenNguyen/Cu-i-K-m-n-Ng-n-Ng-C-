double DaoHamThuong(Function* f, Function* g, double x){
    //kiểm tra hàm g có tồn tại hay không để tránh lỗi mãu số bằng 0
    if (g != NULL){
        //tính tử số của đạo hàm thương 
        double numerator = f->Derive(x) * g->Value(x) - f->Value(x) * g->Derive(x);
        //tính mẫu số của đạo hàm thương
        double denominator = pow(g->Value(x), 2);
        //kiểm tra mẫu số để tránh lỗi chia cho 0
        if (denominator != 0) {
            return numerator / denominator;
        }
    }
    return 0;
}

double DaoHamHop(Function* f, Function* g, double x){
    if (f != NULL && g != NULL){
        //tính giá trị của hàm g(x) và đạo hàm của hàm g(x) tại x
        double gx = g->Value(x);
        double g_prime_x = g->Derive(x);
        //tính đạo hàm của hàm hợp theo công thức 
        return f->Derive(gx) * g_prime_x;
    }
    return 0;
}


