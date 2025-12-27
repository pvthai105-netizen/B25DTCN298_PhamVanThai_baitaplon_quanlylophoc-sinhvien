#include <iostream>
#include <vector>
#include <string>
using namespace std;
// ==================== LOP CO SO TRUU TUONG ====================
// Day la lop cha chua cac phuong thuc chung cho ca Lop hoc va Sinh vien
class QuanLy {
public:
    virtual void hienThi() = 0;        // Hien thi thong tin
    virtual void nhapThongTin() = 0;   // Nhap thong tin
    virtual string layMa() = 0;        // Lay ma de tim kiem
    virtual ~QuanLy() {}               // Destructor ao
};

// ==================== LOP HOC ====================
class LopHoc : public QuanLy {
private:
    string maLop;
    string tenLop;
    string chuyenNganh;
    string phanLoai; // CNTT hoac Ngoai ngu

public:
    // Ham kiem tra ma lop hop le (khong rong)
    bool kiemTraMaLop(string ma) {
        if (ma.empty()) {
            cout << "Loi: Ma lop khong duoc de trong!" << endl;
            return false;
        }
        return true;
    }

    // Ham kiem tra ten lop hop le
    bool kiemTraTenLop(string ten) {
        if (ten.empty()) {
            cout << "Loi: Ten lop khong duoc de trong!" << endl;
            return false;
        }
        return true;
    }
    // Ham kiem tra chuyen nganh hop le
    bool kiemTraChuyenNganh(string cn) {
        if (cn.empty()) {
            cout << "Loi: Chuyen nganh khong duoc de trong!" << endl;
            return false;
        }
        return true;
    }
    // Ham kiem tra phan loai hop le
    bool kiemTraPhanLoai(string pl) {
        if (pl != "CNTT" && pl != "cntt" && pl != "Ngoai ngu" && pl != "ngoai ngu") {
            cout << "Loi: Phan loai chi duoc la 'CNTT' hoac 'Ngoai ngu'!" << endl;
            return false;
        }
        return true;
    }
    void nhapThongTin() override {
        cin.ignore();
        
        // Nhap ma lop voi kiem tra
        do {
            cout << "Nhap ma lop: ";
            getline(cin, maLop);
        } while (!kiemTraMaLop(maLop));

        // Nhap ten lop voi kiem tra
        do {
            cout << "Nhap ten lop: ";
            getline(cin, tenLop);
        } while (!kiemTraTenLop(tenLop));

        // Nhap chuyen nganh voi kiem tra
        do {
            cout << "Nhap chuyen nganh: ";
            getline(cin, chuyenNganh);
        } while (!kiemTraChuyenNganh(chuyenNganh));

        // Nhap phan loai voi kiem tra
        do {
            cout << "Nhap phan loai (CNTT/Ngoai ngu): ";
            getline(cin, phanLoai);
        } while (!kiemTraPhanLoai(phanLoai));

        cout << "Da them lop hoc thanh cong!" << endl;
    }
    void hienThi() override {
        cout << "========================================" << endl;
        cout << "Ma lop: " << maLop << endl;
        cout << "Ten lop: " << tenLop << endl;
        cout << "Chuyen nganh: " << chuyenNganh << endl;
        cout << "Phan loai: " << phanLoai << endl;
        cout << "========================================" << endl;
    }

    string layMa() override {
        return maLop;
    }
    void capNhat() {
        cin.ignore();
        cout << "\n=== CAP NHAT THONG TIN LOP HOC ===" << endl;
        
        do {
            cout << "Nhap ten lop moi: ";
            getline(cin, tenLop);
        } while (!kiemTraTenLop(tenLop));

        do {
            cout << "Nhap chuyen nganh moi: ";
            getline(cin, chuyenNganh);
        } while (!kiemTraChuyenNganh(chuyenNganh));

        do {
            cout << "Nhap phan loai moi (CNTT/Ngoai ngu): ";
            getline(cin, phanLoai);
        } while (!kiemTraPhanLoai(phanLoai));

        cout << "Cap nhat thanh cong!" << endl;
    }
};

// ==================== SINH VIEN ====================
class SinhVien : public QuanLy {
private:
    string maSinhVien;
    string tenSinhVien;
    string ngaySinh; // Dinh dang: dd/mm/yyyy
    string email;
    string soDienThoai;

public:
    // Ham kiem tra ma sinh vien
    bool kiemTraMaSV(string ma) {
        if (ma.empty()) {
            cout << "Loi: Ma sinh vien khong duoc de trong!" << endl;
            return false;
        }
        return true;
    }

