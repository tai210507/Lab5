#include "Bai1.h"

int main() {
    vector<NhanVien*> danhSach;
    int n;

    cout << "Nhap so luong nhan vien can them: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int loaiNV;
        cout << "\nChon loai nhan vien (1: NVSX, 2: NVVP): ";
        cin >> loaiNV;

        NhanVien* nv = nullptr;
        if (loaiNV == 1) {
            nv = new NhanVienSanXuat();
        } else if (loaiNV == 2) {
            nv = new NhanVienVanPhong();
        } else {
            cout << "Lua chon khong hop le!" << endl;
            i--;
            continue;
        }

        nv->nhap();
        danhSach.push_back(nv);
    }


    cout << "\n DANH SACH NHAN VIEN \n";
    double tongLuong = 0;
    for (NhanVien* nv : danhSach) {
        nv->xuat();
        tongLuong += nv->getLuong();
    }
    cout << "-> Tong luong cong ty phai tra: " << (long long)tongLuong << " VND\n";

    NhanVien* nvsxMin = nullptr;
    for (NhanVien* nv : danhSach) {
        if (nv->loai() == "NVSX") {
            if (nvsxMin == nullptr || nv->getLuong() < nvsxMin->getLuong()) {
                nvsxMin = nv;
            }
        }
    }

    cout << "\n-> Nhan vien san xuat co luong thap nhat:\n";
    if (nvsxMin != nullptr) {
        nvsxMin->xuat();
    } else {
        cout << "Khong co nhan vien san xuat nao trong danh sach.\n";
    }

    NhanVien* nvvpOldest = nullptr;
    for (NhanVien* nv : danhSach) {
        if (nv->loai() == "NVVP") {
            if (nvvpOldest == nullptr || nv->getNamSinh() < nvvpOldest->getNamSinh()) {
                nvvpOldest = nv;
            }
        }
    }

    cout << "\n-> Nhan vien van phong co tuoi cao nhat:\n";
    if (nvvpOldest != nullptr) {
        nvvpOldest->xuat();
    } else {
        cout << "Khong co nhan vien van phong nao trong danh sach.\n";
    }

    for (NhanVien* nv : danhSach) {
        delete nv;
    }
    danhSach.clear();

    return 0;
}
