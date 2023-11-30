#include <iostream>
using namespace std;

class Phone_Fee{
	private:
		float _time;
	public:
		static long PRICE_PHONE;
		long calFee(){
			return PRICE_PHONE* this->_time;
		}
};
	long Phone_Fee::PRICE_PHONE = 1000;
	
	class Internet_Fee{
	private:
		long _luongTruyCap;
	public:
		static long PRICE_INTERNET;
		long calFee(){
			return PRICE_INTERNET*this->_luongTruyCap;
		}
};
	long Internet_Fee::PRICE_INTERNET = 200;
	
class Customer{
	private:
		string FullName;
		string ID;
		string Address;
	public:
		void dangKy(){
			cout<<"Nhap ho va ten:";
			getline(cin,this->FullName);
			cin.ignore();
			cin.clear();
			cout<<"Nhap so chung minh:";
			cin>>this->ID;
			cout<<"Nhap dia chi:";
			getline(cin,this->Address);
		}
};

class Cost{
	protected:
		Phone_Fee _phone_fee;
	public:
		static long VAT;
		virtual long calFee()=0;
};
	
class Basic:public Cost{
	private:
		Internet_Fee _internet_fee;
	public:
		long calFee(){
			return this->_phone_fee.calFee()+this->_internet_fee.calFee() + 0.1 * VAT;
		}
};
	
	
class Data_Fee:public Data_Fee{
	private:
		long _luongTruyCap;
	public:
		static long NGUONG_MIEN_PHI;
		static long CUOC_THUE_BAO;
		long calFee(){
			long phone_fee=this->_phone_fee.calFee();
			long internet_fee=0;
			if(_luongTruyCap<=NGUONG_MIEN_PHI){
				internet_fee=CUOC_THUE_BAO;
			}
			else {
				Internet_Fee temp(this->_luongTruyCap-NGUONG_MIEN_PHI);
				internet_fee=CUOC_THUE_BAO+temp.calFee();
			}
			return phone_fee+internet_fee;
		}
};
	
	
class Data_Fix:public Cost{
	public:
		static long MUC_CO_DINH;
		long calFee(){
			return (float)0.9*(this->_phone_fee.calFee())+ MUC_CO_DINH;
		}
};
long Data_Fix::MUC_CO_DINH = 1000000;
	
class Contract{
	private:
		Customer _cus;
		Cost* _cost;
	public:
		void dangKy(){
			this->_cus.dangKy();
			cout<<"Chon goi cuoc: 1-Basic,2-Data_Fee, 3-Data_Fix:\n";
			int choice;
			cin>>choice;
			if (choice==1){
				this->_cost=new Basic();
			}
			else if(choice==2){
				this->_cost=new Data_Fee();
			}
			else if(choice==3){
				this->_cost=new Data_Fix();
			}
			else {
				this->_cost =new Basic();
			}
		}
    void thongBao(){
			cout<<"Khach hang:\n";
			this->_cus.xuat();
			cout<<"Tien cuoc goi cuoc la:"<<this->_cost->calFee();
			cout<<endl;
		}
		~Contract(){
			if(this->_cost){
				delete this->_cost;
				this->_cost=NULL;
			}
		}
	};
class QuanLy{
		vector<Contract*> _ds;
	public:
		void dangKy(){
			int n;
			cout<<"Nhap luong hop dong:";
      cout << "Nhap luong hop dong:";
        cin >> n;
        for (int i = 0; i < n; i++) {
            Contract* c = new Contract();
            c->dangKy();
            this->_ds.push_back(c);
        }
    }
    void thongBao() {
        for (int i = 0; i < this->_ds.size(); i++) {
            this->_ds[i]->thongBao();
        }
    }
    ~QuanLy() {
        for (int i = 0; i < this->_ds.size(); i++) {
            if (this->_ds[i]) {
                delete this->_ds[i];
            }
        }
        this->_ds.clear();
    }
};
int main() {
    QuanLy ql;
    ql.dangKy();
    ql.thongBao();

    return 0;
}









