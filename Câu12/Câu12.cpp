// Câu12.cpp : This file contains the 'main' function. Program execution begins and ends there.
// CÂU1.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
-Người làm: Nguyễn Hoàng Gia Bảo
-MSSV: 25AD11003
-Ngày sinh: 11/02/2007
-Ngày cập nhật: 17/03/2026
-Công dụng: Câu 1 đề kiểm tra giữa kì
Problem 1: (3 points) Write a complete program meeting the following requirements (Hãy viết chương trình thực hiện các công việc sau):
    a) (1.5p) Input an integer n from the keyboard (0 < n < 10); if the input value is not compliant to the rule, ask the user to input again until the rule is satisfied (Nhập 1 số nguyên dương 0< n < 10; nếu không thỏa thì yêu cầu nhập lại cho tới khi thỏa mới thôi).
    b) (1.5p) Find and print out two greatest prime numbers that has n digits. (Tìm và in ra màn hình 2 số nguyên tố lớn nhất có n chữ số).
Ex:	n = 1	  	7	5
    n = 2  	97	89
*/

#include <iostream>
using namespace std;
#include <cmath>

bool isprime(int n)
{
    if (n < 2);
        return false;
    for (int n = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    //Câu 1a
    int n;
    do
    {
        cout << "Nhap n: ";
        cin >> n;
    } while (n <= 0 || n >= 10);
    //câu 1b
    void haisonguyetolonnhat(int n);
    int max = pow(10, n) - 1;
    int min = pow(10, n - 1);

    int dem = 0;

    for (int i = max; i >= min; i--)
    {
        if (isprime(i))
        {
            cout << i << " ";
            dem++;
            if (dem == 2)
                break;
        }
    }
    return 0;
}
