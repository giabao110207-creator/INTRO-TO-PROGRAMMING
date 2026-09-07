// ĐỀ THI 2017-2018 SỐ 3 CÂU 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Tác giả: Nguyễn Hoàng Gia Bảo
Mã số: 25AD11003
Ngày cập nhật cuối: 10/03/2026
Công dụng: ôn tập
*/


#include <iostream>
using namespace std;

int main()
{
    int N;
    int a[100][100];

    // a) Nhập ma trận
    cout << "Nhap N: ";
    cin >> N;

    cout << "Nhap ma tran:\n";
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> a[i][j];

    // In ma trận
    cout << "Ma tran vua nhap:\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }

    // b) Tìm giá trị lớn nhất trên mỗi dòng
    cout << "Gia tri lon nhat tren moi dong:\n";
    for (int i = 0; i < N; i++)
    {
        int max = a[i][0];

        for (int j = 1; j < N; j++)
        {
            if (a[i][j] > max)
                max = a[i][j];
        }

        cout << "Dong " << i + 1 << ": " << max << endl;
    }

    // c) Tìm chữ số xuất hiện nhiều nhất
    int dem[10] = { 0 };

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            int x = a[i][j];

            if (x < 0) x = -x; // phòng trường hợp số âm

            while (x > 0)
            {
                int d = x % 10;
                dem[d]++;
                x /= 10;
            }
        }

    int maxDem = dem[0];
    int so = 0;

    for (int i = 1; i < 10; i++)
    {
        if (dem[i] > maxDem)
        {
            maxDem = dem[i];
            so = i;
        }
    }

    cout << "Chu so xuat hien nhieu nhat: " << so << endl;

    return 0;
}

