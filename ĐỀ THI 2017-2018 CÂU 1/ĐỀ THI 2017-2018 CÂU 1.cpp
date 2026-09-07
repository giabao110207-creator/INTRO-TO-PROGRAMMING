// ĐỀ THI 2017-2018 CÂU 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
- Người viết: Nguyễn Hoàng Gia Bảo
- MSSV : 25AD11003
- Ngày sinh: 11/02/2007
- Ngày cập nhật cuối: 16/03/2026
- Công dụng: Đề kiểm tra 2017-2018 câu 1
Câu 1: (3 điểm) Hãy viết chương trình thực hiện các công việc sau:
    a) (1.5đ) Nhập từ bàn phím 3 số nguyên a, b, c thỏa điều kiện 1 ≤ a, b, c ≤ 13. Nếu không thỏa thì yêu cầu nhập lại cho đến khi thỏa mới thôi.
    b) (1.5đ) Kiểm tra xem 3 số đã nhập có lập thành 1 “sảnh” 3 cây của bài tiến lên hay không. Chú thích: 1 = A, 11 = J, 12 = Q, 13 = K. Sảnh 3 gồm (345, 456, 567, 678, 789, 8910, 910J, 10JQ, JQK, QKA)
*/

#include <iostream>
using namespace std;
#include <algorithm>

int main()
{
    int a, b, c;

    // Nhập và kiểm tra điều kiện
    do {
        cout << "Nhap a: ";
        cin >> a;
    } while (a < 1 || a > 13);

    do {
        cout << "Nhap b: ";
        cin >> b;
    } while (b < 1 || b > 13);

    do {
        cout << "Nhap c: ";
        cin >> c;
    } while (c < 1 || c > 13);
    // Sắp xếp tăng dần
    int arr[3] = { a, b, c };
    sort(arr, arr + 3);
    // Kiểm tra sảnh
    if ((arr[1] == arr[0] + 1 && arr[2] == arr[1] + 1) ||
        (arr[0] == 1 && arr[1] == 12 && arr[2] == 13)) {
        cout << "Day la sanh 3 cay." << endl;
    }
    else {
        cout << "Khong phai sanh 3 cay." << endl;
    }

}
