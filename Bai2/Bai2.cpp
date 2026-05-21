#include "Bai2.h"

//  GIAO DỊCH CHUNG
GiaoDich::GiaoDich() : maGiaoDich(""), ngayGiaoDich(""), donGia(0), dienTich(0) {}
GiaoDich::~GiaoDich() {}

void GiaoDich::nhap() {
    cout << "Nhap ma giao dich: ";
    cin.ignore();
    getline(cin, maGiaoDich);
    cout << "Nhap ngay giao dich (dd/mm/yyyy): ";
    getline(cin, ngayGiaoDich);
    cout << "Nhap don gia: ";
    cin >> donGia;
    cout << "Nhap dien tich: ";
    cin >> dienTich;
}

void GiaoDich::xuat() {
    cout << "Ma GD: " << maGiaoDich
         << "  Ngay: " << ngayGiaoDich
         << "  Don gia: " << (long long)donGia
         << "  Dien tich: " << dienTich;
}

string GiaoDich::getNgayGiaoDich() {
    return ngayGiaoDich;
}

//  GIAO DỊCH ĐẤT
void GiaoDichDat::nhap() {
    cout << " Nhap Giao Dich Dat " << endl;
    GiaoDich::nhap();
    cout << "Nhap loai dat (A/B/C): ";
    cin >> loaiDat;
}

void GiaoDichDat::xuat() {
    cout << "[DAT] ";
    GiaoDich::xuat();
    cout << "  Loai dat: " << loaiDat
         << "  Thanh tien: " << (long long)tinhThanhTien() << endl;
}

double GiaoDichDat::tinhThanhTien() {
    if (loaiDat == "A" || loaiDat == "a") {
        return dienTich * donGia * 1.5;
    }
    // Loại B, C
    return dienTich * donGia;
}

string GiaoDichDat::loaiGiaoDich() {
    return "Dat";
}

//  GIAO DỊCH NHÀ PHỐ
void GiaoDichNhaPho::nhap() {
    cout << " Nhap Giao Dich Nha Pho " << endl;
    GiaoDich::nhap();
    cout << "Nhap loai nha (cao cap / thuong): ";
    cin.ignore();
    getline(cin, loaiNha);
    cout << "Nhap dia chi: ";
    getline(cin, diaChi);
}

void GiaoDichNhaPho::xuat() {
    cout << "[NHA PHO] ";
    GiaoDich::xuat();
    cout << "  Loai nha: " << loaiNha
         << "  Dia chi: " << diaChi
         << "  Thanh tien: " << (long long)tinhThanhTien() << endl;
}

double GiaoDichNhaPho::tinhThanhTien() {
    if (loaiNha == "cao cap") {
        return dienTich * donGia;
    }
    // Loại thường
    return dienTich * donGia * 0.9;
}

string GiaoDichNhaPho::loaiGiaoDich() {
    return "NhaPho";
}

//  GIAO DỊCH CHUNG CƯ
void GiaoDichChungCu::nhap() {
    cout << " Nhap Giao Dich Chung Cu " << endl;
    GiaoDich::nhap();
    cout << "Nhap ma can: ";
    cin >> maCan;
    cout << "Nhap vi tri tang: ";
    cin >> viTriTang;
}

void GiaoDichChungCu::xuat() {
    cout << "[CHUNG CU] ";
    GiaoDich::xuat();
    cout << "  Ma can: " << maCan
         << "  Tang: " << viTriTang
         << "  Thanh tien: " << (long long)tinhThanhTien() << endl;
}

double GiaoDichChungCu::tinhThanhTien() {
    if (viTriTang == 1) {
        return dienTich * donGia * 2;
    } else if (viTriTang >= 15) {
        return dienTich * donGia * 1.2;
    }
    // Các tầng còn lại
    return dienTich * donGia;
}

string GiaoDichChungCu::loaiGiaoDich() {
    return "ChungCu";
}
