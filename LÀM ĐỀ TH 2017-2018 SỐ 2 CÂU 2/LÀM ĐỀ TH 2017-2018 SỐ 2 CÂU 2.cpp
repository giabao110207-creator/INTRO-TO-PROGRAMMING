// LÀM ĐỀ TH 2017-2018 SỐ 2 CÂU 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
-Người làm: Nguyễn Hoàng Gia Bảo
-MSSV: 25AD11003
-Ngày sinh: 11/02/2007
-Ngày cập nhật: 16/03/2026
-Công dụng: Câu 2 đề kiểm tra giữa kì 2017-2018 SỐ 2
Câu 2: (4 điểm) Hãy viết chương trình thực hiện các công việc sau:
    a) (1đ) Nhập từ bàn phím và in ra màn hình 1 mảng số nguyên có N phần tử.
    b) (1đ) Kiểm tra xem mảng có tính chất chẵn lẻ xen kẽ hay không.
VD:	1	4	3	6	5	 Yes
    2	5	4	1		 Yes
    3	4	7	1		 No
    c) (1đ) Tìm và in ra cặp phần tử nguyên tố cùng nhau có tổng lớn nhất.
VD: 	a	1	5	3	8	12	9
Cặp (8, 9) có USCLN = 1 và tổng bằng 17  lớn nhất trong các cặp nguyên tố cùng nhau.
    d) (1đ) Nhập 1 số nguyên K; xóa phần tử cuối cùng chia hết cho K khỏi mảng (nếu có); in mảng kết quả ra màn hình.
*/

#include <iostream>
using namespace std;

// Hàm tìm USCLN
int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// Hàm kiểm tra số nguyên tố
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}
int main()
{
    int a[100], N;

    // a) Nhập và in mảng
    cout << "Nhap N: ";
    cin >> N;

    cout << "Nhap mang:\n";
    for (int i = 0; i < N; i++)
        cin >> a[i];

    cout << "Mang vua nhap: ";
    for (int i = 0; i < N; i++)
        cout << a[i] << " ";

    cout << endl;

    // b) Kiểm tra chẵn lẻ xen kẽ
    bool xenKe = true;

    for (int i = 0; i < N - 1; i++) {
        if ((a[i] % 2) == (a[i + 1] % 2)) {
            xenKe = false;
            break;
        }
    }

    if (xenKe)
        cout << "Mang co tinh chat chan le xen ke: Yes\n";
    else
        cout << "Mang co tinh chat chan le xen ke: No\n";

    // c) Tìm cặp nguyên tố cùng nhau có tổng lớn nhất
    int maxSum = -1;
    int x, y;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {

            if (gcd(a[i], a[j]) == 1) {
                if (a[i] + a[j] > maxSum) {
                    maxSum = a[i] + a[j];
                    x = a[i];
                    y = a[j];
                }
            }

        }
    }

    if (maxSum != -1)
        cout << "Cap (" << x << ", " << y << ") co tong lon nhat = " << maxSum << endl;
    else
        cout << "Khong co cap nguyen to cung nhau\n";

    // d) Xóa phần tử cuối cùng chia hết cho K
    int K;
    cout << "Nhap K: ";
    cin >> K;

    int pos = -1;

    for (int i = N - 1; i >= 0; i--) {
        if (a[i] % K == 0) {
            pos = i;
            break;
        }
    }

    if (pos != -1) {
        for (int i = pos; i < N - 1; i++)
            a[i] = a[i + 1];
        N--;
    }

    cout << "Mang sau khi xoa: ";
    for (int i = 0; i < N; i++)
        cout << a[i] << " ";

    return 0;
}


