// cau10.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
-Người viết: Nguyễn Hoàng Gia Bảo
-MSSV: 25AD11003
-Ngày cập nhật cuối: 2/2/2026
-Đề : Giải PT ax2+bx+c=0
*/

#include <iostream>
using namespace std;

int main()
{
    double a, b, c;
    cout << "Nhap a b c: ";
    cin >> a >> b >> c;

    if (a == 0) {
        if (b == 0) {
            if (c == 0)
                cout << "Vo so nghiem";
            else
                cout << "Vo nghiem";
        }
        else {
            cout << "Nghiem x = " << -c / b;
        }
    }
    else {
        double delta = b * b - 4 * a * c;
        if (delta < 0)
            cout << "Vo nghiem";
        else if (delta == 0)
            cout << "Nghiem kep x = " << -b / (2 * a);
        else {
            cout << "x1 = " << (-b + sqrt(delta)) / (2 * a) << endl;
            cout << "x2 = " << (-b - sqrt(delta)) / (2 * a);
        }
    }

    return 0;
}


