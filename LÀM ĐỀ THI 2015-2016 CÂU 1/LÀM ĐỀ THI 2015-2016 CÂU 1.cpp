// LÀM ĐỀ THI 2015-2016 CÂU 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
-Người làm: Nguyễn Hoàng Gia Bảo 
-MSSV: 25AD11003
-Ngày sinh: 11/02/2007
-Ngày cập nhật: 16/03/2026
-Công dụng: Câu 1 đề kiểm tra giữa kì 
Câu 1: (3 điểm) Hãy viết chương trình thực hiện các công việc sau:
    a) (1.5đ) Nhập từ bàn phím một số nguyên N thỏa điều kiện N là số nguyên tố. Nếu không thỏa thì yêu cầu nhập lại cho đến khi thỏa mới thôi.
    b) (1.5đ) Tìm và in ra màn hình số nguyên tố tiếp theo sau N (tức là số nguyên tố nhỏ nhất lớn hơn N).
*/

#include <iostream>
#include <cmath>
using namespace std;

//Hàm kiểm tra 1 số nguyên không có phai là số nguyên tố không 
bool ktnt(int k);


int main()
{
    //Câu 1a
    int n;
    do {
        cout << "Nhap 1 so nguyen to:";
        cin >> n;
    } while (ktnt(n) == false);
    //Câu 1b
    int i = n + 1;
    while (ktnt(i) == false)
        i++;
    cout << "So nguyen to tiep theo:" << i;

    return 0;

}

//Phần 4: Thân của các hàm/CT con tự xây dựng thêm

//Kiểm tra 1 số nguyên k có phải là số nguyên tố hay không
bool ktnt(int k) {
    if (k < 2)
        return false;
    double c = sqrt(k);
    for (int i = 2; i <= c; i++) {
        if (k % i == 0)
            return false;
    }
    return true;
}
