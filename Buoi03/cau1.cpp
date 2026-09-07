// cau1.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
-Người viết: Nguyễn Hoàng Gia Bảo
-MSSV: 25AD11003
-Ngày cập nhật cuối: 2/2/2026
-Đề : Nhập vào 2 số a, b. Tìm số lớn nhất và xuất ra màn hình.
*/

#include <iostream>
using namespace std;

int main()
{
    double a, b;
    cout << "Nhap a: ";
    cin >> a;
    cout << "Nhap b: ";
    cin >> b;

    if (a > b)
        cout << "So lon nhat la: " << a;
    else
        cout << "So lon nhat la: " << b;
    
    return 0;
}

