// Buoi12_MANG2D.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
#define MAX 20				//maximum size of the matrix

//Function declarations
//1. Matrix input
void MatrixInput(int m[][MAX], int d, int c);
//2. Matrix output
void MatrixOutput(int m[][MAX], int d, int c);
//3. Matrix summing
int MatrixSumming(int m[][MAX], int d, int c);
//3b. Summing all even elements

//4. Find the maximum value

//4b. Find the maximum odd value (if any). In case there is no such value,
//the function returns 0.

//4c. Find the minimum value, together with one of its position(s).
//Function returns the minimum value
//(dmin, cmin) contain the position of the minimum value
int FindMinAndPos(int m[][MAX], int d, int c, int& dmin, int& cmin);
//4d. Find the (first) row with maximum total

//6a. Tính tổng dòng thứ k của ma trận(0 <= k < d)
int SumRow(int m[][MAX]), int d, int c, int k;

//PHẦN 3: hàm main() - thân chương trình chính
int main()
{
	//Khai báo biến cục bộ (local) đặt ở đây
	int m[MAX][MAX];		//the matrix variable
	int d;					//actual number of rows
	int c;					//actual number of columns
	do {
		//Các câu lệnh (statements) đặt ở đây...
		cout << "Input number of rows:";
		cin >> d;
		cout << "Input number of columns:";
		cin >> c;
		MatrixInput(m, d, c);
		cout << "The maxtrix just input:\n";
		MatrixOutput(m, d, c);
		int t = MatrixSumming(m, d, c);
		cout << "Total of all elements = " << t << endl;

		int minval, ipos, jpos;
		minval = FindMinAndPos(m, d, c, ipos, jpos);
		//sử dụng 3 giá trị thu được.
		cout << " Gia tri nho nhat: " << minval << endl;
		cout << " Vi tri cua min: " << ipos << endl;

		cout << "Nhan phim ESC de thoat...\n";
	} while (_getch() != 27);
}	//end

//PHẦN 4: thân các hàm/chương trình con tự định nghĩa thêm
//1. Matrix input
void MatrixInput(int m[][MAX], int d, int c)
{
	for (int i = 0; i < d; i++)
		for (int j = 0; j < c; j++)
		{
			cout << "m[" << i << "][" << j << "]=";		//prompt
			cin >> m[i][j];
		}
}
//2. Matrix output
void MatrixOutput(int m[][MAX], int d, int c)
{
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < c; j++) {
			cout.width(5);
			cout << m[i][j];
		}
		cout << endl;
	}
}

//3. Matrix summing
int MatrixSumming(int m[][MAX], int d, int c)
{
	int s = 0;
	for (int i = 0; i < d; i++)
		for (int j = 0; j < c; j++)
			s += m[i][j];
	return s;
}

//4c. Find the minimum value, together with one of its position(s).
//Function returns the minimum value
//(dmin, cmin) contain the position of the minimum value
int FindMinAndPos(int m[][MAX], int d, int c, int& dmin, int& cmin)
{
	int min = m[0][0];			//storing the maximum value
	dmin = 0, cmin = 0;		//storing row index & column index of max
	for (int i = 0; i < d; i++)
		for (int j = 0; j < c; j++)
			if (m[i][j] < min)
			{
				min = m[i][j];
				dmin = i;
				cmin = j;
			}
	return min;
}

//6a. Tính tổng dòng thứ k của ma trận (0 <= k < d)
int SumRow(int m[][MAX], int d, int c, int k)
{
	if (k < 0 || k >= d) return 0;             //Dòng không hợp lệ
	int s = 0;
	for (int j; j < c; j++)
		s += m[k][j];
	return s;
}