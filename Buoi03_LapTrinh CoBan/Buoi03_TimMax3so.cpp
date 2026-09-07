# include <iostream>
using namespace std;
int main() 
{ 
	int a, b, c, max;      //khai bao bien 
	//B1. Nhap 3 so nguyen 
    Cout << "Nhap a:";
	cin >> a;
	Cout << "Nhap b:";
	cin >> b;
	Cout << "Nhap c:";
	cin >> c;
	//B@. Tim max
	max = (a>b) ? a:b;    //phep toan dieu kien 
	max = (c>max) c:max;
	//B3. in ket qua 
	cout << "so lon nhat = " << max << endl
}
