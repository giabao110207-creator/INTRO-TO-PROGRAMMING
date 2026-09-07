// ĐỀ THI 2015-2016.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
- Người viết: Nguyễn Hoàng Gia Bảo
- MSSV : 23AD11003
- Ngày cập nhật cuối: 08/03/2026
- Công dụng:Ôn tập
*/


#include <iostream>
#include <cmath>
using namespace std;

//CÂU 1
// Kiểm tra số nguyên tố 
bool ktnt(int k) {
    if (k < 2) return false;
    for (int i = 2; i <= sqrt(k); i++)
        if (k % i == 0) return false;
    return true;
}

int main()
{
    int N;

    // Câu 1a
    do {
        cout << "Nhap N: ";
        cin >> N;
    } while (!ktnt(N));

    // Câu 1b
    int i = N + 1;
    while (!ktnt(i))
        i++;

    cout << "So nguyen to tiep theo: " << i;

    return 0;
}


