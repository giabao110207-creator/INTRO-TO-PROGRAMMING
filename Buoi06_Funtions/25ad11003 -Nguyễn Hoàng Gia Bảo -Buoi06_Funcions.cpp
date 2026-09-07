// Buoi06_Funtions.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Người viết: Nguyễn Hoàng Gia Bảo
MSSV: 25AD11003
Ngày cập nhật cuối: 03/02/2026
Công dụng: nhập một số nguyên dương n. In ra màn hình:
- Các số nguyên tố <= n theo thứ tự từ bé đến lớn
- Các số chính phương <= n theo thứ tự từ bé đến lớn
- Viết hàm tìm ước chung lớn nhất (UCLN) của hai số nguyên dương a và b.
- Viết hàm tìm bội chung nhỏ nhất (BCNN) của hai số nguyên dương a và b. 
- Tìm UCLN của các số a, b, c, d, e.
- Tìm BCNN của các số a, b, c, d, e.
- Cho số nguyên dương n. Viết chương trình thực hiện các yêu cầu sau: 
  a. Viết hàm kiểm tra xem n có phải là số nguyên tố (SNT) hay không? Hàm trả về true nếu
n là SNT và false nếu ngược lại. 
  b. In SNT gần nhất và bé hơn hoặc bằng n (giả sử n > 2)
  c. In ra các SNT từ 1 đến n.
  d. In ra n số nguyên tố đầu tiên bắt đầu từ a (a cho trước). 
- Cho n là số nguyên dương. Viết chương trình thực hiện các yêu cầu sau:
a. In ra số Fibonacci thứ n. Số Fibonacci được định nghĩa theo công thức sau:
b. Tìm tổng của các số Fibonacci chẵn nhỏ hơn hoặc bằng n
*/

//Phần 1: Khai báo tiền xử lý (pre-processors)
#include <iostream>
#include <cmath>    // Cần thư viện này để dùng hàm sqrt
using namespace std;

//Phần 2: Khai báo toàn cục (global) - dùng chung cho cả chương trình
//KHAI BÁO NGUYÊN MẪU HÀM (Prototypes)
//Hàm kiểm tra 1 số nguyên không có phai là số nguyên tố không 
bool ktnguyento(int k);
//Hàm kiểm tra 1 số nguyên không có phai là số chính phương không 
bool ktcp(int k);
void innguyento(int n);
void inchinhphuong(int n);
int UCLN(int a, int b);
int BCNN(int a, int b);
int UCLN_5so(int a, int b, int c, int d, int e);
int BCNN_5so(int a, int b, int c, int d, int e);

// Hàm in SNT gần nhất và bé hơn hoặc bằng n (giả sử n > 2) 
void cau5b(int n);
void cau5d(int n, int a);

// Hàm để làm câu 6 
long long fibonacci(int n);          // Trả về số Fib thứ n
long long tongFibonaccichan(int n);  // Trả về tổng các số Fib chẵn <= n

//Phần 3: Chương trình chính 
int main() {
    int n, a, b, c, d, e;

    if (ktnguyento(n) == true) cout << "Yes!" << endl;
    else cout << "No!" << endl;
    cout << "\n--- tim so nguyen duong va so chinh phuong ---" << endl;
    cout << "nhap 1 so nguyen duong n: ";
    cin >> n;

    cout << "Cac so nguyen to <= " << n << " la: " << endl;
    innguyento(n);

    cout << "\nCac so chinh phuong <= " << n << " la: " << endl;
    inchinhphuong(n);

    cout << "\n--- tim UCLN ---" << endl;
    cout << "nhap so nguyen duong a: ";
    cin >> a;
    cout << "nhap so nguyen duong b: ";
    cin >> b;
    cout << "Uoc chung lon nhat cua " << a << " va " << b << " la: " << UCLN(a, b) << endl;

    cout << "\n--- tim BCNN ---" << endl;
    cout << "nhap so nguyen duong c, d, e: \n";
    cin >> c >> d >> e;

    cout << "BCNN 2 so cua " << a << " va " << b << " la: " << BCNN(a, b) << endl;
    cout << "UCLN cua 5 so la: " << UCLN_5so(a, b, c, d, e) << endl;
    cout << "BCNN cua 5 so la: " << BCNN_5so(a, b, c, d, e) << endl;
    return 0;
}


//Phần 4: Thân của các hàm/CT con tự xây dựng thêm

