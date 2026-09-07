// cau8.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
-Người viết: Nguyễn Hoàng Gia Bảo
-MSSV: 25AD11003
-Ngày cập nhật cuối: 2/2/2026
-Đề : Nhập vào 3 cạnh a, b, c. Hỏi đó là tam giác gì? (đều, cân, vuông, thường, ko phải)
*/

#include <iostream>
using namespace std;

int main()
{
    double a, b, c;
    cout << "Nhap 3 canh: ";
    cin >> a >> b >> c;

    if (!(a + b > c && a + c > b && b + c > a)) {
        cout << "Khong phai tam giac";
    }
    else if (a == b && b == c) {
        cout << "Tam giac deu";
    }
    else if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a) {
        cout << "Tam giac vuong";
    }
    else if (a == b || a == c || b == c) {
        cout << "Tam giac can";
    }
    else {
        cout << "Tam giac thuong";
    }

    return 0;
}

