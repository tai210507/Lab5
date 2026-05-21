#ifndef BAI4_H
#define BAI4_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//  LỚP TRỪU TƯỢNG: NHÂN VIÊN
class NhanVien {
protected:
    string maNhanVien;
    string hoTen;
    int tuoi;
    string sdt;
    string email;
    double luongCoBan;

public:
    NhanVien();
    virtual ~NhanVien();

    virtual void nhap();
    virtual void xuat();

    // Phương thức thuần ảo
    virtual double tinhLuong() = 0;
    virtual string loaiNhanVien() = 0;

    double getLuong();
};

//  LỚP CON: LẬP TRÌNH VIÊN
class LapTrinhVien : public NhanVien {
private:
    int soGioOvertime;

public:
    void nhap() override;
    void xuat() override;
    double tinhLuong() override;
    string loaiNhanVien() override;
};

//  LỚP CON: KIỂM CHỨNG VIÊN
class KiemChungVien : public NhanVien {
private:
    int soLoiPhatHien;

public:
    void nhap() override;
    void xuat() override;
    double tinhLuong() override;
    string loaiNhanVien() override;
};

//  LỚP QUẢN LÝ: CÔNG TY HOÀN CẦU
class CongTyHoanCau {
private:
    vector<NhanVien*> danhSach;

public:
    ~CongTyHoanCau();

    void nhapDanhSach();                // a. Nhập danh sách
    void xuatDanhSach();                // b. Xuất danh sách
    double tinhLuongTrungBinh();        // Hàm hỗ trợ tính trung bình
    void xuatNV_LuongThapHonTB();       // c. Xuất NV lương thấp hơn TB
    void xuatNV_LuongCaoNhat();         // d. Xuất NV có lương cao nhất
    void xuatNV_LuongThapNhat();        // e. Xuất NV có lương thấp nhất
    void xuatLTV_LuongCaoNhat();        // f. Xuất Lập trình viên lương cao nhất
    void xuatKCV_LuongThapNhat();       // g. Xuất Kiểm chứng viên lương thấp nhất
};

#endif
