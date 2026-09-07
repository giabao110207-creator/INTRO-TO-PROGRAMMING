// Buoi08_Mang1D.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <time.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define MAX 100			//số phần tử tối đa

//Khai báo hàm
//1. Nhập mảng
void nhapmang(int a[], int n);
//2. In mảng
void inmang(int a[], int n);
//3. Tạo mảng chứa giá trị ngẫu nhiên
void taomang(int a[], int n, int x, int y);
//3.1 Tạo 1 số ngẫu nhiên thuộc đoạn [a, b]
int songaunhien(int a, int b);
//Hàm phụ: kiểm tra nguyên tố
bool ktnt(int n);

//Các thao tác liên quan đến việc XÓA phần tử
//4. Xóa phần tử tại vị trí k cho trước (0<=k<n)
void xoavitri(int a[], int& n, int k);
//5.1 Xóa phần tử đầu tiên bằng x có trong mảng
void xoaxdau(int a[], int& n, int x);
//5.2 Xóa phần tử cuối cùng bằng x có trong mảng
void xoaxcuoi(int a[], int& n, int x);
//5.3 Xóa số chẵn đầu tiên của mảng (nếu có)
void xoachandau(int a[], int& n);
//5.4 Xóa số lẻ cuối cùng của mảng (nếu có)
void xoalecuoi(int a[], int& n);
//5.5 Xóa tất cả các phần tử bằng x khỏi mảng
void xoatatca(int a[], int& n, int x);
//6.1 Xóa số nguyên tố đầu tiên trong mảng (nếu có)
void xoatdau(int a[], int& n);
//6.2 Xóa số chính phương cuối cùng trong mảng (nếu có)
void xoachinhphuongcuoi(int a[], int& n);
bool ktschinhphuong(int n);                               //Hàm phụ kiểm tra chính phương:
//6.3 Xóa tất cả các số hoàn hảo ra khỏi mảng (nếu có)
void xoasohoanhao(int a[], int& n);
bool ktsohoanhao(int n);                                  //Hàm phụ kiểm tra số hoàn hảo
//6.4 Xóa tất cả các phần tử nguyên tố cùng nhau với số x cho trước
//VD:	3	5	4	9	1
//	x = 6
//KQ:	3	4	9
void xoanguyentocungnhau(int a[], int& n, int x);
int UCLN(int a, int b);                                    //Hàm phụ UCLN 
//6.7 Xóa tất cả các phần tử xuất hiện từ 3 lần trở lên trong mảng
void xoaxuathien3lan(int a[], int& n);
//6.8 Xóa tất cả các phần tử trùng nhau, chỉ chừa lại 1 phần tử đầu làm đại diện
void xoatrunggiulai1(int a[], int& n);
//6.9 Xóa tất cả các phần tử trùng nhau trong mảng
void xoatatcatrung(int a[], int& n);
//10. Chèn giá trị x vào vị trí k cho trước trong mảng
void chenvitri(int a[], int& n, int x, int k);
//11. Chèn x vào sau số nguyên tố đầu tiên trong mảng.
//Nếu mảng ko có số nguyên tố nào thì thêm x vào cuối mảng
void chensaungto(int a[], int& n, int x);
//12. Cho a là mảng tăng dần, chèn x vào a sao cho a vẫn tăng sau khi chèn
void chentang(int a[], int& n, int x);

//Nhóm thao tác sắp xếp
//Hàm phụ: hoán đổi nội dung của 2 biến số nguyên
void hoanvi(int x, int y);
//13.1 Sắp xếp mảng tăng dần
void saptang(int a[], int n);
//13.2 Sắp xếp mảng giảm dần
void sapgiam(int a[], int n);
//13.3 Sắp xếp mảng sao cho các số chẵn tăng dần, số lẻ giữ nguyên vị trí
void sapchantang(int a[], int n);
//13.4 Sắp xếp mảng sao cho các sô chẵn đổi chỗ cho nhau và tăng dần
//các số lẻ đổi chỗ cho nhau và giảm dần
void sapchantanglegiam(int a[], int n);
//13.5 Sắp xếp mảng sao cho số chẵn về đầu, số lẻ về cuối mảng
void sapchandaulecuoi(int a[], int n);
//13.6 Sắp xếp mảng sao cho số chẵn về đầu và tăng dần,
//số lẻ về cuối và giảm dần
void sapchandautanglecuoigiam(int a[], int n);

