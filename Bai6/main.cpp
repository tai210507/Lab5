#include "Bai6.h"

int main() {
    CongTyXYZ congTy;
    int choice;

    do {
        cout << "\n HE THONG QUAN LY CONG TY XYZ \n";
        cout << "1. Nhap danh sach 3 loai khach hang\n";
        cout << "2. Xuat danh sach khach hang & So tien moi nguoi\n";
        cout << "3. Thong ke tong doanh thu\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "Chon chuc nang: ";
        cin >> choice;

        switch (choice) {
            case 1:
                congTy.nhapDanhSach();
                break;
            case 2:
                congTy.xuatDanhSach();
                break;
            case 3:
                congTy.thongKeTongDoanhThu();
                break;
            case 0:
                cout << "Dang thoat chuong trinh...\n";
                break;
            default:
                cout << "Lua chon khong hop le!\n";
                break;
        }
    } while (choice != 0);

    return 0;
}
