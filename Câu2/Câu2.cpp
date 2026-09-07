// Câu2.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
-Người làm: Nguyễn Hoàng Gia Bảo
-MSSV: 25AD11003
-Ngày sinh: 11/02/2007
-Ngày cập nhật: 17/03/2026
-Công dụng: Câu 2 đề kiểm tra giữa kì
Problem 2: (7 points) Write a complete program meeting the following requirements (Hãy viết chương trình thực hiện các công việc sau):
    a) (1p) Input an integer array with N elements, then ouput that array onto the console screen (Nhập từ bàn phím và in ra màn hình 1 mảng số nguyên có N phần tử).
    b) (1.5p) Check if all even numbers in the array are in descending order or not (Kiểm tra và cho biết các số chẵn trong mảng có thứ tự giảm dần hay không).
Ex: 		1	8	4	7	2	 Yes
        1	5	3	4		 Yes
        1	2	3	4		 No
    c) (1.5p) Find and print out the smallest square number in the array (if any). (Tìm và in ra số chính phương nhỏ nhất của mảng – nếu có).
    d) (1.5p) Delete the all the square numbers from the array, except for the smallest one (if any); print out the resulting array (Xóa số tất cả các số chính phương ra khỏi mảng, trừ 1 số chính phương nhỏ nhất (nếu có); in mảng kết quả ra màn hình).
    e) (1.5p) Create a new array containing elements that have 5 or more dividents, extracting from the existing array (if any); print out the resulting array (Tạo mảng mới gồm những số có từ 4 ước số dương trở lên (nếu có) trích từ mảng ban đầu; in mảng kết quả ra màn hình).
*/

#include <iostream>
using namespace std;

#define SIZE 100

//Khai báo hàm 
//1. Nhập Mảng 
void nhapmang(int a[], int n);
//2. In mảng 
void  inmang(int a[], int n);
//3 Kiểm tra xem các số chẵn của mảng có thứ tự giảm hay không
bool ktchantang(int a[], int n);

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

    //Thao tác 3: Kiểm tra xem các số chẵn của mảng có thứ tự giảm hay không
    bool ktchangiam(int a[], int n);
    {
        int k = -1;

        bool first = true;
        bool check = true;
        for (int i = 0; i < n; i++)
        {
            if (a[i] % 2 == 0)
            {
                k = a[i];
                first = false;
            }
            else if (a[i] > k)
            {
                check = false;
                break;
            }
            k = a[i];
        }
        if (check)
            cout << "NO";
        else
            cout << "YES";
        return 0;
    }
    //c
    int cpMin = INT_MAX;
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (ktcp(a[i])) {
            if (a[i] < cpMin) cpMin = a[i];
            found = true;
        }
    }
    if (found) {
        cout << "So chinh phuong nho nhat: " << cpMin << endl;
    }
    else {
        cout << "Khong co so chinh phuong trong mang" << endl;
    }

    //d
    if (found) {
        int b[100];
        int m = 0;
        bool keptSmallest = false;
        for (int i = 0; i < n; i++) {
            if (ktcp(a[i])) {
                if (a[i] == cpMin && !keptSmallest) {
                    b[m++] = a[i];
                    keptSmallest = true;
                }
                else {
                }
            }
            else {
                b[m++] = a[i];
            }
        }
        cout << "Mang sau khi xoa cac so chinh phuong (con mot cp so nho nhat): ";
        xuatMang(b, m);
    }
    else {
        cout << "Mang sau khi xoa cac so chinh phuong: ";
        xuatMang(a, n);
    }

    return 0;

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
//3. Kiểm tra 1 số nguyên k có phải là số chính phương hay không
bool ktcp(int k) {
    if (k < 0) return false;
    int s = sqrt(k);
    return (s * s == k);
}