//Nhóm kiểm tra tính chất mảng
//14.1 Kiểm tra xem mảng có chứa số âm không
bool chuasoam(int a[], int n);
//14.2 Kiểm tra xem mảng có chứa toàn số âm không
bool chuatoansoam(int a[], int n);
//14.3 Kiểm tra xem mảng có thứ tự tăng hay không
bool kttang(int a[], int n);
//14.4 Kiểm tra xem các số chẵn của mảng có thứ tự tăng hay không
bool ktchantang(int a[], int n);
//14.5 Kiểm tra xem mảng có tính chất âm dương xen kẽ hay không
//14.6 Kiểm tra xem mảng có tính chất chẵn lẻ xen kẽ hay không
//14.7 Kiểm tra xem mảng có tính chất tăng giảm xen kẽ hay không
//14.8 Kiểm tra xem các phần tử của mảng có lập thành cấp số cộng không

//Nhóm thao tác trên 2 hay nhiều mảng 1 chiều
//15. Tách mảng (a,n) thành 2 mảng con:
//(mc, nc) chứa các số chẵn, (ml, nl) chứa các số lẻ
void tachmangchanle(int a[], int n, int mc[], int& nc, int ml[], int& nl);
//16. Trộn 2 mảng (a, na) và (b, nb) đã có thứ tự tăng dần
//thành mảng (c, nc) sao cho mảng c vẫn có thứ tự tăng dần
//17.1 Kiểm tra xem 2 mảng a và b có bằng nhau không (giống nhau hoàn toàn)
//17.2 Kiểm tra xem mảng (a, na) có chứa mọi phần tử của mảng (b, nb) không
//VD:	a	2	1	4	9
//		b	1	4	1
//17.3 Kiểm tra xem 2 mảng (a, na) và (b, nb) có cùng tập các phần tử ko
//VD:	a	2	1	4	2
//		b	4	2	1
//17.4 Tìm TẬP các phần tử (không trùng nhau) của mảng (a, na)
//VD:	a	2	1	2	2	4	1
//KQ:		1	2	4
//17.5 Tìm TẬP các phần tử chung (giống nhau) của 2 mảng (a, na) và (b, nb)
//VD:	a	2	1	9	2	4	1
//		b	4	2	2	6
//KQ:		2	4


int main()
{
	{
		srand(time(NULL));			//để tạo bộ số ngẫu nhiên mới
		int a[MAX], n;
		cout << "Nhap so phan tu:";
		cin >> n;
		taomang(a, n, 1, 9);		//giá trị từ 1 đến 9
		cout << "Mang ban dau:\n";
		inmang(a, n);
		////xóa số 5 đầu tiên trong mảng (nếu có) rồi in kết quả
		//xoaxdau(a, n, 5);
		//xoachandau(a, n);
		//xoalecuoi(a, n);
		//chensaungto(a, n, 0);		//chèn số 0 vào sau snt đầu tiên trong mảng
		sapchantang(a, n);
		cout << "Mang ket qua:\n";
		inmang(a, n);
		return 0;
	}

	int u = 10, v = 30;              //2 biến nguyên 
	cout << "Gia tri ban dau:\n";
	cout << u << endl << v << endl;
	hoanvi(u, v);                 //Thực hiện hoán đổi 
	cout << "Gia tri sau khi hoan doi:\n";
	cout << u << endl << v << endl;
	return 0;
}

//Định nghĩa hàm
//Hàm phụ: hoán đổi nội dung của 2 biến số nguyên
void hoanvi(int x, int y)
{
	int t = x;
	x = y;
	y = t;

}
//1. Nhập mảng
void nhapmang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap phan tu thu " << i << ":";
		cin >> a[i];
	}
}
//2. In mảng
void inmang(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "  ";
	cout << endl;
}
//3. Tạo mảng chứa giá trị ngẫu nhiên thuộc đoạn [x, y]
void taomang(int a[], int n, int x, int y)
{
	for (int i = 0; i < n; i++)
		a[i] = songaunhien(x, y);
}
//3.1 Tạo 1 số ngẫu nhiên thuộc đoạn [a, b] (a<=b)
int songaunhien(int a, int b)
{
	if (a > b) return 0;			//lỗi
	return a + rand() % (b - a + 1);
}

