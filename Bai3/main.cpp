#include "Bai3.h"

int main() {
    TruongDaiHoc uit;
    int choice;

    do {
        cout << "\n HE THONG QUAN LY SINH VIEN \n";
        cout << "1. Nhap danh sach sinh vien\n";
        cout << "2. Xuat danh sach sinh vien\n";
        cout << "3. Xuat DS sinh vien du dieu kien tot nghiep\n";
        cout << "4. Xuat DS sinh vien khong du dieu kien\n";
        cout << "5. Tim SV Dai hoc co DTB cao nhat\n";
        cout << "6. Tim SV Cao dang co DTB cao nhat\n";
        cout << "7. Thong ke so luong rot tot nghiep\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "Chon chuc nang: ";
        cin >> choice;

        switch (choice) {
            case 1: uit.nhapDanhSach(); break;
            case 2: uit.xuatDanhSach(); break;
            case 3: uit.xuatDSSV_DuDieuKien(); break;
            case 4: uit.xuatDSSV_KhongDuDieuKien(); break;
            case 5: uit.timSVDaiHoc_DTBCaoNhat(); break;
            case 6: uit.timSVCaoDang_DTBCaoNhat(); break;
            case 7: uit.thongKeKhongDuDieuKien(); break;
            case 0: cout << "Dang thoat chuong trinh...\n"; break;
            default: cout << "Lua chon khong hop le!\n"; break;
        }
    } while (choice != 0);

    return 0;
}
