#include <iostream>
#include <cmath> 
using namspace std;
// Khai bao toan cuc (global) - dung chung cho ca chuong trinh 
const float PI = 3.14159; // khai bao hang so PI
float cv, dt; // khai bao 2 bien so thuc 
int main() {
	int r; // khai bai bien (cuc bo)
	cout << "Nhap ban kinh";
	cin >> r;
	cv = 2 * r * PI;
	dt = r * r * PI;
	cout << "Chu vi = " << cv << endl;
	cout << "Dien tich = " << dt << endl;
	return 0;
}