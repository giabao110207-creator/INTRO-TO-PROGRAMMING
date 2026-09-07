// cau4.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
-Người viết: Nguyễn Hoàng Gia Bảo
-MSSV: 25AD11003
-Ngày cập nhật cuối: 2/2/2026
-Đề : Nhập vào 4 số a, b, c, d. Tìm và xuất ra màn hình số lớn nhất.
*/

#include <iostream>
using namespace std;

int main()
{
    double a, b, c, d;
    cout << "Nhap a b c d: ";
    cin >> a >> b >> c >> d;

    double max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    if (d > max) max = d;

    cout << "So lon nhat la: " << max;
    return 0;
}