//Các thao tác liên quan đến việc XÓA phần tử
//4. Xóa phần tử tại vị trí k cho trước (0<=k<n)
void xoavitri(int a[], int& n, int k)
{
	if (k < 0 || k >= n) return;		//k ko hợp lệ thì nghỉ sớm!
	for (int i = k + 1; i < n; i++)		//dồn lên
		a[i - 1] = a[i];
	n--;								//số phần tử giảm đi
}
//5.1 Xóa phần tử đầu tiên bằng x có trong mảng
void xoaxdau(int a[], int& n, int x)
{
	//B1. Tìm vị trí xuất hiện đầu tiên của x
	int i = 0;		//xuất phát từ đầu mảng
	while (i < n && a[i] != x) i++;		//đi tìm x
	//B2. Nếu có thì xóa phần tử tại vị trí đó
	if (i < n)							//tìm thấy x tại vị trí i
		xoavitri(a, n, i);				//thì xóa nó đi
}
//5.2 Xóa phần tử cuối cùng bằng x có trong mảng
void xoaxcuoi(int a[], int& n, int x)
{
	//B1. Tìm vị trí xuất hiện đầu tiên của x
	int i = n - 1;		//xuất phát từ cuối mảng
	while (i >= 0 && a[i] != x) i--;	//đi tìm x
	//B2. Nếu có thì xóa phần tử tại vị trí đó
	if (i >= 0)							//tìm thấy x tại vị trí i
		xoavitri(a, n, i);				//thì xóa nó đi
}
//5.3 Xóa số chẵn đầu tiên của mảng (nếu có)
void xoachandau(int a[], int& n)
{
	//B1. Tìm vị trí xuất hiện đầu tiên của số chẵn
	int i = 0;		//xuất phát từ đầu mảng
	while (i < n && a[i] % 2 != 0) i++;	//đi tìm số chẵn
	//B2. Nếu có thì xóa phần tử tại vị trí đó
	if (i < n)							//tìm thấy số chẵn tại vị trí i
		xoavitri(a, n, i);				//thì xóa nó đi
}
//5.4 Xóa số lẻ cuối cùng của mảng (nếu có)
void xoalecuoi(int a[], int& n)
{
	//B1. Tìm vị trí xuất hiện cuối cùng của số lẻ
	int i = n - 1;		//xuất phát từ cuối mảng
	while (i >= 0 && a[i] % 2 == 0) i--;	//đi tìm số lẻ
	//B2. Nếu có thì xóa phần tử tại vị trí đó
	if (i >= 0)							//tìm thấy số lẻ tại vị trí i
		xoavitri(a, n, i);				//thì xóa nó đi
}
//5.5 Xóa tất cả các phần tử bằng x khỏi mảng
void xoatatca(int a[], int& n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
		{
			xoavitri(a, n, i);         //xóa phần tử tại vị trí i
			i--;                       //lùi lại để kiểm tra phần tử vừa dồn lên
		}
	}
}

//6.1 Xóa số nguyên tố đầu tiên trong mảng (nếu có)
void xoatdau(int a[], int& n)
{
	int i = 0;
	while (i < n && !ktnt(a[i])) i++;

	if (i < n)
		xoavitri(a, n, i);
}

//Hàm phụ kiểm tra chính phương:
bool ktschinhphuong(int n)
{
	if (n < 0) return false;
	int t = (int)sqrt(n);
	return t * t == n;
}
//6.2 Xóa số chính phương cuối cùng trong mảng (nếu có)
void xoachinhphuongcuoi(int a[], int& n)
{
	int i = n - 1;
	while (i >= 0 && !ktschinhphuong(a[i])) i--;

	if (i >= 0)
		xoavitri(a, n, i);
}

//Hàm phụ kiểm tra số hoàn hảo
bool ktsohoanhao(int n)
{
	if (n <= 0) return false;

	int sum = 0;
	for (int i = 1; i <= n / 2; i++)
		if (n % i == 0)
			sum += i;

	return sum == n;
}
//6.3 Xóa tất cả các số hoàn hảo ra khỏi mảng (nếu có)
void xoasohoanhao(int a[], int& n)
{
	for (int i = 0; i < n; i++)
	{
		if (ktsohoanhao(a[i]))
		{
			xoavitri(a, n, i);
			i--; // kiểm tra lại vị trí vừa dồn
		}
	}
}
//Hàm phụ UCLN 
int UCLN(int a, int b)
{
	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}
//6.4 Xóa tất cả các phần tử nguyên tố cùng nhau với số x cho trước
void xoanguyentocungnhau(int a[], int& n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (UCLN(a[i], x) == 1)
		{
			xoavitri(a, n, i);
			i--;
		}
	}
}

//6.7 Xóa tất cả các phần tử xuất hiện từ 3 lần trở lên trong mảng
void xoaxuathien3lan(int a[], int& n)
{
	for (int i = 0; i < n; i++)
	{
		int dem = 0;

		for (int j = 0; j < n; j++)
			if (a[j] == a[i])
				dem++;

		if (dem >= 3)
		{
			for (int j = i; j < n; j++)
			{
				if (a[j] == a[i])
				{
					xoavitri(a, n, j);
					j--;
				}
			}
			i--;
		}
	}
}

//6.8 Xóa tất cả các phần tử trùng nhau, chỉ chừa lại 1 phần tử đầu làm đại diện
void xoatrunggiulai1(int a[], int& n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int k = i + 1; k < n; k++)
		{
			if (a[i] == a[k])
			{
				xoavitri(a, n, k);
				k--;
			}
		}
	}
}
//6.9 Xóa tất cả các phần tử trùng nhau trong mảng
void xoatatcatrung(int a[], int& n)
{
	for (int i = 0; i < n; i++)
	{
		int dem = 0;

		for (int k = 0; k < n; k++)
			if (a[k] == a[i])
				dem++;
		if (dem > 1)
		{
			for (int k = i; k < n; k++)
			{
				if (a[k] == a[i])
				{
					xoavitri(a, n, k);
					k--;
				}
			}
			i--;
		}
	}
}

