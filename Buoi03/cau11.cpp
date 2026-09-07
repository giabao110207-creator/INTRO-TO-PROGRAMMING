// cau11.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
-Người viết: Nguyễn Hoàng Gia Bảo
-MSSV: 25AD11003
-Ngày cập nhật cuối: 2/2/2026
-Đề : Giải PT ax4+bx2+c=0
*/

#include <iostream>
using namespace std;

int main()
{
    double a, b, c;
    cout << "Nhap a b c: ";
    cin >> a >> b >> c;

    if (a == 0) {
        cout << "Khong phai phuong trinh bac 4";
        return 0;
    }

    double delta = b * b - 4 * a * c;

    if (delta < 0) {
        cout << "Vo nghiem";
    }
    else {
        double t1 = (-b + sqrt(delta)) / (2 * a);
        double t2 = (-b - sqrt(delta)) / (2 * a);

        bool found = false;

        if (t1 >= 0) {
            cout << "x = " << sqrt(t1) << " va x = " << -sqrt(t1) << endl;
            found = true;
        }
        if (t2 >= 0 && t2 != t1) {
            cout << "x = " << sqrt(t2) << " va x = " << -sqrt(t2) << endl;
            found = true;
        }

        if (!found)
            cout << "Vo nghiem";
    }

    return 0;
}