    // Ham kiem tra ten sinh vien
    bool kiemTraTenSV(string ten) {
        if (ten.empty()) {
            cout << "Loi: Ten sinh vien khong duoc de trong!" << endl;
            return false;
        }
        return true;
    }

    // Ham kiem tra ngay sinh (dinh dang dd/mm/yyyy)
    bool kiemTraNgaySinh(string ns) {
        if (ns.length() != 10) {
            cout << "Loi: Ngay sinh phai co dinh dang dd/mm/yyyy!" << endl;
            return false;
        }
        if (ns[2] != '/' || ns[5] != '/') {
            cout << "Loi: Ngay sinh phai co dinh dang dd/mm/yyyy!" << endl;
            return false;
        }
        return true;
    }

    // Ham kiem tra email (phai co @)
    bool kiemTraEmail(string em) {
        if (em.find('@') == string::npos) {
            cout << "Loi: Email phai chua ky tu @!" << endl;
            return false;
        }
        return true;
    }

    // Ham kiem tra so dien thoai (phai la so va co 10 chu so)
    bool kiemTraSoDienThoai(string sdt) {
        if (sdt.length() != 10) {
            cout << "Loi: So dien thoai phai co 10 chu so!" << endl;
            return false;
        }
        for (int i = 0; i < sdt.length(); i++) {
            if (sdt[i] < '0' || sdt[i] > '9') {
                cout << "Loi: So dien thoai chi duoc chua chu so!" << endl;
                return false;
            }
        }
        return true;
    }

    void nhapThongTin() override {
        cin.ignore();
        
        // Nhap ma sinh vien
        do {
            cout << "Nhap ma sinh vien: ";
            getline(cin, maSinhVien);
        } while (!kiemTraMaSV(maSinhVien));

        // Nhap ten sinh vien
        do {
            cout << "Nhap ten sinh vien: ";
            getline(cin, tenSinhVien);
        } while (!kiemTraTenSV(tenSinhVien));

        // Nhap ngay sinh
        do {
            cout << "Nhap ngay sinh (dd/mm/yyyy): ";
            getline(cin, ngaySinh);
        } while (!kiemTraNgaySinh(ngaySinh));

        // Nhap email
        do {
            cout << "Nhap email: ";
            getline(cin, email);
        } while (!kiemTraEmail(email));

        // Nhap so dien thoai
        do {
            cout << "Nhap so dien thoai (10 chu so): ";
            getline(cin, soDienThoai);
        } while (!kiemTraSoDienThoai(soDienThoai));

        cout << "Da them sinh vien thanh cong!" << endl;
    }

    void hienThi() override {
        cout << "========================================" << endl;
        cout << "Ma sinh vien: " << maSinhVien << endl;
        cout << "Ten sinh vien: " << tenSinhVien << endl;
        cout << "Ngay sinh: " << ngaySinh << endl;
        cout << "Email: " << email << endl;
        cout << "So dien thoai: " << soDienThoai << endl;
        cout << "========================================" << endl;
    }

    string layMa() override {
        return maSinhVien;
    }

    void capNhat() {
        cin.ignore();
        cout << "\n=== CAP NHAT THONG TIN SINH VIEN ===" << endl;
        
        do {
            cout << "Nhap ten sinh vien moi: ";
            getline(cin, tenSinhVien);
        } while (!kiemTraTenSV(tenSinhVien));

        do {
            cout << "Nhap ngay sinh moi (dd/mm/yyyy): ";
            getline(cin, ngaySinh);
        } while (!kiemTraNgaySinh(ngaySinh));

        do {
            cout << "Nhap email moi: ";
            getline(cin, email);
        } while (!kiemTraEmail(email));

        do {
            cout << "Nhap so dien thoai moi (10 chu so): ";
            getline(cin, soDienThoai);
        } while (!kiemTraSoDienThoai(soDienThoai));

        cout << "Cap nhat thanh cong!" << endl;
    }
};

