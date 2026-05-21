#ifndef BAI1_H
#define BAI1_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class NhanVien {
protected:
    string hoTen;
    string ngaySinh;
    double luong;

public:
    NhanVien();
    virtual ~NhanVien();

    virtual void nhap();
    virtual void xuat();


    virtual double tinhLuong() = 0;
    virtual string loai() = 0;


    double getLuong();
    int getNamSinh();
};

class NhanVienSanXuat : public NhanVien {
private:
    int soSanPham;
    double luongCanBan;

public:
    void nhap() override;
    void xuat() override;
    double tinhLuong() override;
    string loai() override;
};

class NhanVienVanPhong : public NhanVien {
private:
    int soNgayLam;

public:
    void nhap() override;
    void xuat() override;
    double tinhLuong() override;
    string loai() override;
};

#endif
