/*
	Người viết: Nguyễn Hoàng Gia Bảo
	MSSSV: 25AD11003
	Ngày cập nhật: 27/01/2026
	Buổi 4.4: Lệnh lặp while, do...while và for
*/
/*	-----While syntax--------
	while (expression)
	{
		statement[s] to be looped;
	}
*/

/*	-----Do...While syntax-----
	do{
		statement[s] to be looped;
	} while (expression);
*/

/*	-----For syntax-------
	for (stmnt1; expression; stmnt2)
	statement[s] to be looped;
*/



#include <iostream>
using namespace std;
int main() {
	// Tính tổng các số từ 1-10
	/*int tong = 0;
	int i = 1;*/
	
	/*while (i <= 10) {
		tong += i;
		i++;
	}*/

	// Nhập liệu rồi mới kiểm tra 
	// Thực hiện / chạy được nhiều lần 
	/*do {
		tong += i;
		i++;
	} while (i <= 10);*/
	
	
	// Vòng lặp for 
	// Cách 1:
	/*int tong = 0, i;
	for (i = 1; i <= 10; i++)
		tong += i;*/			// Cộng dồn 
	//Cách 2:
	int tong, i;				// Chưa có giá trị 
	for (i = 1, tong = 0; i <= 10; i++)
		tong = +i;

	cout << "Tong = " << tong << endl;
	return 0;
}
