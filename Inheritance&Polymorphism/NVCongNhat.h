#pragma once
#include "NhanVien.h"

class NVCongNhat : public NhanVien {
protected:
    int SoNgayDiLam;
public:
    // override
    void Nhap();
    long long TinhLuong();
};