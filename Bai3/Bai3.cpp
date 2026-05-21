#include "Bai3.h"

//  LỚP SINH VIÊN
SinhVien::SinhVien() : maSo(""), hoTen(""), diaChi(""), tongTinChi(0), diemTrungBinh(0.0) {}
SinhVien::~SinhVien() {}

void SinhVien::nhap() {
    cout << "Nhap ma so SV: ";
    cin >> maSo;
    cin.ignore();
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);
    cout << "Nhap dia chi: ";
    getline(cin, diaChi);
    cout << "Nhap tong so tin chi: ";
    cin >> tongTinChi;
    cout << "Nhap diem trung binh: ";
    cin >> diemTrungBinh;
}

void SinhVien::xuat() {
    cout << "MSSV: " << maSo
         << "  Ho ten: " << hoTen
         << "  Dia chi: " << diaChi
         << "  Tin chi: " << tongTinChi
         << "  DTB: " << diemTrungBinh;
}

double SinhVien::getDiemTrungBinh() {
    return diemTrungBinh;
}

//  LỚP SINH VIÊN CAO ĐẲNG
void SinhVienCaoDang::nhap() {
    cout << " Nhap Sinh Vien Cao Dang " << endl;
    SinhVien::nhap();
    cout << "Nhap diem thi tot nghiep: ";
    cin >> diemThiTotNghiep;
}

void SinhVienCaoDang::xuat() {
    cout << "[CAO DANG] ";
    SinhVien::xuat();
    cout << "  Diem thi TN: " << diemThiTotNghiep
         << "  Trang thai: " << (xetTotNghiep() ? "Dat" : "Khong dat") << endl;
}

bool SinhVienCaoDang::xetTotNghiep() {
    return (tongTinChi >= 120 && diemTrungBinh >= 5.0 && diemThiTotNghiep >= 5.0);
}

string SinhVienCaoDang::loaiSinhVien() {
    return "CaoDang";
}

//  LỚP SINH VIÊN ĐẠI HỌC
void SinhVienDaiHoc::nhap() {
    cout << " Nhap Sinh Vien Dai Hoc " << endl;
    SinhVien::nhap();
    cin.ignore();
    cout << "Nhap ten luan van: ";
    getline(cin, tenLuanVan);
    cout << "Nhap diem luan van: ";
    cin >> diemLuanVan;
}

void SinhVienDaiHoc::xuat() {
    cout << "[DAI HOC] ";
    SinhVien::xuat();
    cout << "  Ten LV: " << tenLuanVan
         << "  Diem LV: " << diemLuanVan
         << "  Trang thai: " << (xetTotNghiep() ? "Dat" : "Khong dat") << endl;
}

bool SinhVienDaiHoc::xetTotNghiep() {
    return (tongTinChi >= 170 && diemTrungBinh >= 5.0 && diemLuanVan >= 5.0);
}

string SinhVienDaiHoc::loaiSinhVien() {
    return "DaiHoc";
}

//  LỚP TRƯỜNG ĐẠI HỌC
TruongDaiHoc::~TruongDaiHoc() {
    for (SinhVien* sv : danhSach) {
        delete sv;
    }
    danhSach.clear();
}

void TruongDaiHoc::nhapDanhSach() {
    int n;
    cout << "Nhap so luong sinh vien can them: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int loai;
        cout << "\nChon he dao tao (1: Cao dang, 2: Dai hoc): ";
        cin >> loai;

        SinhVien* sv = nullptr;
        if (loai == 1) {
            sv = new SinhVienCaoDang();
        } else if (loai == 2) {
            sv = new SinhVienDaiHoc();
        } else {
            cout << "Lua chon khong hop le!" << endl;
            i--;
            continue;
        }
        sv->nhap();
        danhSach.push_back(sv);
    }
}

void TruongDaiHoc::xuatDanhSach() {
    cout << "\n DANH SACH SINH VIEN \n";
    for (SinhVien* sv : danhSach) {
        sv->xuat();
    }
}

void TruongDaiHoc::xuatDSSV_DuDieuKien() {
    cout << "\n DANH SACH SINH VIEN DU DIEU KIEN TOT NGHIEP \n";
    bool found = false;
    for (SinhVien* sv : danhSach) {
        if (sv->xetTotNghiep()) {
            sv->xuat();
            found = true;
        }
    }
    if (!found) cout << "Khong co sinh vien nao du dieu kien.\n";
}

void TruongDaiHoc::xuatDSSV_KhongDuDieuKien() {
    cout << "\n DANH SACH SINH VIEN KHONG DU DIEU KIEN TOT NGHIEP \n";
    bool found = false;
    for (SinhVien* sv : danhSach) {
        if (!sv->xetTotNghiep()) {
            sv->xuat();
            found = true;
        }
    }
    if (!found) cout << "Tat ca sinh vien deu du dieu kien.\n";
}

void TruongDaiHoc::timSVDaiHoc_DTBCaoNhat() {
    SinhVien* maxSV = nullptr;
    for (SinhVien* sv : danhSach) {
        if (sv->loaiSinhVien() == "DaiHoc") {
            if (maxSV == nullptr || sv->getDiemTrungBinh() > maxSV->getDiemTrungBinh()) {
                maxSV = sv;
            }
        }
    }
    cout << "\n SINH VIEN DAI HOC CO DTB CAO NHAT \n";
    if (maxSV != nullptr) maxSV->xuat();
    else cout << "Khong co sinh vien Dai hoc nao trong danh sach.\n";
}

void TruongDaiHoc::timSVCaoDang_DTBCaoNhat() {
    SinhVien* maxSV = nullptr;
    for (SinhVien* sv : danhSach) {
        if (sv->loaiSinhVien() == "CaoDang") {
            if (maxSV == nullptr || sv->getDiemTrungBinh() > maxSV->getDiemTrungBinh()) {
                maxSV = sv;
            }
        }
    }
    cout << "\n SINH VIEN CAO DANG CO DTB CAO NHAT \n";
    if (maxSV != nullptr) maxSV->xuat();
    else cout << "Khong co sinh vien Cao dang nao trong danh sach.\n";
}

void TruongDaiHoc::thongKeKhongDuDieuKien() {
    int rotCaoDang = 0, rotDaiHoc = 0;
    for (SinhVien* sv : danhSach) {
        if (!sv->xetTotNghiep()) {
            if (sv->loaiSinhVien() == "CaoDang") rotCaoDang++;
            else if (sv->loaiSinhVien() == "DaiHoc") rotDaiHoc++;
        }
    }
    cout << "\n THONG KE SINH VIEN KHONG DU DIEU KIEN \n";
    cout << "He Cao dang: " << rotCaoDang << " sinh vien.\n";
    cout << "He Dai hoc: " << rotDaiHoc << " sinh vien.\n";
}
