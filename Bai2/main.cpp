#include "Bai2.h"

int main() {
    vector<GiaoDich*> danhSach;
    int choice;

    do {
        cout << "\n QUAN LY GIAO DICH VAKALAND \n";
        cout << "1. Them giao dich Dat\n";
        cout << "2. Them giao dich Nha Pho\n";
        cout << "3. Them giao dich Chung Cu\n";
        cout << "4. Thong ke so luong tung loai giao dich\n";
        cout << "5. Tinh trung binh thanh tien Chung Cu\n";
        cout << "6. Tim giao dich Nha Pho co thanh tien cao nhat\n";
        cout << "7. Xuat giao dich trong thang 12/2024\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "Chon chuc nang: ";
        cin >> choice;

        if (choice == 1) {
            GiaoDich* gd = new GiaoDichDat();
            gd->nhap();
            danhSach.push_back(gd);
        }
        else if (choice == 2) {
            GiaoDich* gd = new GiaoDichNhaPho();
            gd->nhap();
            danhSach.push_back(gd);
        }
        else if (choice == 3) {
            GiaoDich* gd = new GiaoDichChungCu();
            gd->nhap();
            danhSach.push_back(gd);
        }
        else if (choice == 4) {
            int demDat = 0, demNhaPho = 0, demChungCu = 0;
            for (GiaoDich* gd : danhSach) {
                if (gd->loaiGiaoDich() == "Dat") demDat++;
                else if (gd->loaiGiaoDich() == "NhaPho") demNhaPho++;
                else if (gd->loaiGiaoDich() == "ChungCu") demChungCu++;
            }
            cout << "\n THONG KE SO LUONG \n";
            cout << "Giao dich Dat: " << demDat << endl;
            cout << "Giao dich Nha Pho: " << demNhaPho << endl;
            cout << "Giao dich Chung Cu: " << demChungCu << endl;
        }
        else if (choice == 5) {
            double tongTienCC = 0;
            int demCC = 0;
            for (GiaoDich* gd : danhSach) {
                if (gd->loaiGiaoDich() == "ChungCu") {
                    tongTienCC += gd->tinhThanhTien();
                    demCC++;
                }
            }
            if (demCC > 0) {
                cout << "\nTrung binh thanh tien Chung Cu: " << (long long)(tongTienCC / demCC) << " VND\n";
            } else {
                cout << "\nKhong co giao dich Chung Cu nao!\n";
            }
        }
        else if (choice == 6) {
            GiaoDich* nhaPhoMax = nullptr;
            for (GiaoDich* gd : danhSach) {
                if (gd->loaiGiaoDich() == "NhaPho") {
                    if (nhaPhoMax == nullptr || gd->tinhThanhTien() > nhaPhoMax->tinhThanhTien()) {
                        nhaPhoMax = gd;
                    }
                }
            }
            cout << "\n NHA PHO CO THANH TIEN CAO NHAT \n";
            if (nhaPhoMax != nullptr) {
                nhaPhoMax->xuat();
            } else {
                cout << "Khong co giao dich Nha Pho nao!\n";
            }
        }
        else if (choice == 7) {
            cout << "\n DANH SACH GIAO DICH THANG 12 NAM 2024 \n";
            bool found = false;
            for (GiaoDich* gd : danhSach) {
                string ngay = gd->getNgayGiaoDich();
                // Giả định định dạng nhập là dd/mm/yyyy
                if (ngay.length() >= 7) {
                    string thangNam = ngay.substr(ngay.length() - 7); // Lấy "12/2024"
                    if (thangNam == "12/2024") {
                        gd->xuat();
                        found = true;
                    }
                }
            }
            if (!found) {
                cout << "Khong tim thay giao dich nao trong thoi gian nay.\n";
            }
        }

    } while (choice != 0);

    // Giải phóng bộ nhớ
    for (GiaoDich* gd : danhSach) {
        delete gd;
    }
    danhSach.clear();

    return 0;
}
