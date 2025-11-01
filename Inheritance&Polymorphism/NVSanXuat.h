#pragma once
#include "NhanVien.h"

class NVSanXuat : public NhanVien {
protected: 
	int SoSP; 
public: 
	// override 
	void Nhap();
	long long TinhLuong();
};