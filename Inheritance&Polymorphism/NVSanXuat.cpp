#include "NVSanXuat.h"

void NVSanXuat::Nhap() {
    // Option A: CORRECT
    NhanVien::Nhap();

    // // Option B: INCORRECT
    // cout<<"Nhap ma nhan vien: ";
    // getline(cin,Ma);
    // cout<<"Nhap ho ten nhan vien: ";
    // getline(cin,HoTen);
    // cout<<"Nhap dia chi:";
    // getline(cin,DiaChi);

    cout << "Nhap so san pham: ";
    //cin.ignore();
    cin >> SoSP;
}


long long NVSanXuat::TinhLuong() {
    Luong = NhanVien::TinhLuong() + SoSP * 1000;
    return Luong;
}