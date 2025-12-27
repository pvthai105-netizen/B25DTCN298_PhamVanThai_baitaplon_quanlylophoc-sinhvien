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
};

// ==================== LOP HOC ====================
class LopHoc : public QuanLy {
private:
    string maLop;
    string tenLop;
    string chuyenNganh;
    string phanLoai; // CNTT hoac Ngoai ngu

public:
    void nhapThongTin() override {
        cin.ignore();
        
        cout << "Nhap ma lop: ";
        getline(cin, maLop);

        cout << "Nhap ten lop: ";
        getline(cin, tenLop);

        cout << "Nhap chuyen nganh: ";
        getline(cin, chuyenNganh);

        cout << "Nhap phan loai (CNTT/Ngoai ngu): ";
        getline(cin, phanLoai);

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
        
        cout << "Nhap ten lop moi: ";
        getline(cin, tenLop);

        cout << "Nhap chuyen nganh moi: ";
        getline(cin, chuyenNganh);

        cout << "Nhap phan loai moi (CNTT/Ngoai ngu): ";
        getline(cin, phanLoai);

        cout << "Cap nhat thanh cong!" << endl;
    }
};

// ==================== SINH VIEN ====================
class SinhVien : public QuanLy {
private:
    string maSinhVien;
    string tenSinhVien;
    string ngaySinh;
    string email;
    string soDienThoai;

public:
    void nhapThongTin() override {
        cin.ignore();
        
        cout << "Nhap ma sinh vien: ";
        getline(cin, maSinhVien);

        cout << "Nhap ten sinh vien: ";
        getline(cin, tenSinhVien);

        cout << "Nhap ngay sinh (dd/mm/yyyy): ";
        getline(cin, ngaySinh);

        cout << "Nhap email: ";
        getline(cin, email);

        cout << "Nhap so dien thoai: ";
        getline(cin, soDienThoai);

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
        
        cout << "Nhap ten sinh vien moi: ";
        getline(cin, tenSinhVien);

        cout << "Nhap ngay sinh moi (dd/mm/yyyy): ";
        getline(cin, ngaySinh);

        cout << "Nhap email moi: ";
        getline(cin, email);

        cout << "Nhap so dien thoai moi: ";
        getline(cin, soDienThoai);

        cout << "Cap nhat thanh cong!" << endl;
    }
};

// ==================== LOP QUAN LY CHUNG ====================
// Template class de quan ly ca Lop hoc va Sinh vien (Da hinh)
template <typename T>
class HeThongQuanLy {
private:
    vector<T> danhSach;

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
        T item;
        cout << "\nTHEM MOI:\n" << endl;
        item.nhapThongTin();
        danhSach.push_back(item);
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
