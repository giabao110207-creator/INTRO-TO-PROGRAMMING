// ĐỀ THI 2017-2018 SỐ 3 CÂU 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Tác giả: Nguyễn Hoàng Gia Bảo
Mã số: 25AD11003
Ngày cập nhật cuối: 10/03/2026
Công dụng: ôn tập
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cout << "Nhap so phan tu N: ";
    cin >> n;

    int a[100];

    // a) Nhập và in mảng
    cout << "Nhap cac phan tu cua mang:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }

    cout << "Mang vua nhap: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << endl;

    // b) Kiểm tra phần tử thuộc đoạn [a,b]
    int x, y;
    cout << "Nhap a va b: ";
    cin >> x >> y;

    bool check = true;

    for (int i = 0; i < n; i++)
    {
        if (a[i] < x || a[i] > y)
        {
            check = false;
            break;
        }
    }

    if (check)
        cout << "Tat ca phan tu deu thuoc doan [" << x << "," << y << "]\n";
    else
        cout << "Khong phai tat ca phan tu deu thuoc doan\n";

    // c) Phần tử gần trung bình cộng nhất
    float sum = 0;

    for (int i = 0; i < n; i++)
        sum += a[i];

    float tbc = sum / n;

    int gan = a[0];
    float minDiff = abs(a[0] - tbc);

    for (int i = 1; i < n; i++)
    {
        if (abs(a[i] - tbc) < minDiff)
        {
            minDiff = abs(a[i] - tbc);
            gan = a[i];
        }
    }

    cout << "Phan tu gan trung binh cong nhat: " << gan << endl;

    // d) Xóa phần tử chia hết cho K
    int k;
    cout << "Nhap K: ";
    cin >> k;

    int i = 0;
    while (i < n)
    {
        if (a[i] % k == 0)
        {
            for (int j = i; j < n - 1; j++)
                a[j] = a[j + 1];
            n--;
        }
        else
            i++;
    }

    cout << "Mang sau khi xoa: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}



