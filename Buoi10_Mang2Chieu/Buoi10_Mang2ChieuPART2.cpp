// Buoi10_Mang2Chieu.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Tác giả: Nguyễn Hoàng Gia Bảo
Mã số: 25AD11003
Ngày cập nhật cuối: 10/03/2026
Công dụng/Mục đích: Implement some basic operations on matric (aka. 2D-arrays)
*/
#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;


#define MAX 20
int main() {
	int a[MAX][MAX];			// Ma trận vuông kích thước Max x Max 
	int n;						// Cấp của ma trận 
	int i, j;					// Biến chạy 
	do {
		// Các lệnh cảu chương trình đặt ở đây 
		//B1: Nhập cấp của ma trận vuông
		cout << "Nhap cap cua ma tran vuong:";
		cin >> n;
		// TT1: Nhập ma trận 
		for (j = 0; j < n; j++) {
			cout << "a[" << i << "][" << j << "]=";
			cin >> a[i][j];
		}
		// TT2: In ma trận 
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				cout.width(5);				// Đặt kích thước tối thiểu = 5 
				cout << a[i][j];
			}
			cout << endl;				// Xuống dòng mới 

		}
		
		//TT3: Kiểm tra ma trận đơn vị --> Rồi 

		// TT4: Kiểm tra ma trận tam giác dưới 
		int kiemtra = 1;					//Biến ghi nhận kết quả kiểm tra 
											//  = 1 nếu ma trận thỏa đk, ngược lại thì =0
		// Duyệt ma trận để phát hiện vi phạm
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if ((i < j && a[i][j] != 0) || (i > j && a[i][j] == 0)) {
					kiemtra = 0;			// Ghi nhận vi phạm --> kết luận 
					i = n;					// Để thoát khỏi vòng for i
					break;					// Để thoát khỏi vòng for j 
				}
			}
		}
		// Kết luận dựa trên giá trị của biến K
		// if (a) <--> if (a!=0)
		// if (!a) <--> if (a==0)
		if (kiemtra) cout << "Day la ma tran tam giac duoi" << endl;
		else cout << "Day khong phai la ma tran tam giac duoi" << endl;
		
		// TT5: Kiểm tra các phần tử trên đường chéo chính của ma trận có tăng dần không 
		// Xem các phần tử trên đường chéo chính a[i][j] là 1 mảng 1 chiều 
		// 1	2	5	6	9				n = 5
		int tang = 1;						// Biến ghi nhận kết quả 
		for (i = 0; i < n - 1; i++) {
			if (a[i][i] > a[i + 1][i + 1]) {
				tang = 0;					// Ghi nhận kết quả 
				break;
			}
		}
		// dựa vào biết tang để kết luận 
		if (tang) cout << "Cac phan tu tren duong cheo chinh tang dan" << endl;
		else cout << "Cac phan tu tren duong cheo chinh khong tang dan" << endl;
		// TT6: Kiểm tra xem ma trận a có đối xưng không  

		//TT7: Tim gia tri chan nho nhat trong ma tran
		int minChan;
		int coChan = 0;

		//TT8: Kiem tra ma tran don vi
		int donvi = 1;

		//TT9: Tinh tong cac so chan tren bien ma tran
		int tongChanBien = 0;

		//TT10: Tim dong co tong so chan lon nhat
		int maxTong = -1;
		int dongMax = -1;

		
		cout << "Nhap phim ESC de thoat" << endl;
	}
	while (_getch() != 27);
	return 0;
}

//PHẦN 4: thân các hàm/chương trình con tự định nghĩa thêm
//11.
{
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (a[i][j] % 2 == 0) {
				if (coChan == 0) {
					minChan = a[i][j];
					coChan = 1;
				}
				else if (a[i][j] < minChan) {
					minChan = a[i][j];
				}
			}
		}
	}

	if (coChan)
		cout << "So chan nho nhat trong ma tran: " << minChan << endl;
	else
		cout << "Ma tran khong co so chan" << endl;
}

//12
{
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {

			if (i == j && a[i][j] != 1) {
				donvi = 0;
			}

			if (i != j && a[i][j] != 0) {
				donvi = 0;
			}
		}
	}

	if (donvi)
		cout << "Day la ma tran don vi" << endl;
	else
		cout << "Day khong phai ma tran don vi" << endl;
}

//13.
{
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {

			if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
				if (a[i][j] % 2 == 0) {
					tongChanBien += a[i][j];
				}
			}

		}
	}

	cout << "Tong cac so chan tren bien ma tran: " << tongChanBien << endl;
}

//14.
{
	for (i = 0; i < n; i++) {

		int tongDong = 0;

		for (j = 0; j < n; j++) {

			if (a[i][j] % 2 == 0) {
				tongDong += a[i][j];
			}

		}

		if (tongDong > maxTong) {
			maxTong = tongDong;
			dongMax = i;
		}
	}

	cout << "Dong co tong so chan lon nhat la: " << dongMax << endl;
	cout << "Tong lon nhat: " << maxTong << endl;
}