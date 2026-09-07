// LÀM ĐỀ THI 2015-2016 CÂU 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
-Người làm: Nguyễn Hoàng Gia Bảo
-MSSV: 25AD11003
-Ngày sinh: 11/02/2007
-Ngày cập nhật: 16/03/2026
-Công dụng: Câu 2 đề kiểm tra giữa kì
Câu 2: (5 điểm) Hãy viết chương trình thực hiện các công việc sau:
    a) (1đ) Nhập từ bàn phím và in ra màn hình 1 mảng số nguyên có N phần tử.
    b) (1.5đ) Cho biết trong mảng có bao nhiêu phần tử có từ 5 ước số dương trở lên.
    c) (1.5đ) Tìm và in ra phần tử xuất hiện nhiều lần nhất cùng với số lần xuất hiện của nó. Trường hợp có nhiều phần tử có số lần xuất hiện bằng nhau thì chỉ cần in ra 1 trong các giá trị mà thôi.
    d) (1đ) Tính và in tổng tất cả các chữ số của những phần tử trong mảng.
*/


#include <iostream>
using namespace std;
#define SIZE 100

//Phần 2: Khai báo toàn cục (global) - dùng chung cho cả chương trình 

//Khai báo hàm 
//1. Nhập Mảng 
void nhapmang(int a[], int n);
//2. In mảng 
void  inmang(int a[], int n);
//3. Đếm ước 
int demuoc(int n);
int demp5uoc(int a[], int n);
//4. Phần tử xuất hiện nhiều nhất 
void phantunhieunhat(int a[], int n);
//5. Tính tổng 
int tong(int a[], int n);

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
    cout << "So phan tu co tu 5 uoc tro len: " << demp5uoc(a, n) << endl;

    //Thao tác 4: Tìm phần tử xuất hiện nhiều lần nhất
    phantunhieunhat(a, n);
    
    //Thao tác 5: Tính tổng toàn bộ các phần tử của mảng 
    cout << "Tong mang: " << tong(a, n) << endl;
}

//Phần 4: Thân của các hàm CT/con tự xây dựng thêm
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

//3. Đếm ước 
int demuoc(int n)
{
    int dem = 0;
    n = abs(n);

    for (int i = 1; i <= n; i++)
        if (n % i == 0)
            dem++;

    return dem;
}

int demp5uoc(int a[], int n)
{
    int dem = 0;

    for (int i = 0; i < n; i++)
        if (demuoc(a[i]) >= 5)
            dem++;

    return dem;
}

//4. Phần tử xuất hiện nhiều nhất 
void phantunhieunhat(int a[], int n)
{
    int maxDem = 0;
    int value;

    for (int i = 0; i < n; i++)
    {
        int dem = 0;

        for (int j = 0; j < n; j++)
        {
            if (a[i] == a[j])
                dem++;
        }

        if (dem > maxDem)
        {
            maxDem = dem;
            value = a[i];
        }
    }

    cout << "Phan tu xuat hien nhieu nhat: " << value << endl;
    cout << "So lan xuat hien: " << maxDem << endl;
}

//5. Tính tổng 
int tong(int a[], int n)
{
    int s = 0;       //Tổng 
    for (int i = 0; i < n; i++)
        s += a[i];              //s = s + a[1]; i.e. cộng dồn 
    return s;                  //Trả kết quả ra 
}