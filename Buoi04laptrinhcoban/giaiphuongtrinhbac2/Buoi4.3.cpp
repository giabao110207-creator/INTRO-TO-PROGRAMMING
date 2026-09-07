/*
	Người viết: Nguyễn Hoàng Gia Bảo
	MSSSV: 25AD11003
	Ngày cập nhật: 27/01/2026
	Buổi 4.3: Giải và biện luận  phương trình bậc 2 ax^2 + bx + c
*/

// Nhập vào 3 hệ số a,b,c
// Giải và biện luận phương trình bậc 2 ax^2 + bx + c

#include <iostream>
using namespace std;
int main() {
	// Khai báo biến 
	float a, b, c, x1, x2, delta, x;
	// Nhâp liệu 
	cout << "Nhap cac he so a, b, c: ";
	cin >> a >> b >> c;
	// Biện luận
	if (a == 0) {					// trường hợp suy biến	
		// Giải và biện luận phương trình bậc nhất bx+c=0
		if (b == 0) {
			if (c == 0) cout << "Phuong trinh vo so nghiem" << endl;
			else cout << "Phuong trinh vo nghiem" << endl;
		}
		else {			//b!=0
			cout << "Phuong trinh co 1 nghiem don x = " << -c / b << endl;
		}
	}
	else {							// Phương trình bậc 2 (a!=0)
		// Tính delta
		delta = b * b - 4 * a * c;
		// Xét delta<0, ==0,>0
		if(delta < 0){
			cout << "Phuong trinh vo nghiem" << endl;
		}
		else {						// Delta >=0
			if (delta == 0) {
				x = -b / (2 * a);
				cout << "Phuong trinh co nghiem la: " << x << endl;
			}
			else{					// Delta >0
				if (delta > 0) {
					x1 = (-b + sqrt(delta) / (2 * a));
					x2 = (-b - sqrt(delta) / (2 * a));
					cout << "Phuong trinh co 2 nghiem la: " << x1 << x2 << endl;
				}

			}
	}
	return 0;
}