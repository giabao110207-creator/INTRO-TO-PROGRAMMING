// Buoi10_Mang2Chieu.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Tác giả: Nguyễn Hoàng Gia Bảo
Mã số: 25AD11003
Ngày cập nhật cuối: 10/03/2026
Công dụng/Mục đích: Implement some basic operations on matric (aka. 2D-arrays)
*/

//PHẦN 1: Các khai báo tiền xử lý (pre-processors)
#include <iostream>
#include <conio.h>
#include <math.h>

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

//PHẦN 3: hàm main() - thân chương trình chính
int main()
{
	//Khai báo biến cục bộ (local) đặt ở đây
	int a[MAX][MAX];		//Ma trận vuông
	int d;					//Số dòng thực tế sử dụng 
	int c;	                //Số cột thực tế sử dụng
	int n;
	int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
	int m, p, k;
	int i, j;               //Biến chạy
	do {
		//Các lệnh của chương trình đặt ở đây 
		//B1. Nhập kích thước thực tế của ma trận 
		cout << "Nhap so dong:";
		cin >> d;
		cout << "Nhap so cot:";
		cin >> c;

		//Thao tác 1: Nhập ma trận
		for (i = 0; i < d; i++)
			for (j = 0; j < c; j++)
			{
				cout << "a[" << i << "][" << j << "] = ";    //Câu nhắc 
				cin >> a[i][j];
			}
		//Thao tác 2: In ma trận 
		for (i = 0; i < d; i++)
		{
			for (j = 0; j < c; j++)
			{
				cout.width(5);                //Đặt kích thước tối thiểu bằng 5
				cout << a[i][j];

			}
			cout << endl;        //Xuống dòng mới 
		}
		//Thao tác 3: Tính tổng các phần tử của ma trận 
		int tong = 0;
		for (i = 0; i < d; i++)
			for (j = 0; j < d; j++)
				tong += a[i][j];
		//In kết quả sau khi duyệt xong 
		cout << " Tong cac phan tu = " << tong << endl;
		//Thao tác 3: Tính tổng các số chẵn có trong ma trận 
		//Thao tác 4: Đếm số lượng số chính phương có trong ma trận 
		int demcp = 0;
		for (i = 0; i < d; i++)
			for (j = 0; j < d; j++)
				if (int(sqrt(a[i][j])) == sqrt(a[i][j]))
					demcp++;
		//In kết quả sau khi duyệt xong 
		cout << "  So luong so chinh phuong = " << tong << endl;

		//Thao tác 5: Tìm giá trị lớn nhất của ma trận

		//Thao tác 5b: Tìm giá trị lớn nhất và 1 vị trí xuất hiện của nó
		int max = a[0][0];              //Giá trị lớn nhất 
		int dmax = 0;                   //Chỉ số dòng của giá trị max
		int cmax = 0;                   //Chỉ số cột của giá trị max 
		for (i = 0; i < d; i++)
			for (j = 0; j < c; j++)     //Duyệt ma trận 
				if (a[i][j] > max)
				{
					max = a[i][j];
					dmax = i;
					cmax = j;
				}
		//Ra khỏi vòng lặp - -> In kết quả 
		cout << "  Gia tri lon nhat  = " << max << endl;
		cout << "  Vi tri xuat hien = (" << dmax << ", " << cmax << ")" << endl;
		//Thao tác 5c: Tìm giá trị chẵn lớn nhất (nếu có) và vị trí của nó 
		//B1: Tìm số chẵn đầu tiên trong ma trận (nếu có)
		int maxc;                           //Lưu gía trị chẵn lớn nhất nếu có
		int timthay = 0;                    //ghi nhận xem có tìm thấy số chẵn nào không 
		for (i = 0; i < d; i++)
			for (j = 0; j < c; j++)
				if (a[i][j] % 2 == 0)
				{
					timthay = 1;            //Đánh dấu lại là đã tìm thấy số chẵn 
					maxc = a[i][j];
					dmax = i;
					cmax = j;
					i = d;                  //Để vòng lặp for i thoát trong lần tới 
					break;                  //Để thoát khỏi vòng lặp for j ngay lập tức
				}
		//B2: Nếu tìm thấy số chẵn thì sẽ đi tiếp để tìm thấy số chẵn lớn hơn (nếu có)
		// Ngược lại thì kết luận mảng không có số chẵn 
		if (timthay == 0) cout << " Mang khong co so chan nao!\n";
		else
		{
			//Chap nhan duyet lai tu dau 
			for (i = 0; i < d; i++)
				for (j = 0; j < c; j++)
					if (a[i][j] % 2 == 0 && a[i][j] > maxc)
					{
						maxc = a[i][j];
						dmax = i;
						cmax = j;
					}
			//In kết quả 
			cout << "  Gia tri lon nhat  = " << maxc << endl;
			cout << "  Vi tri xuat hien = (" << dmax << ", " << cmax << ")" << endl;
		}
		//Thao tác 6: Tìm dòng có tổng lớn nhất 
		int td = 0;             //Tổng của 1 dòng 
		int maxdong;            //Gia trị lớn nhất của 1 dòng 

		//B1: Tinh tong dong 0, gán cho maxdong 
		for (j = 0; j < c; j++)
			td += a[0][j];
		maxdong = td;
		dmax = 0;               //Vị trí của dòng có tổng lớn nhất 
		//B2: Duyệt từng dòng 
		for (i = 0; i < d; i++)
		{
			//Tính tổng dòng i
			td = 0;            //Vì sang dòng mới phải tính lại từ đầu 
			for (j = 0; j < c; j++)
				td += a[i][j];
			//So sánh tổng dòng i và maxdong, cập nhật lại nếu cần thiết 
			if (td > maxdong);
			{
				maxdong = td;
				dmax = i;
			}
			//B3: Kết luận 
			cout << " Dong co tong lon nhat: " << dmax << endl;
			cout << " Tong dong lon nhat = " << maxdong << endl;

		}
		//Thao tác 6b: Tìm cột có nhiều số chẵn nhất 
		int maxcot = 0;           //Số lượng số chẵn nhiều nhất của 1 cột 
		int cmax = 0;                 //Chỉ số của cột có nhiều số chẵn nhất 
		for (j = 0; j < c; j++)  //Duyệt theo từng cột 
		{
			//Đếm số lượng số chẵn trên cột j
			int dem = 0;
			for (j = 0; j < d; j++)
				if (a[i][j] % 2 == 0) dem++;
			//So sánh cập nhật lại maxcot và cmax nếu cần thiết 
			if (d > maxcot)
			{
				maxcot = d;
				cmax = j;
			}
		}
		cout << "  Cot co nhieu so chan nhat: " << maxc << endl;
		cout << " so luong so chan nhieu nhat tren 1 cot = " << maxcot << endl;
		/*
		//Thao tác 7a: Kiểm tra xem ma trận có chứa toàn số dương hay không
		//Tìm xem trong mảng có phần tử nào <= 0 hay không
		int kiemtra = 1;               //Biến cờ hiệu ghi nhận kết quả kiểm tra
									   //=1 nếu việc kiểm tra thỏa Đk, ngược lại = 0
		for ( i = 0; i < d; i++)
			for ( j = 0; j < c; j++)
				if (a[i][j] <= 0)      //Nếu phát hiện vi pham
				{
					kiemtra = 0;       //Ghi nhận vi phạm
					i = d;             //Thoát khỏi 2 vòng lặp
					break;
				}
		//Kết luận dựa vào giá trị của biến kiểm tra
		if (kiemtra == 1) cout << "Mang chua toan so duong!\n";
		else cout << "Mang khong chua toan so duong !\n";
		*/

		//Thao tác 7b: Kiểm tra xem ma trận có phải là ma trận đơn vị không 
		int kiemtra;
		if (d != c)            //Ma trận không vuông
			kiemtra = 0;
		else                  //Ma trận vuông 
		{
			kiemtra = 1;        //Giả sử đây là ma trận đơn vị
			for (i = 0; i < d; i++)
				for (j = 0; j < c; j++)  //Duyệt ma trận 
					if ((i == j && a[i][j] != 1) || (i != j && a[i][j] != 0))
					{
						kiemtra = 0;        //Ghi nhận vi phạm 
						i = d;         //Thoát khỏi 2 vòng lặp 
						break;
					}

		}
		//Kết luận
		if (kiemtra == 1) cout << "Day la ma tran don vi!\n ";
		else cout << "Day khong phai la ma tran don vi!\n ";
		//Thao tác 7c: Kiểm tra xem ma trận có phải là ma trận tam giác trên/dưới không
		int arr[MAX * MAX];
		int n = 0;         //Sẽ tăng dần lên mỗi lần thêm 1 phần tử vào cuối arr
		//B1: Nối các dòng ma trận a để tạo mảng 1 chiều arr có kích thước dxc
		for (i = 0; i < d; i++)
			for (j = 0; j < c; j++)
				arr[n++] = a[i][j];          //Thêm a[i][j] vào cuối mảng arr
		//B2: Thao tác phụ: kiểm tra xem mảng 1 chiều (arr,n) có thứ tự tăng hay không 
		int tang = 1;    //Biến kiểm tra 
		for ( i = 0; i < n -1; i++)
			if (a[i] > a[i + 1])
			{
				tang = 0;      //Ghi nhận vi phạm
				break;         //Dừng việc kiểm tra 

			}
		//B3: Kết luận dựa vào giá trị của biến tăng 
		if (tang) cout << "ma trận tăng dần từ trái qua phải,từ trên xún dưới!\n";
		else cout << "Mang khong thoa tinh chat!\n";
		//Thao tác 7d: Kiểm tra xem ma trận có tăng dần từ trái qua phải,từ trên xún dưới không

		//Thao tác 8: Công 2 ma trận cùng cấp
		//Duyệt từng ô của ma trận c, Tinh tóan giá trị của nó dựa vào giá trị của A và B
		for (i = 0; i < d; i++)
			for (j = 0; j < c; j++)
				C[i][j] = A[i][j] = B[i][j];
		//Thao tác 9: Nhân 2 ma trận A(mxn) và ma trận B(nxp) - -> C(mxp)
		//Duyệt qua C
		for (i = 0; i < m; i++)
			for (j = 0; j < p; j++)
			{
				C[i][j] = 0;      //Lúc đầu bằng 0 
				for (k = 0; k < n; k++)
					C[i][j] += A[i][k] * B[k][j];
			}
				MatrixInput(a, d, c);
		cout << "The maxtrix just input:\n";
		MatrixOutput(a, d, c);
		int t = MatrixSumming(a, d, c);
		cout << "Total of all elements = " << t << endl;

		int minval, ipos, jpos;
		minval = FindMinAndPos(a, d, c, ipos, jpos);
		//sử dụng 3 giá trị thu được.

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
			if (m[i][j] > min)
			{
				min = m[i][j];
				dmin = i;
				cmin = j;
			}
	return min;
}
