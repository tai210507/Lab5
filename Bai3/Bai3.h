#ifndef BAI3_H
#define BAI3_H

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

//  LỚP TRỪU TƯỢNG: SINH VIÊN
class SinhVien {
protected:
    string maSo;
    string hoTen;
    string diaChi;
    int tongTinChi;
    double diemTrungBinh;

public:
    SinhVien();
    virtual ~SinhVien();

    virtual void nhap();
    virtual void xuat();

    // Phương thức thuần ảo xét tốt nghiệp
    virtual bool xetTotNghiep() = 0;
    virtual string loaiSinhVien() = 0;

    double getDiemTrungBinh();
};

//  LỚP CON: SINH VIÊN CAO ĐẲNG
class SinhVienCaoDang : public SinhVien {
private:
    double diemThiTotNghiep;

public:
    void nhap() override;
    void xuat() override;
    bool xetTotNghiep() override;
    string loaiSinhVien() override;
};

//  LỚP CON: SINH VIÊN ĐẠI HỌC
class SinhVienDaiHoc : public SinhVien {
private:
    string tenLuanVan;
    double diemLuanVan;

public:
    void nhap() override;
    void xuat() override;
    bool xetTotNghiep() override;
    string loaiSinhVien() override;
};

//  LỚP QUẢN LÝ: TRƯỜNG ĐẠI HỌC
class TruongDaiHoc {
private:
    vector<SinhVien*> danhSach;

public:
    ~TruongDaiHoc();

    void nhapDanhSach();                // a. Nhập danh sách
    void xuatDanhSach();                // b. Xuất danh sách
    void xuatDSSV_DuDieuKien();         // c. Xuất DS đủ điều kiện tốt nghiệp
    void xuatDSSV_KhongDuDieuKien();    // d. Xuất DS không đủ điều kiện
    void timSVDaiHoc_DTBCaoNhat();      // e. SV Đại học có ĐTB cao nhất
    void timSVCaoDang_DTBCaoNhat();     // f. SV Cao đẳng có ĐTB cao nhất
    void thongKeKhongDuDieuKien();      // g. Thống kê số lượng rớt tốt nghiệp mỗi loại
};

#endif
