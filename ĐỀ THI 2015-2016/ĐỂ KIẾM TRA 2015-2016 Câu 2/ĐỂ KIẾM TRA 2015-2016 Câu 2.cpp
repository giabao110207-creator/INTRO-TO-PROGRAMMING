// ĐỂ KIẾM TRA 2015-2016 Câu 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
- Người viết: Nguyễn Hoàng Gia Bảo
- MSSV : 23AD11003
- Ngày cập nhật cuối: 08/03/2026
- Công dụng:Ôn tập 
*/

//Phần 1: Khai báo tiền xử lý (pre-processors)
#include <iostream>
#include <cmath>
using namespace std;            //Dùng các lệnh cin và cout
#define SIZE 100                //Kích thước mảng 


//Phần 2: Khai báo toàn cục (global) - dùng chung cho cả chương trình 
//Khai báo hàm 
//1. Nhập Mảng 
void nhapmang(int a[], int n);
//2. In mảng 
void  inmang(int a[], int n);
//3. Đếm ước 
int demuoc(int n);
int dempt5uoc(int a[], int n);

int main()
{
    //Khai báo biến (cục bộ)
    int a[SIZE];                    //Mảng 1 chiều 
    int n;                          //Số phần tử thực tế sử dụng (n <= SIZE)

    //Nhập số phần tử 
    cout << "Nhap so phan tu:";
    cin >> n;

    //Thao tác 1: Nhập giá trị cho các phần tử của mảng (n giá trị)
    //cin >> a[0];                     //Nhập giá trị cho ô đầu (Phần tử đầu)
    //cin >> a[1];
    //cin >> a[2];
    for (int i = 0; i < n; i++) {
        cout << "Nhap phan tu thu #" << i << ":";      //Câu nhắc 
        cin >> a[i];
    }

    //Thao tác 2: In nội dung mảng ra màn hình 
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;                                       //Sau khi in xong mảng thì xuống dòng 

    //Thao tác 3: Đếm số phần tử có 5 ước dương trở lên
    cout << "So phan tu co tu 5 uoc tro len: " << dempt5uoc(a, n) << endl;
}

//Phần 4: Thân của các hàm CT/con tự xây dựng thêm
//Câu 2a 
//1. Nhập mảng 
void nhapmang(int a[], int n)
{
    for (int i = 0; i < n; i++) {
        cout << "Nhap phan tu thu #" << i << ":";      //Câu nhắc 
        cin >> a[i];
    }
}

//2. In mảng
void inmang(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

//Câu 2b
int demuoc(int n)
{
    int dem = 0;
    n = abs(n);

    for (int i = 1; i <= n; i++)
        if (n % i == 0)
            dem++;

    return dem;
}

int dempt5uoc(int a[], int n)
{
    int dem = 0;

    for (int i = 0; i < n; i++)
        if (demuoc(a[i]) >= 5)
            dem++;

    return dem;
}