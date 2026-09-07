// Buoi12_MaTranVuong.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Tác giả: Nguyễn Hoàng Gia Bảo
Mã số: 25AD11003
Ngày cập nhật cuối: 23/3/2026
Công dụng/Mục đích: Implement some basic operations on matric (aka. 2D-arrays)
*/

//PHẦN 1: Các khai báo tiền xử lý (pre-processors)
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

//PHẦN 2: Khai báo toàn cục (global declarations)
//Đây là các khai báo dùng chung cho toàn bộ chương trình
//Khai báo này có thể là hằng, biến, hàm, không gian tên,...
using namespace std;		//khai báo không gian tên/thư viện
#define MAX 4				//maximum size of the matrix

//Function declarations
//1. Matrix input
void SquareMatrixInput(int m[][MAX], int n);
//2. Matrix output
void SquareMatrixOutput(int m[][MAX], int n);
//3. Matrix summing
void SquareMatrixSumming(int m[][MAX], int n);
//4. Kiểm tra ma trận đơn vị
bool MTDonVi(int m[][MAX], int n);
//5. Kiểm tra ma trận chéo
bool MTCheo(int m[][MAX], int n);


int main()
{

	//Khai báo biến cục bộ (local) đặt ở đây
	int m[MAX][MAX] = { {1,0,0,0},
						{0,1,0,0},
						{0,0,1,0},
						{0,0,0,1} };
	int n = 4;
		if (MTDonVi(m, n) == true) cout << "YES!\n";
		else cout << "NO!\n";
	

	
}


//PHẦN 4: thân các hàm/chương trình con tự định nghĩa thêm
//1. Matrix input
void MatrixInput(int m[][MAX],  int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cout << "m[" << i << "][" << j << "]=";		//prompt
			cin >> m[i][j];
		}
}
//2. Matrix output
void MatrixOutput(int m[][MAX], int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout.width(5);
			cout << m[i][j];
		}
		cout << endl;
	}
}

//3. Matrix summing
int MatrixSumming(int m[][MAX], int n)
{
	int s = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			s += m[i][j];
	return s;
}

//4. Kiểm tra ma trận đơn vị
bool MTDonVi(int m[][MAX], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if ((i == j && m[i][j] != 1) || (i == j && m[i][j] != 0)) return false;   //Kết luận và dừng kiểm tra 
				return true;

}

//5. Kiểm tra ma trận chéo
bool MTCheo(int m[][MAX], int n)
{

}