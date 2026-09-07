# include <iostream>
using namespace std;
int main() 
{ 
	float a, b, b, max_2, max_1;
	//B1. Nhap 3 so nguyen 
    Cout << "Nhap a:";
	cin >> a;
	Cout << "Nhap b:";
	cin >> b;
	Cout << "Nhap c:";
	cin >> c;
	//B2. Tim max
	if (a == b && b == c) Cout << "khong co so lon thu nhi!\n";
	else
	{ 
		if (a < b) { 
			t = a; a = b; b = t;
		}
		if (a < c) {
			t = a; a = c; c = t;
		}
		if (b < c) {
			t = b; b = c; c = t;
		}
		if (a > b) max = b
		else max = c
	}
	