// ĐỀ THI 2017-2018 CÂU 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
- Người viết: Nguyễn Hoàng Gia Bảo
- MSSV : 23AD11003
- Ngày cập nhật cuối: 15/03/2026
Cong dung: Nhap ma tran d x c va tim phan tu co nhieu uoc so duong nhat tren moi dong
*/

#include <iostream>
#include <conio.h>

using namespace std;

#define MAX 20

//Khai bao cac ham
void MatrixInput(int m[][MAX], int d, int c);
void MatrixOutput(int m[][MAX], int d, int c);
int DemUoc(int n);
void TimPhanTuNhieuUocNhatMoiDong(int m[][MAX], int d, int c);

int main()
{
    int a[MAX][MAX];
    int d, c;

    //Nhap kich thuoc ma tran
    cout << "Nhap so dong: ";
    cin >> d;

    cout << "Nhap so cot: ";
    cin >> c;

    //Nhap ma tran
    MatrixInput(a, d, c);

    //In ma tran
    cout << "\nMa tran vua nhap:\n";
    MatrixOutput(a, d, c);

    //Tim phan tu co nhieu uoc nhat tren moi dong
    TimPhanTuNhieuUocNhatMoiDong(a, d, c);

    cout << "Nhan phim ESC de thoat...";
    while (_getch() != 27);

    return 0;
}

/////////////////////////////////////////////////////
//Ham nhap ma tran
void MatrixInput(int m[][MAX], int d, int c)
{
    for (int i = 0; i < d; i++)
        for (int j = 0; j < c; j++)
        {
            cout << "m[" << i << "][" << j << "] = ";
            cin >> m[i][j];
        }
}

/////////////////////////////////////////////////////
//Ham in ma tran
void MatrixOutput(int m[][MAX], int d, int c)
{
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout.width(5);
            cout << m[i][j];
        }
        cout << endl;
    }
}

/////////////////////////////////////////////////////
//Ham dem so uoc duong cua mot so
int DemUoc(int n)
{
    int dem = 0;

    if (n < 0) n = -n;

    for (int i = 1; i <= n; i++)
        if (n % i == 0)
            dem++;

    return dem;
}

/////////////////////////////////////////////////////
//Tim phan tu co nhieu uoc so nhat tren moi dong
void TimPhanTuNhieuUocNhatMoiDong(int m[][MAX], int d, int c)
{
    for (int i = 0; i < d; i++)
    {
        int maxUoc = DemUoc(m[i][0]);
        int value = m[i][0];

        for (int j = 1; j < c; j++)
        {
            int soUoc = DemUoc(m[i][j]);

            if (soUoc > maxUoc)
            {
                maxUoc = soUoc;
                value = m[i][j];
            }
        }

        cout << "Dong " << i << ": "
            << value << " (co " << maxUoc << " uoc)" << endl;
    }
}