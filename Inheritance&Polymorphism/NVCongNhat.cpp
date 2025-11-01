#include "NVCongNhat.h"

void NVCongNhat::Nhap()
{
    NhanVien::Nhap();
    cout << "Nhap so ngay di lam: ";
   // cin.ignore();
    cin >> SoNgayDiLam;
}

long long NVCongNhat::TinhLuong() {
    Luong = NhanVien::TinhLuong() + SoNgayDiLam * 300000;
    return Luong;
}