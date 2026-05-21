#include "Bai6.h"

//  LỚP KHÁCH HÀNG
KhachHang::KhachHang() : hoTen(""), soLuongHang(0), donGiaHang(0) {}
KhachHang::~KhachHang() {}

void KhachHang::nhap() {
    cout << "Nhap ho ten khach hang: ";
    cin.ignore();
    getline(cin, hoTen);
    cout << "Nhap so luong hang: ";
    cin >> soLuongHang;
    cout << "Nhap don gia hang: ";
    cin >> donGiaHang;
}

void KhachHang::xuat() {
    cout << "Ho ten: " << hoTen
         << "  So luong: " << soLuongHang
         << "  Don gia: " << (long long)donGiaHang;
}

//  KHÁCH HÀNG BÌNH THƯỜNG (A)
void KhachHangBinhThuong::nhap() {
    cout << " Nhap Khach Hang Binh Thuong (Loai A) \n";
    KhachHang::nhap();
}

void KhachHangBinhThuong::xuat() {
    cout << "[Loai A] ";
    KhachHang::xuat();
    cout << "  Thanh tien: " << (long long)tinhTien() << " VND\n";
}

double KhachHangBinhThuong::tinhTien() {
    double tien = soLuongHang * donGiaHang;
    return tien + tien * 0.1; // + 10% VAT
}

string KhachHangBinhThuong::loaiKhachHang() {
    return "A";
}

//  KHÁCH HÀNG THÂN THIẾT (B)
void KhachHangThanThiet::nhap() {
    cout << " Nhap Khach Hang Than Thiet (Loai B) \n";
    KhachHang::nhap();
    cout << "Nhap so nam than thiet: ";
    cin >> soNamThanThiet;
}

void KhachHangThanThiet::xuat() {
    cout << "[Loai B] ";
    KhachHang::xuat();
    cout << "  Nam TT: " << soNamThanThiet
         << "  Thanh tien: " << (long long)tinhTien() << " VND\n";
}

double KhachHangThanThiet::tinhTien() {
    double tien = soLuongHang * donGiaHang;
    // Vẫn dùng std::max như đề bài viết MAX
    double phanTramKM = max((soNamThanThiet * 5.0) / 100.0, 0.50);
    double tienSauKM = tien * (1.0 - phanTramKM);
    return tienSauKM + tienSauKM * 0.1; // + 10% VAT
}

string KhachHangThanThiet::loaiKhachHang() {
    return "B";
}

//  KHÁCH HÀNG ĐẶC BIỆT (C)
void KhachHangDacBiet::nhap() {
    cout << " Nhap Khach Hang Dac Biet (Loai C) \n";
    KhachHang::nhap();
}

void KhachHangDacBiet::xuat() {
    cout << "[Loai C] ";
    KhachHang::xuat();
    cout << "  Thanh tien: " << (long long)tinhTien() << " VND\n";
}

double KhachHangDacBiet::tinhTien() {
    double tien = soLuongHang * donGiaHang;
    double tienSauGiam = tien * 0.50; // Giảm 50%
    return tienSauGiam + tienSauGiam * 0.1; // + 10% VAT
}

string KhachHangDacBiet::loaiKhachHang() {
    return "C";
}

//  CÔNG TY XYZ
CongTyXYZ::~CongTyXYZ() {
    for (KhachHang* kh : danhSach) {
        delete kh;
    }
    danhSach.clear();
}

void CongTyXYZ::nhapDanhSach() {
    int x, y, z;
    cout << "Nhap so luong Khach hang Binh thuong (Loai A) x = ";
    cin >> x;
    cout << "Nhap so luong Khach hang Than thiet (Loai B) y = ";
    cin >> y;
    cout << "Nhap so luong Khach hang Dac biet (Loai C) z = ";
    cin >> z;

    cout << "\n TIEN HANH NHAP DU LIEU \n";
    for (int i = 0; i < x; i++) {
        KhachHang* kh = new KhachHangBinhThuong();
        kh->nhap();
        danhSach.push_back(kh);
    }
    for (int i = 0; i < y; i++) {
        KhachHang* kh = new KhachHangThanThiet();
        kh->nhap();
        danhSach.push_back(kh);
    }
    for (int i = 0; i < z; i++) {
        KhachHang* kh = new KhachHangDacBiet();
        kh->nhap();
        danhSach.push_back(kh);
    }
}

void CongTyXYZ::xuatDanhSach() {
    cout << "\n DANH SACH KHACH HANG & SO TIEN PHAI TRA \n";
    if (danhSach.empty()) {
        cout << "Danh sach hien tai dang trong!\n";
        return;
    }
    for (KhachHang* kh : danhSach) {
        kh->xuat();
    }
}

void CongTyXYZ::thongKeTongDoanhThu() {
    double tong = 0;
    for (KhachHang* kh : danhSach) {
        tong += kh->tinhTien();
    }
    cout << "\n TONG DOANH THU CONG TY \n";
    cout << "-> Tong so tien thu duoc: " << (long long)tong << " VND\n";
}
