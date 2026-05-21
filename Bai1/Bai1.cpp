#include "Bai1.h"

NhanVien::NhanVien() : hoTen(""), ngaySinh(""), luong(0) {}
NhanVien::~NhanVien() {}

void NhanVien::nhap() {
    cout << "Nhap ho ten: ";
    cin.ignore();
    getline(cin, hoTen);
    cout << "Nhap ngay sinh (dd/mm/yyyy): ";
    getline(cin, ngaySinh);
}

void NhanVien::xuat() {
    cout << "Ho ten: " << hoTen
         << " Ngay sinh: " << ngaySinh
         << " Luong: " << (long long)luong << " VND";
}

double NhanVien::getLuong() {
    return luong;
}

int NhanVien::getNamSinh() {
    if (ngaySinh.length() >= 4) {
        string nam = ngaySinh.substr(ngaySinh.length() - 4);
        return stoi(nam);
    }
    return 0;
}

void NhanVienSanXuat::nhap() {
    cout << " Nhap Nhan Vien San Xuat " << endl;
    NhanVien::nhap();
    cout << "Nhap luong can ban: ";
    cin >> luongCanBan;
    cout << "Nhap so san pham: ";
    cin >> soSanPham;
    luong = tinhLuong();
}

void NhanVienSanXuat::xuat() {
    cout << "[NVSX] ";
    NhanVien::xuat();
    cout << " Luong CB: " << (long long)luongCanBan
         << " So SP: " << soSanPham << endl;
}

double NhanVienSanXuat::tinhLuong() {
    return luongCanBan + (soSanPham * 5000);
}

string NhanVienSanXuat::loai() {
    return "NVSX";
}

void NhanVienVanPhong::nhap() {
    cout << " Nhap Nhan Vien Van Phong " << endl;
    NhanVien::nhap();
    cout << "Nhap so ngay lam viec: ";
    cin >> soNgayLam;
    luong = tinhLuong();
}

void NhanVienVanPhong::xuat() {
    cout << "[NVVP] ";
    NhanVien::xuat();
    cout << " So ngay lam: " << soNgayLam << endl;
}

double NhanVienVanPhong::tinhLuong() {
    return soNgayLam * 100000;
}

string NhanVienVanPhong::loai() {
    return "NVVP";
}
