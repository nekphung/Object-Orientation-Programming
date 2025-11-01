#include "NhanVien.h"

void NhanVien::Nhap()
{
    cout << "Nhap ma nhan vien: ";
    getline(cin, Ma);
    cout << "Nhap ho ten nhan vien: ";
    getline(cin, HoTen);
    cout << "Nhap dia chi:";
    getline(cin, DiaChi);
    Luong = 0;
}


long long NhanVien::TinhLuong() {
    Luong = 0;
    return Luong;
}