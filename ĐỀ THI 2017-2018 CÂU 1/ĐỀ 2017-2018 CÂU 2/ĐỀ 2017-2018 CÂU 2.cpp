// ĐỀ 2017-2018 CÂU 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
- Người viết: Nguyễn Hoàng Gia Bảo
- MSSV : 25AD11003
- Ngày sinh : 11/02/2007
- Ngày cập nhật cuối: 16/03/2026
- Công dụng:Ôn tập
Câu 2: (4 điểm) Hãy viết chương trình thực hiện các công việc sau:
    a) (1đ) Nhập từ bàn phím và in ra màn hình 1 mảng số nguyên có N phần tử.
    b) (1đ) Nhập vào 2 số nguyên a và b. In ra màn hình những phần tử là ước số của a, đồng thời là bội số của b.
    c) (1đ) Tìm và in ra cặp phần tử có ước số chung lớn nhất lớn nhất.
VD: 	a	1	5	3	8	4	9
Cặp (8, 4) có USCLN = 4  lớn nhất trong các cặp
    d) (1đ) Nhập 1 số nguyên K; chèn K vào sau số chẵn đầu tiên của mảng, nếu mảng không có số chẵn thì thêm K vào cuối mảng; in mảng kết quả ra màn hình.
*/

#include <iostream>
using namespace std;

#define MAX 100

// Hàm nhập mảng
void NhapMang(int a[], int& n)
{
    cout << "Nhap so phan tu n: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}
//======================
// Hàm xuất mảng
void XuatMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}

//======================
// Hàm tìm UCLN
int UCLN(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

//======================
// Câu b
void UocVaBoi(int a[], int n)
{
    int x, y;

    cout << "\nNhap a: ";
    cin >> x;

    cout << "Nhap b: ";
    cin >> y;

    cout << "Phan tu la uoc cua a va boi cua b: ";

    for (int i = 0; i < n; i++)
    {
        if (x % a[i] == 0 && a[i] % y == 0)
            cout << a[i] << " ";
    }
}

//======================
// Câu c
void CapUCLNLonNhat(int a[], int n)
{
    int max = 0;
    int x, y;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int u = UCLN(a[i], a[j]);

            if (u > max)
            {
                max = u;
                x = a[i];
                y = a[j];
            }
        }
    }

    cout << "\nCap (" << x << ", " << y << ") co UCLN lon nhat = " << max;
}

//======================
// Câu d
void ChenK(int a[], int& n)
{
    int k;
    cout << "\nNhap K: ";
    cin >> k;

    int pos = -1;

    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            pos = i;
            break;
        }
    }

    if (pos == -1)
    {
        a[n] = k;
        n++;
    }
    else
    {
        for (int i = n; i > pos + 1; i--)
            a[i] = a[i - 1];

        a[pos + 1] = k;
        n++;
    }

    cout << "\nMang sau khi chen: ";
    XuatMang(a, n);
}

//======================
int main()
{
    int a[MAX], n;

    // Câu a
    NhapMang(a, n);
    cout << "Mang vua nhap: ";
    XuatMang(a, n);

    // Câu b
    UocVaBoi(a, n);

    // Câu c
    CapUCLNLonNhat(a, n);

    // Câu d
    ChenK(a, n);

    return 0;
}



