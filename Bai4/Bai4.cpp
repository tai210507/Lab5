#include "Bai4.h"

//  LỚP NHÂN VIÊN
NhanVien::NhanVien() : maNhanVien(""), hoTen(""), tuoi(0), sdt(""), email(""), luongCoBan(0) {}
NhanVien::~NhanVien() {}

void NhanVien::nhap() {
    cout << "Nhap ma nhan vien: ";
    cin >> maNhanVien;
    cin.ignore();
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);
    cout << "Nhap tuoi: ";
    cin >> tuoi;
    cin.ignore();
    cout << "Nhap so dien thoai: ";
    getline(cin, sdt);
    cout << "Nhap email: ";
    getline(cin, email);
    cout << "Nhap luong co ban: ";
    cin >> luongCoBan;
}

void NhanVien::xuat() {
    cout << "Ma NV: " << maNhanVien
         << "  Ho ten: " << hoTen
         << "  Tuoi: " << tuoi
         << "  SDT: " << sdt
         << "  Email: " << email;
}

double NhanVien::getLuong() {
    return tinhLuong(); // Gọi hàm đa hình
}

//  LỚP LẬP TRÌNH VIÊN
void LapTrinhVien::nhap() {
    cout << " Nhap Thong Tin Lap Trinh Vien " << endl;
    NhanVien::nhap();
    cout << "Nhap so gio overtime: ";
    cin >> soGioOvertime;
}

void LapTrinhVien::xuat() {
    cout << "[LTV] ";
    NhanVien::xuat();
    cout << "  Luong CB: " << (long long)luongCoBan
         << "  Overtime: " << soGioOvertime << "h"
         << "  TONG LUONG: " << (long long)tinhLuong() << " VND\n";
}

double LapTrinhVien::tinhLuong() {
    return luongCoBan + (soGioOvertime * 200000.0);
}

string LapTrinhVien::loaiNhanVien() {
    return "LTV";
}

// LỚP KIỂM CHỨNG VIÊN
void KiemChungVien::nhap() {
    cout << " Nhap Thong Tin Kiem Chung Vien " << endl;
    NhanVien::nhap();
    cout << "Nhap so loi phat hien: ";
    cin >> soLoiPhatHien;
}

void KiemChungVien::xuat() {
    cout << "[KCV] ";
    NhanVien::xuat();
    cout << "  Luong CB: " << (long long)luongCoBan
         << "  So loi: " << soLoiPhatHien
         << "  TONG LUONG: " << (long long)tinhLuong() << " VND\n";
}

double KiemChungVien::tinhLuong() {
    return luongCoBan + (soLoiPhatHien * 50000.0);
}

string KiemChungVien::loaiNhanVien() {
    return "KCV";
}

//  LỚP CÔNG TY HOÀN CẦU
CongTyHoanCau::~CongTyHoanCau() {
    for (NhanVien* nv : danhSach) {
        delete nv;
    }
    danhSach.clear();
}

void CongTyHoanCau::nhapDanhSach() {
    int n;
    cout << "Nhap so luong nhan vien can them: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int loai;
        cout << "\nChon loai (1: Lap Trinh Vien, 2: Kiem Chung Vien): ";
        cin >> loai;

        NhanVien* nv = nullptr;
        if (loai == 1) {
            nv = new LapTrinhVien();
        } else if (loai == 2) {
            nv = new KiemChungVien();
        } else {
            cout << "Lua chon khong hop le!" << endl;
            i--;
            continue;
        }
        nv->nhap();
        danhSach.push_back(nv);
    }
}

void CongTyHoanCau::xuatDanhSach() {
    cout << "\n DANH SACH NHAN VIEN \n";
    for (NhanVien* nv : danhSach) {
        nv->xuat();
    }
}

double CongTyHoanCau::tinhLuongTrungBinh() {
    if (danhSach.empty()) return 0;
    double tongLuong = 0;
    for (NhanVien* nv : danhSach) {
        tongLuong += nv->getLuong();
    }
    return tongLuong / danhSach.size();
}

void CongTyHoanCau::xuatNV_LuongThapHonTB() {
    double tb = tinhLuongTrungBinh();
    cout << "\n DANH SACH NHAN VIEN LUONG THAP HON TRUNG BINH (" << (long long)tb << " VND) \n";
    bool found = false;
    for (NhanVien* nv : danhSach) {
        if (nv->getLuong() < tb) {
            nv->xuat();
            found = true;
        }
    }
    if (!found) cout << "Khong co nhan vien nao co luong thap hon trung binh.\n";
}

void CongTyHoanCau::xuatNV_LuongCaoNhat() {
    if (danhSach.empty()) return;
    double maxLuong = danhSach[0]->getLuong();
    for (NhanVien* nv : danhSach) {
        if (nv->getLuong() > maxLuong) {
            maxLuong = nv->getLuong();
        }
    }
    cout << "\n NHAN VIEN CO LUONG CAO NHAT \n";
    for (NhanVien* nv : danhSach) {
        if (nv->getLuong() == maxLuong) nv->xuat();
    }
}

void CongTyHoanCau::xuatNV_LuongThapNhat() {
    if (danhSach.empty()) return;
    double minLuong = danhSach[0]->getLuong();
    for (NhanVien* nv : danhSach) {
        if (nv->getLuong() < minLuong) {
            minLuong = nv->getLuong();
        }
    }
    cout << "\n NHAN VIEN CO LUONG THAP NHAT \n";
    for (NhanVien* nv : danhSach) {
        if (nv->getLuong() == minLuong) nv->xuat();
    }
}

void CongTyHoanCau::xuatLTV_LuongCaoNhat() {
    double maxLuong = -1;
    for (NhanVien* nv : danhSach) {
        if (nv->loaiNhanVien() == "LTV" && nv->getLuong() > maxLuong) {
            maxLuong = nv->getLuong();
        }
    }
    cout << "\n LAP TRINH VIEN CO LUONG CAO NHAT \n";
    if (maxLuong == -1) {
        cout << "Khong co Lap Trinh Vien nao trong danh sach.\n";
        return;
    }
    for (NhanVien* nv : danhSach) {
        if (nv->loaiNhanVien() == "LTV" && nv->getLuong() == maxLuong) nv->xuat();
    }
}

void CongTyHoanCau::xuatKCV_LuongThapNhat() {
    double minLuong = -1;
    for (NhanVien* nv : danhSach) {
        if (nv->loaiNhanVien() == "KCV") {
            if (minLuong == -1 || nv->getLuong() < minLuong) {
                minLuong = nv->getLuong();
            }
        }
    }
    cout << "\n KIEM CHUNG VIEN CO LUONG THAP NHAT \n";
    if (minLuong == -1) {
        cout << "Khong co Kiem Chung Vien nao trong danh sach.\n";
        return;
    }
    for (NhanVien* nv : danhSach) {
        if (nv->loaiNhanVien() == "KCV" && nv->getLuong() == minLuong) nv->xuat();
    }
}
