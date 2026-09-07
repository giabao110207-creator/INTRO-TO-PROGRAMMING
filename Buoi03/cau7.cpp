// cau7.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
-Người viết: Nguyễn Hoàng Gia Bảo
-MSSV: 25AD11003
-Ngày cập nhật cuối: 2/2/2026
-Đề : Nhập vào 3 số a, b, c. Kiểm tra đó có phải là 3 cạnh của 1 tam giác hay không?
*/

#include <iostream>
using namespace std;

int main()
{
    double a, b, c;
    cout << "Nhap 3 canh: ";
    cin >> a >> b >> c;

    if (a + b > c && a + c > b && b + c > a)
        cout << "Day la 3 canh cua mot tam giac";
    else
        cout << "Khong phai tam giac";

    return 0;
}