//10. Chèn giá trị x vào vị trí k cho trước trong mảng
void chenvitri(int a[], int& n, int x, int k)
{
	if (k<0 || k>n) return;			//vị trí ko hợp lệ
	for (int i = n - 1; i >= k; i--)//dời ra sau
		a[i + 1] = a[i];
	a[k] = x;						//đưa x vào vị trí k
	n++;							//số phần tử tăng lên
}
//11. Chèn x vào sau số nguyên tố đầu tiên trong mảng.
//Nếu mảng ko có số nguyên tố nào thì thêm x vào cuối mảng
void chensaungto(int a[], int& n, int x)
{
	//B1. Tìm vị trí của số nguyên tố đầu tiên (nếu có)
	int i = 0;
	while (i < n && !ktnt(a[i])) i++;
	//B2. Chèn x vào sau vị trí đó (nếu gặp)
	if (i < n) chenvitri(a, n, x, i + 1);
	//Ngược lại thêm x vào cuối mảng
	else a[n++] = x;
}
//12. Cho a là mảng tăng dần, chèn x vào a sao cho a vẫn tăng sau khi chèn
void chentang(int a[], int& n, int x)
{
	//B1. Tìm phần tử đầu tiên lớn hơn x
	int i = 0;
	while (i < n && a[i] <= x) i++;
	//B2.1 Nếu có thì chèn x vào tại vị trí đó
	if (i < n) chenvitri(a, n, x, i);
	//B2.2 Ngược lại thì thêm x vào cuối mảng
	else a[n++] = x;
}

//Hàm phụ: kiểm tra nguyên tố
bool ktnt(int n)
{
	if (n < 2) return false;
	int c = (int)sqrt(n);		//tính căn bậc 2
	for (int i = 2; i <= c; i++)
		if (n % i == 0) return false;
	return true;
}

//Nhóm thao tác sắp xếp
//Hàm phụ: hoán vị giá trị 2 biến nguyên
void swap(int& a, int& b)
{
	int t = a; a = b; b = t;
}
//13.1 Sắp xếp mảng tăng dần
void saptang(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j]) swap(a[i], a[j]);
}
//13.2 Sắp xếp mảng giảm dần
void sapgiam(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] < a[j]) swap(a[i], a[j]);
}
//13.3 Sắp xếp mảng sao cho các số chẵn tăng dần, số lẻ giữ nguyên vị trí
void sapchantang(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		if (a[i] % 2 == 0)
		{
			for (int j = i + 1; j < n; j++)
				if (a[j] % 2 == 0 && a[i] > a[j]) swap(a[i], a[j]);
		}
}
//13.4 Sắp xếp mảng sao cho các sô chẵn đổi chỗ cho nhau và tăng dần
//các số lẻ đổi chỗ cho nhau và giảm dần
void sapchantanglegiam(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		if (a[i] % 2 == 0)
		{
			for (int j = i + 1; j < n; j++)
				if (a[j] % 2 == 0 && a[i] > a[j])
					swap(a[i], a[j]);
		}
		else {			//a[i] là số lẻ
			for (int j = i + 1; j < n; j++)
				if (a[j] % 2 != 0 && a[i] < a[j])
					swap(a[i], a[j]);
		}
}
//13.5 Sắp xếp mảng sao cho số chẵn về đầu, số lẻ về cuối mảng
void sapchandaulecuoi(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] % 2 != 0 && a[j] % 2 == 0)
				swap(a[i], a[j]);
}
//13.6 Sắp xếp mảng sao cho số chẵn về đầu và tăng dần,
//số lẻ về cuối và giảm dần
void sapchandautanglecuoigiam(int a[], int n)
{
	sapchandaulecuoi(a, n);
	sapchantanglegiam(a, n);
}

//14.1 Kiểm tra xem mảng có chứa số âm không
bool chuasoam(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
			return true;
	}
	return false;
}
//14.2 Kiểm tra xem mảng có chứa toàn số âm không
bool chuatoansoam(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] >= 0)
			return false;
	}
	return true;
}

//14.3 Kiểm tra xem mảng có thứ tự tăng hay không
bool kttang(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] > a[i + 1])
			return false;
	}
	return true;
}

//14.4 Kiểm tra xem các số chẵn của mảng có thứ tự tăng hay không
bool ktchantang(int a[], int n)
{
	int k = -1;

	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			if (k != -1 && a[i] < k)
				return false;

			k = a[i];
		}
	}
	return true;
}