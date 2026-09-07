// Buoi4.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
- Người viết: Nguyễn Hoàng Gia Bảo
- MSSV : 23AD11003
- Ngày cập nhật cuối: 27/01/2026
- Công dụng: Buổi số 4.1: so sánh lệnh nhập scanf và cin
*/

#include "stdafx.h"
#include <stdio.h>    // dùng printf, scanf
#include <conio.h>    // dùng gets

int main()
{
   Khai báo biến ---> chưa có giá trị
   int a, b, c;
   float x, y, z;
   Dùng lệnh scanf để nhập liệu
   scanf_s("%", &a);          // Nhập giá trị cho biến a
   scanf_s("f%f%", &x, &y)    // Nhập giá trị cho 2 biến x,y
    return 0;
}

