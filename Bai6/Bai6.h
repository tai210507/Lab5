#ifndef BAI6_H
#define BAI6_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Để dùng std::max

using namespace std;

//  LỚP TRỪU TƯỢNG: KHÁCH HÀNG
class KhachHang {
protected:
    string hoTen;
    int soLuongHang;
    double donGiaHang;

public:
    KhachHang();
    virtual ~KhachHang();

    virtual void nhap();
    virtual void xuat();

    virtual double tinhTien() = 0;
    virtual string loaiKhachHang() = 0;
};

//  LỚP CON: KHÁCH HÀNG BÌNH THƯỜNG (Loại A)
class KhachHangBinhThuong : public KhachHang {
public:
    void nhap() override;
    void xuat() override;
    double tinhTien() override;
    string loaiKhachHang() override;
};

//  LỚP CON: KHÁCH HÀNG THÂN THIẾT (Loại B)
class KhachHangThanThiet : public KhachHang {
private:
    int soNamThanThiet;

public:
    void nhap() override;
    void xuat() override;
    double tinhTien() override;
    string loaiKhachHang() override;
};

//  LỚP CON: KHÁCH HÀNG ĐẶC BIỆT (Loại C)
class KhachHangDacBiet : public KhachHang {
public:
    void nhap() override;
    void xuat() override;
    double tinhTien() override;
    string loaiKhachHang() override;
};

//  LỚP QUẢN LÝ: CÔNG TY XYZ
class CongTyXYZ {
private:
    vector<KhachHang*> danhSach;

public:
    ~CongTyXYZ();

    void nhapDanhSach();
    void xuatDanhSach();
    void thongKeTongDoanhThu();
};

#endif