//Kiểm tra 1 số nguyên k có phải là số nguyên tố hay không
bool ktnt(int k) {
    if (k < 2)
        return false;
    double c = sqrt(k);
    for (int i = 2; i <= c; i++) {
        if (k % i == 0)
            return false;
    }
    return true;
}

//Kiểm tra 1 số nguyên k có phải là số chính phương hay không
bool ktcp(int k) {
    if (k < 0) return false;
    int s = sqrt(k);
    return (s * s == k);
}

//Hàm in ra các số nguyên tố <= n theo thứ tự từ bé đến lớn
void innguyento(int n) {
    for (int i = 1; i <= n; i++) {
        if (ktnt(i) == true)
            cout << i << " ";
    }
    cout << endl;
}

//Hàm in ra các số chính phương <= n theo thứ tự từ lớn đến bé
void inchinhphuong(int n) {
    for (int i = 1; i <= n; i++) {
        if (ktcp(i) == true)
            cout << i << " ";
    }
    cout << endl;
}

//Hàm tìm ước chung lớn nhất của 2 số nguyên dương a, b
int UCLN(int a, int b) {
    //nếu nhập 0
    if (a == 0 || b == 0)
        return a + b;

    while (a != b) {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
}

//Hàm tìm bội chung nhỏ nhất của 2 số nguyên dương a, b
int BCNN(int a, int b) 
{
    if (a == 0 || b == 0) return 0;
    return (int)a * b;
}

//Hàm tìm bội chung lớn nhất của 5 số nguyên dương a, b, c, d, e
int UCLN_5so(int a, int b, int c, int d, int e) 
{
    int ucln_ab = UCLN(a, b);
    int ucln_abc = UCLN(ucln_ab, c);
    int ucln_abcd = UCLN(ucln_abc, d);
    return UCLN(ucln_abcd, e);
}

//Hàm tìm bội chung nhỏ nhất của 5 số nguyên dương a, b, c, d, e
int BCNN_5so(int a, int b, int c, int d, int e) 
{
    int bcnn_ab = BCNN(a, b);
    int bcnn_abc = BCNN(bcnn_ab, c);
    int bcnn_abcd = BCNN(bcnn_abc, d);
    return BCNN(bcnn_abcd, e);
}

//hàm kiểm tra xem n có phải là số nguyên tố (SNT) hay không? Hàm trả về true nếun là SNT và false nếu ngược lại.
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

//In SNT gần nhất và bé hơn hoặc bằng n (giả sử n > 2)
 void primeNearest(int n) 
    {
        for (int i = n; i >= 2; i--) {
            if (isPrime(i)) {
                cout << "So nguyen to gan nhat <= " << n << " la: " << i << endl;
                return;
            }
        }
//In ra các SNT từ 1 đến n.
 void printPrimesToN(int n);
        {
            cout << "Cac so nguyen to tu 1 den " << n << ": ";
            for (int i = 2; i <= n; i++) {
                if (isPrime(i))
                    cout << i << " ";
            }
            cout << endl;
        }

//In ra n số nguyên tố đầu tiên bắt đầu từ a (a cho trước). 
        void cau5d(int n, int a); {
            int dem = 0; // Bien de dem xem da in duoc bao nhieu so
            int i = a;   // Bat dau kiem tra tu so a
            while (dem < n) {
                if (ktnguyento(i)) {
                    cout << i << " ";
                    dem++; // Moi lan tim thay thi tang bien dem
                }
                i++; // Tang i de kiem tra so tiep theo
            }
            cout << endl;
        }

        // 6a. Tim so Fibonacci thu n (dung vong lap)
        long fibonacci(int n);
        {
            if (n == 0) return 0;
            if (n == 1) return 1;
            long long f0 = 0, f1 = 1, fn;
            for (int i = 2; i <= n; i++) {
                fn = f0 + f1;
                f0 = f1;
                f1 = fn;
            }
            return f1;
        }

        // 6b. Tong cac so Fibonacci chan <= n
        long long tongFibonaccichan(int n); {
            long long f0 = 0, f1 = 1, fn = 0;
            long long tong = 0;
            // Ta bat dau tu fn = 0
            while (fn <= n) {
                if (fn % 2 == 0) {
                    tong += fn;
                }
                // Tao so Fibonacci tiep theo
                fn = f0 + f1;
                f0 = f1;
                f1 = fn;
            }
            return tong;
        }