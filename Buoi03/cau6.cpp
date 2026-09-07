// cau6.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
-Người viết: Nguyễn Hoàng Gia Bảo
-MSSV: 25AD11003
-Ngày cập nhật cuối: 2/2/2026
-Đề : Nhập vào 3 số a, b, c. Tìm và xuất ra màn hình số lớn nhì.
*/

#include <iostream>
using namespace std;

int main()
{
    double a, b, c;
    cout << "Nhap a b c: ";
    cin >> a >> b >> c;

    double max, second;

    if (a >= b && a >= c) {
        max = a;
        second = (b > c) ? b : c;
    }
    else if (b >= a && b >= c) {
        max = b;
        second = (a > c) ? a : c;
    }
    else {
        max = c;
        second = (a > b) ? a : b;
    }

    cout << "So lon nhi la: " << second;
    return 0;
}

