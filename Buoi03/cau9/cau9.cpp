// cau9.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
-Người viết: Nguyễn Hoàng Gia Bảo
-MSSV: 25AD11003
-Ngày cập nhật cuối: 2/2/2026
-Đề : Giải PT ax+b=0
*/

#include <iostream>
using namespace std;

int main()
{
    double a, b;
    cout << "Nhap a b: ";
    cin >> a >> b;

    if (a == 0) {
        if (b == 0)
            cout << "Phuong trinh vo so nghiem";
        else
            cout << "Phuong trinh vo nghiem";
    }
    else {
        cout << "Nghiem x = " << -b / a;
    }

    return 0;
}

