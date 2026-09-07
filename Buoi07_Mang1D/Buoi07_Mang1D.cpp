// Buoi07_Mang1D.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
- Người viết: Nguyễn Hoàng Gia Bảo
- MSSV : 23AD11003
- Ngày cập nhật cuối: 02/03/2026
- Công dụng: Minh hoạ các thao tác cơ bản 
*/


//Phần 1: Khai báo tiền xử lý (pre-processors)
#include <iostream>
using namespace std;                //Dùng các lệnh cin và cout
#define SIZE 100                    //Kích thước mảng 

//Phần 2: Khai báo toàn cục (global) - dùng chung cho cả chương trình 

//Khai báo hàm 
//1. Nhập Mảng 
void nhapmang(int a[], int n);
//2. In mảng 
void  inmang(int a[], int n);
//3.1 Tính tổng mảng 
int tongmang(int a[], int n);
//3.2 Tính tổng các số chẵn trong mảng 
int tongchan(int a[], int n);
//3.3 Hàm kiểm tra số nguyên tố (cũ)
bool ktnt(int n);
//3.4 Hàm kiểm tra số chính phương (cũ)
bool ktcp(int n);
//3.5 Tính tổng các số nguyên tố có trong mảng 
int tongnt(int a[], int n);
//3.6 Đếm số lượng số chính phương có trong mảng 
int demcp(int a[], int n);
//Phần 3: Chương trình chính 

//Bài Tập
//6. Viết hàm tìm vị trí dương đầu tiên trong mảng 1 chiều.
//Hàm trả về vị trí đầu tiên tìm được, nếu mảng không có số dương thì trả về -1
int timvtduong(int a[], int n);

//7. Viết hàm tìm giá trị dương bé nhất trong mảng 1 chiều.
//Nếu mảng không có số dương nào thì trả về -1
int timduongmin(int a[], int n);

//8. Viết hàm tìm vị trí số nguyên tố lớn nhất trong mảng.
int timvtntmax(int a[], int n);

//9. Viết hàm tìm vị trí số chính phương cuối cùng trong mảng.
int timvtcpcuoi(int a[], int n);

//15. Tìm UCLN của mọi phần tử trong mảng.
int ucln(int a[], int n);
int ucln2(int a, int b);

//16. Tìm BCNN của mọi phần tử trong mảng.
int bcnn(int a[], int n);
int bcnn2(int a, int b);

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

    //Thao tác 3: Tính tổng toàn bộ các phần tử của mảng 
        int s = 0;       //Tổng 
        for (int i = 0; i < n; i++)
            s += a[i];              //s = s + a[1]; i.e. cộng dồn 

    // Thao tác 4: Tính tổng các số chẵn trong mảng
        int tc = tongchan(a, n);
        cout << "Tong cua cac so chan la: " << tc << endl;

    // Thao tác 5: Kiểm tra số nguyên tố (cũ)
        ktnt(n);

    // Thao tác 6: Kiểm tra số chính phương (cũ)
        ktcp(n);
    // Thao tác 7: Tính tổng các số nguyên tố có trong mảng
        int tnt = tongnt(a, n);
        cout << "Tong cac so nguyen to la: " << tnt << endl;

    // Thao tác 8: Đếm số lượng số chính phương có trong mảng
        int dcp = demcp(a, n);
        cout << "So luong so chinh phuong co trong mang la: " << dcp << endl;

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

//3.1 Tính tổng mảng 
//Hàm trả về tổng của tất cả các phần tử trong mảng 
int tongmang(int a[], int n)
{
    int s = 0;       //Tổng 
    for (int i = 0; i < n; i++)
        s += a[i];              //s = s + a[1]; i.e. cộng dồn 
    return s;                  //Trả kết quả ra 
}

//3.2 Tính tổng các số chẵn trong mảng 
int tongchan(int a[], int n) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            s += a[i];
        }
    }
    return s;
}

// 3.3 Hàm kiểm tra số nguyên tố (cũ)
bool ktnt(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

//3.4 Hàm kiểm tra số chính phương (cũ)
bool ktcp(int n) {
    if (n < 0) return false;
    int can = sqrt(n);
    if (can * can == n) return true;
    return false;
}

//3.5 Tính tổng các số nguyên tố có trong mảng
int tongnt(int a[], int n) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        if (ktnt(a[i]) == true) {
            s += a[i];
        }
    }
    return s;
}

//3.6 Đếm số lượng số chính phương có trong mảng
int demcp(int a[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (ktcp(a[i]) == true) {
            count++;
        }
    }
    return count;
}

//6. Viết hàm tìm vị trí dương đầu tiên trong mảng 1 chiều.
//Hàm trả về vị trí đầu tiên tìm được, nếu mảng không có số dương thì trả về -1
int timvtduong(int a[], int n)
{
    for (int i = 0; i < n; i++)
        if (a[i] > 0) return i;
    return -1;
}

//7. Viết hàm tìm giá trị dương bé nhất trong mảng 1 chiều.
//Nếu mảng không có số dương nào thì trả về -1
int timduongmin(int a[], int n)
{
     int min = -1;

    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            if (min == -1 || a[i] < min)
            {
                min = a[i];
            }
        }
    }

    return min;
}

//8. Viết hàm tìm vị trí số nguyên tố lớn nhất trong mảng.
int timvtntmax(int a[], int n)
{
    int vt = -1;
    int max = -1;

    for (int i = 0; i < n; i++)
    {
        if (ktnt(a[i]) == true)
        {
            if (a[i] > max)
            {
                max = a[i];
                vt = i;
            }
        }
    }

    return vt;
}

//9. Viết hàm tìm vị trí số chính phương cuối cùng trong mảng.
int timvtcpcuoi(int a[], int n)
{
    int vt = -1;

    for (int i = 0; i < n; i++)
    {
        if (ktcp(a[i]) == true)
        {
            vt = i;
        }
    }

    return vt;
}

//15. Tìm UCLN của mọi phần tử trong mảng.
int ucln(int a[], int n)
{
    int kq = a[0];

    for (int i = 1; i < n; i++)
    {
        kq = ucln2(kq, a[i]);
    }

    return kq;
}

//16. Tìm BCNN của mọi phần tử trong mảng.
int bcnn(int a[], int n)
{
    int kq = a[0];

    for (int i = 1; i < n; i++)
    {
        kq = bcnn2(kq, a[i]);
    }

    return kq;
}

