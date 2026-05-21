#include "Bai4.h"

int main() {
    CongTyHoanCau congTy;
    int choice;

    do {
        cout << "\n HE THONG QUAN LY CONG TY HOAN CAU \n";
        cout << "1. Nhap danh sach nhan vien\n";
        cout << "2. Xuat danh sach nhan vien\n";
        cout << "3. Xuat nhan vien co luong thap hon muc trung binh\n";
        cout << "4. Xuat thong tin nhan vien co luong cao nhat\n";
        cout << "5. Xuat thong tin nhan vien co luong thap nhat\n";
        cout << "6. Xuat Lap Trinh Vien co luong cao nhat\n";
        cout << "7. Xuat Kiem Chung Vien co luong thap nhat\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "Chon chuc nang: ";
        cin >> choice;

        switch (choice) {
            case 1: congTy.nhapDanhSach(); break;
            case 2: congTy.xuatDanhSach(); break;
            case 3: congTy.xuatNV_LuongThapHonTB(); break;
            case 4: congTy.xuatNV_LuongCaoNhat(); break;
            case 5: congTy.xuatNV_LuongThapNhat(); break;
            case 6: congTy.xuatLTV_LuongCaoNhat(); break;
            case 7: congTy.xuatKCV_LuongThapNhat(); break;
            case 0: cout << "Dang thoat chuong trinh...\n"; break;
            default: cout << "Lua chon khong hop le!\n"; break;
        }
    } while (choice != 0);

    return 0;
}
