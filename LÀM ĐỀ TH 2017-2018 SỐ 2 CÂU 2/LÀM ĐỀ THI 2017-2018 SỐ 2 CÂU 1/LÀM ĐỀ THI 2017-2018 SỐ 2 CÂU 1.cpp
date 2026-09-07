// LÀM ĐỀ THI 2017-2018 SỐ 2 CÂU 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
-Người làm: Nguyễn Hoàng Gia Bảo
-MSSV: 25AD11003
-Ngày sinh: 11/02/2007
-Ngày cập nhật: 16/03/2026
-Công dụng: Câu 1 đề kiểm tra giữa kì 2017-2018 SỐ 2
Câu 1: (3 điểm) Hãy viết chương trình thực hiện các công việc sau:
    a) (1.5đ) Nhập từ bàn phím 2 số nguyên K và N thỏa điều kiện 1 ≤ K ≤ 9 và
1 ≤ N ≤ 9*K . Nếu không thỏa thì yêu cầu nhập lại cho đến khi thỏa mới thôi.
    b) (1.5đ) Tìm và in ra màn hình số nguyên lớn nhất có K chữ số và tổng các chữ số của số đó đúng bằng N.
VD:	K = 1, N = 8  8
    K = 3, N = 1  100
    K = 4, N = 30  9993
*/

#include <iostream>
using namespace std;

int main()
{
    //Câu 1a
    int K, N;
    do
    {
        cout << "Nhap K: ";
        cin >> K;
        cout << "Nhap N: ";
        cin >> N;
    } while (K < 1 || K > 9 || N < 1 || N > 9 * K);
    //Câu 1b
    int a[10];

    // Tìm số lớn nhất
    for (int i = 0; i < K; i++)
    {
        if (N >= 9)
        {
            a[i] = 9;
            N = N - 9;
        }
        else
        {
            a[i] = N;
            N = 0;
        }
    }

    // In kết quả
    cout << "So lon nhat: ";
    for (int i = 0; i < K; i++)
        cout << a[i];

    return 0;
}



