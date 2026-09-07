/*
	Người viết: Nguyễn Hoàng Gia Bảo
	MSSSV: 25AD11003
	Ngày cập nhật: 27/01/2026
	Buổi 4.5: Minh họa lệnh lặp - In các ước dương của 1 số
		Đề
		//Chương trình nhập 1 số nguyên duong từ bàn phím
		//In ra các ước số dương của số đó
		//Yêu cầu: Việc nhập phải đảm bảo số nhập vào > 0
		//Nếu không thỏa thì yêu cầu nhập lại cho tới khi thoải mới thôi 
*/
#include <iostream>
using namespace std;
int main() {
	int n;			// Số nhập vào
	int i;
	// Nhập số thỏa điều kiện n > 0
	do {
		cout << "Nhap 1 so nguyen duong: ";
		cin >> n;
	} while (n <= 0);		// điều kiện để lặp lại = phủ định (đk ràng buộc)
	
	// In ra các ước số dương của n
	for(i=1;i<=n;i++)
		if (n % i == 0) {
			cout << i << "  ";
		}
	cout << endl;			// xuống dòng cho dễ nhìn 
	
	return 0;
}