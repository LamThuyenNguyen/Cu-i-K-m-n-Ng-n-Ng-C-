class BenhNhan{
	protected:
		int MSBN;//mã số bệnh nhân
	public:
	  //nhập thông tin
		virtual void nhap(istream& is){
			is>>this->MSBN;
		}
		//cập nhật ngày xuất viện
		virtual void capNhatNgayXuatVien(int ngay);
		//trả về trạng thái bệnh nhân
		virtual bool getTrangThai(){
			return true;
		}
		//tính tiền viện phí 
		virtual long tinhTien(){
			return 0;//mặc định là 0
		}
		virtual void capNhatVienPhi(){
			
		}
	};
	class BenhNhanNgoaiTru{
	private:
	  //chi phí ngoại trú
		long _vienPhi;
	public:
	  ///nhập thông tin ngoại trú
		BenhNhanNgoaiTru(int id){
			this->MSBN=id;
		}
		virtual void nhap(istream& is){
			is>>this->_vienPhi;
		}
		//tổng chi phí ngoại trú
		long tinhTien(){
			return this->_vienPhi;
		}
		//cập nhật chi phí khi có thêm chi phí
		void capNhatVienPhi(long Tien){
			this->_vienPhi+=Tien;
		}
	};
	class BenhNhanNoiTru{
	private:
	  //các biến thành viên
		int _loaiPhong;//a=1,b=2,c=3
		int _ngayBatDauNamVien;
		int _soNgayNamVien;
		bool _daXuatVien;//true: da, false: chua
		long _phiKhamBenhMoiNgay;
	public:
		static long A;
		static long B;
		static long C;
		//nhập 
		void nhap(istream& is){
			is>>this->_phiKhamBenhMoiNgay;//phí khám mỗi ngày
			char c;
			is>>c;
			this->_loaiPhong=c-64;
		}
		BenhNhanNoiTru(int MaSo, int ngay, long tien, char c){
			this->MSBN=MaSo;
			this->_ngayBatDauNamVien=ngay;
			this->_phiKhamBenhMoiNgay=tien;
			this->_loaiPhong=c-64;
			this->_daXuatVien=false;
		}
		//cập nhật ngày bệnh nhân xuất viện
		void capNhatNgayXuatVien(int ngay){
			this->_soNgayNamVien=ngay-this->_ngayBatDauNamVien;
			this->_daXuatVien=true;
		}
		//tính tổng chi phí dựa trên loại phòng
		long tinhTien(){
			if(this->_loaiPhong==1){
				return this->A*(this->_soNgayNamVien+this->_phiKhamBenhMoiNgay);
			}
			else if(this->_loaiPhong==2){
				return this->B*(this->_soNgayNamVien+this->_phiKhamBenhMoiNgay);				
			}
			else if(this->_loaiPhong==3){
				return this->C*(this->_soNgayNamVien+this->_phiKhamBenhMoiNgay);				
			}
			else {
				return 0;
			}
		}
	};
	long BenhNhanNoiTru::A=1400000;
  long BenhNhanNoiTru::B=900000;
  long BenhNhanNoiTru::C=600000;

	class DanhSachBenhNhan{
		//vector chauws danh sách các bệnh nhân
		vector<BenhNhan*> _ds;
	public:
		void nhap(){
			//mở tệp input.log để đọc dữ liệu tuef đầu vào tiêu chuẩn stdin
			freopen("input.log","rt",stdin);
			int ngay=0;
			while(!cin.eof()){//đọc dữ liệu đến khi hết tệp
			  //đoạc các thông tin để chia trường hợp 
				cin>>ngay;
				int MaSo=0;
				cin>>MaSo;
				cin.ignore();
				cin.clear();
				string s="";
				cin>>s;
				BenhNhan* p=NULL;
				//nếu là kiểm tra bệnh (KB) đọc vào giá trị Tien
				if(s=="KB"){
					long Tien=0;
					cin>>Tien;
					if(MaSo<=this->_ds.size()-1){
						this->_ds[MaSo-1]->capNhatVienPhi(Tien);
					}
					//nếu bệnh nhân chưa tồn tại thì tạo bênh nhân mới
					else {
						p=new BenhNhanNgoaiTru (MaSo,Tien);
						this->_ds.push_back(p);
					}
				}
				//nếu là nội trú (NV) đọc giá trị tien và loại phòng c
				else if(s=="NV"){
					long Tien=0;
					cin>>Tien;
					char c;
					cin>>c;
					//tạo bệnh nhân nội trú mới
					p=new BenhNhanNoiTru(MaSo,ngay,Tien,c)
					this->_ds.push_back(p);
				}
				//nếu xuất viện (XV) cập nhật nagyf xuất viện cho bệnh nhân tương ứng trong danh sách
				else if(s=="XV"){
					this->_ds[MaSo-1]->capNhatNgayXuatVien(ngay);
				}
				//nếu là tính tổng chi phí thì alpwj qua danh sách bệnh nhân 
				else if(s=="TKVP"){
					for(int i=0;i<this->_ds.size();i++){
						//nếu bệnh nhân là bệnh nhân nội trú chưa xuất viện thì cập nhật ngày xuất viện
						if(dynamic_cast<BenhNhanNgoaiTru*>(this->_ds[i])==NULL){
							if(this->_ds[i]->getTrangThai()==false){
								this->_ds[i]->capNhatNgayXuatVien(ngay);
							}
						}
					}
				}
			}
			//đóng tệp
			freopen("CON","rt",stdin);
		}
		//hàm tinhTongVienPhi() để tính tổng viện phí của tắt cả các bệnh nhân trong bệnh viện 
		long tinhTongTienVienPhi(){
			long sum=0;
			for(int i=0;i<this->_ds.size();i++){
				sum+=this->_ds[i]->tinhTien();
			}
			return sum;//trả về tổng
		}
	};