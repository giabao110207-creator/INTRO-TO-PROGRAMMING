// ĐỀ THI 2017-2018 SỐ 3 CÂU 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Tác giả: Nguyễn Hoàng Gia Bảo
Mã số: 25AD11003
Ngày cập nhật cuối: 10/03/2026
Công dụng: ôn tập
*/

#include <iostream>
#include <cmath>
using namespace std;

bool laSoNguyenTo(int n);
int timMinNT(int n);
int timMaxNT(int n);

int main()
{
    int n;
    // a) Nhập n (1 ≤ n ≤ 8)
    do
    {
        cout << "Nhap n (1 <= n <= 8): ";
        cin >> n;

        if (n < 1 || n > 8)
            cout << "Nhap sai, vui long nhap lai!\n";

    } while (n < 1 || n > 8);

    // b) Tìm số nguyên tố nhỏ nhất và lớn nhất có n chữ số
    int minNT = timMinNT(n);
    int maxNT = timMaxNT(n);

    cout << "So nguyen to nho nhat co " << n << " chu so: " << minNT << endl;
    cout << "So nguyen to lon nhat co " << n << " chu so: " << maxNT << endl;

    return 0;
}

// Phần 4: Định nghĩa hàm

// Hàm kiểm tra số nguyên tố
bool laSoNguyenTo(int n)
{
    if (n < 2) return false;

    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;

    return true;
}

// Hàm tìm số nguyên tố nhỏ nhất có n chữ số
int timMinNT(int n)
{
    int start = pow(10, n - 1);
    int end = pow(10, n) - 1;

    for (int i = start; i <= end; i++)
        if (laSoNguyenTo(i))
            return i;
}

// Hàm tìm số nguyên tố lớn nhất có n chữ số
int timMaxNT(int n)
{
    int start = pow(10, n - 1);
    int end = pow(10, n) - 1;

    for (int i = end; i >= start; i--)
        if (laSoNguyenTo(i))
            return i;
}
