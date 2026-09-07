// Buoi4.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
	Người viết: Nguyễn Hoàng Gia Bảo 
	MSSSV: 25AD11003
	Ngày cập nhật: 27/01/2026
	Bài 4.2: Nhập xuất chuỗi dùng cin.getline và cout
*/
#include <iostream>
using namespace std;
int main() {
	// Khai báo biến --> Biến chưa có giá 
	// Khai báo biến --> Biến chưa có giá 
	int a, b, c;
	float x, y, z;
	char hoten[50];				// Khai báo biến chuỗi 
	// Dung cin để nhập liệu 
	cin >> a;					// Nhập giá trị cho biến a
	//cin >> x >> y;				// Nhập giá trị cho 2 biến 
	//cin >> b >> z >> c;			// Nhập giá trị cho 3 biến 

	cout << "Nhap ho ten cua ban: ";// Nhắc thông báo 
	cin.getline(hoten, 50);		// Nhập chuỗi 
	cout << "Ho ten vua nhap: "; // Thông báo 
	cout << hoten << endl;
	cout << "a = " << a << endl; // In giá trị của biến a 

	return 0;
}