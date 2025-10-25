#include <iostream>
#include <string>

using namespace std;

class PhanSo {
private:
    long long tu, mau;
public:
    PhanSo(): tu(0), mau(0) {}
    PhanSo(long long, long long);
    void toiGian();
    void hienThi();
};

PhanSo::PhanSo(long long tu, long long mau) {
    this->tu = tu;
    this->mau = mau;
}

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    else return gcd(b, a%b);
}

void PhanSo::toiGian() {
    long long ucln = gcd(tu, mau);
    tu /= ucln;
    mau /= ucln;
}

void PhanSo::hienThi() {
    cout << tu << "/" << mau << endl;
}

int main() {
    long long tu, mau; 
    cin >> tu >> mau;
    PhanSo ps(tu, mau);
    ps.toiGian();
    ps.hienThi();
    return 0;
}