#ifndef BAI2_H
#define BAI2_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class GiaoDich {
protected:
    string maGiaoDich;
    string ngayGiaoDich;
    double donGia;
    double dienTich;

public:
    GiaoDich();
    virtual ~GiaoDich();

    virtual void nhap();
    virtual void xuat();

    // Các phương thức thuần ảo
    virtual double tinhThanhTien() = 0;
    virtual string loaiGiaoDich() = 0;

    string getNgayGiaoDich();
};

//  LỚP CON: GIAO DỊCH ĐẤT
class GiaoDichDat : public GiaoDich {
private:
    string loaiDat; // "A", "B", "C"

public:
    void nhap() override;
    void xuat() override;
    double tinhThanhTien() override;
    string loaiGiaoDich() override;
};

//  LỚP CON: GIAO DỊCH NHÀ PHỐ
class GiaoDichNhaPho : public GiaoDich {
private:
    string loaiNha; // "cao cap", "thuong"
    string diaChi;

public:
    void nhap() override;
    void xuat() override;
    double tinhThanhTien() override;
    string loaiGiaoDich() override;
};

//  LỚP CON: GIAO DỊCH CĂN HỘ CHUNG CƯ
class GiaoDichChungCu : public GiaoDich {
private:
    string maCan;
    int viTriTang;

public:
    void nhap() override;
    void xuat() override;
    double tinhThanhTien() override;
    string loaiGiaoDich() override;
};

#endif
