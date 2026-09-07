/*
	Người viết: Nguyễn Hoàng Gia Bảo
	MSSSV: 25AD11003
	Ngày cập nhật: 27/01/2026
	Buổi 4.6: Tạo khung chương trình mẫu chạy được nhiều lần
*/
#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;		// Dùng để cin cout
int main() {
	// Khai báo biến đặt ở đây 
	do {
		// Các lệnh của chương trình đặt ở đây

		cout << "Nhan phim ESC de thoat" << endl;
	} while (_getch() != 27);			// Chương trình chạy được nhiều lần
	return 0;
}