// ==================== LOP QUAN LY CHUNG ====================
// Template class de quan ly ca Lop hoc va Sinh vien (Da hinh)
template <typename T>
class HeThongQuanLy {
private:
    vector<T> danhSach;  // Luu truc tiep doi tuong, khong dung con tro

public:
    // 1. HIEN THI DANH SACH
    void hienThiDanhSach() {
        if (danhSach.empty()) {
            cout << "\nDanh sach trong!" << endl;
            return;
        }
        cout << "\nDANH SACH:\n" << endl;
        for (int i = 0; i < danhSach.size(); i++) {
            cout << "STT " << (i + 1) << ":" << endl;
            danhSach[i].hienThi();
            cout << endl;
        }
    }
    // 2. THEM MOI
    void themMoi() {
        T item;  // Tao doi tuong tam thoi
        cout << "\nTHEM MOI:\n" << endl;
        item.nhapThongTin();
        danhSach.push_back(item);  // Sao chep vao vector
    }
    // 3. XOA
    void xoa() {
        if (danhSach.empty()) {
            cout << "\nDanh sach trong, khong co gi de xoa!" << endl;
            return;
        }
        string ma;
        cin.ignore();
        cout << "\nXOA:\n" << endl;
        cout << "Nhap ma can xoa: ";
        getline(cin, ma);

        for (int i = 0; i < danhSach.size(); i++) {
            if (danhSach[i].layMa() == ma) {
                danhSach.erase(danhSach.begin() + i);
                cout << "Da xoa thanh cong!" << endl;
                return;
            }
        }
        cout << "Khong tim thay ma: " << ma << endl;
    }

    // 4. CAP NHAT
    void capNhat() {
        if (danhSach.empty()) {
            cout << "\nDanh sach trong, khong co gi de cap nhat!" << endl;
            return;
        }

        string ma;
        cin.ignore();
        cout << "\nCAP NHAT:\n" << endl;
        cout << "Nhap ma can cap nhat: ";
        getline(cin, ma);

        for (int i = 0; i < danhSach.size(); i++) {
            if (danhSach[i].layMa() == ma) {
                danhSach[i].capNhat();
                return;
            }
        }
        cout << "Khong tim thay ma: " << ma << endl;
    }

    // Menu con cho tung doi tuong
    void hienThiMenuCon(string tenDoiTuong) {
        int luaChon;
        do {
            cout << "\n========================================" << endl;
            cout << "   QUAN LY " << tenDoiTuong << endl;
            cout << "========================================" << endl;
            cout << " 1. Hien thi danh sach" << endl;
            cout << " 2. Them moi" << endl;
            cout << " 3. Xoa" << endl;
            cout << " 4. Cap nhat" << endl;
            cout << " 0. Quay lai" << endl;
            cout << "========================================" << endl;
            cout << "Nhap lua chon: ";
            cin >> luaChon;
            // Kiem tra loi nhap
            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Loi: Vui long nhap so!" << endl;
                continue;
            }
            switch (luaChon) {
                case 1:
                    hienThiDanhSach();
                    break;
                case 2:
                    themMoi();
                    break;
                case 3:
                    xoa();
                    break;
                case 4:
                    capNhat();
                    break;
                case 0:
                    cout << "Quay lai menu chinh..." << endl;
                    break;
                default:
                    cout << "Lua chon khong hop le! Vui long chon tu 0-4." << endl;
            }
        } while (luaChon != 0);
    }
};

// ==================== HAM MAIN ====================
int main() {
    HeThongQuanLy<LopHoc> quanLyLopHoc;
    HeThongQuanLy<SinhVien> quanLySinhVien;

    int luaChon;

    cout << "\nCHAO MUNG DEN HE THONG QUAN LY RIKKEI EDU\n" << endl;

    do {
        cout << "\n========================================" << endl;
        cout << "          MENU CHINH" << endl;
        cout << "========================================" << endl;
        cout << " 1. Quan ly Lop hoc" << endl;
        cout << " 2. Quan ly Sinh vien" << endl;
        cout << " 0. Thoat chuong trinh" << endl;
        cout << "========================================" << endl;
        cout << "Nhap lua chon: ";
        cin >> luaChon;
        // Kiem tra loi nhap
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Loi: Vui long nhap so!" << endl;
            continue;
        }
        switch (luaChon) {
            case 1:
                quanLyLopHoc.hienThiMenuCon("LOP HOC");
                break;
            case 2:
                quanLySinhVien.hienThiMenuCon("SINH VIEN");
                break;
            case 0:
                cout << "\nCam on ban da su dung he thong. Tam biet!" << endl;
                break;
            default:
                cout << "Lua chon khong hop le! Vui long chon tu 0-2." << endl;
        }
    } while (luaChon != 0);
}
