// Buoi12_ChuoiKyTu.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;

//Đếm số lần xuất hiện của 1 ký tự trong 1 chuỗi 
int DemKyTu(char s[], char ch)
{
    int len = strlen(s);      //Chiều dài chuỗi (Số ký tự có trong chuỗi)
    int dem = 0;
        for (int i = 0; i < len; i++)
            if (s[i] == ch) dem++;
    return dem;
}

//Đếm số Từ trong chuỗi bất kỳ. Từ = dãy liên tiếp ký tự khác trắng,
//Ngăn cách nhau bởi it nhất 1 ký tự trắng 
// VD: s =" Le   Thi  Hong gam " --> 4 TỪ 
int DemTu(char s[])
{
    if (s[0] == NULL) return 0;           //Chuỗi rỗng 
    int sotu = 0;
    int len = strlen(s);
    if (s[0] != 32) sotu++;               //Có từ đầu tiên 
    for (int i = 1; i < len; i++)
        if (s[i] != 32 && s[i - 1] == 32) sotu++;
    return sotu;
}

//Viết hoa ký tự đầu mỗi từ, viết thuờng tất cả những ký tự còn lại 
void VietHoaDauTu(char s[])
{
    s[0] = toupper(s[0]);             //tolower
    int len = strlen(s);
    for (int i = 1; i < len; i++)
        if (s[i - 1] == 32) s[i] = toupper(s[i]);
        else s[i] = toupper(s[i]);
}
int main()
{
    //1. Khai báo biến kiểu chuỗi 
    char hoten[50];      //C chuẩn
    char temp[50];
    string s;            //C++

    cin.getline(hoten, 50);
    cout << "Chuoi vua nhap:\n" << hoten << endl;
    /*
    //Một số hàm xử lý chuỗi có sẵn trong thư viện string.h
    //1. Tính chiều dài chuỗi
    cout << "Chieu dai chuoi:" << strlen(hoten) << endl;
    //2. Sao chép / gán chuỗi
    strcpy_s(temp, hoten);
    cout << " Chuoi duoc sao chep:\n " << temp << endl;
    //3. Nối chuỗi
    strcat_s(temp, " xin chao cac ban!");
    cout << "Chuoi duoc noi them:\n " << temp << endl;
    //4. strset: điền toàn bộ chuỗi bằng 1 ký tự giống nhau
    //5. so sánh 2 chuỗi
    int kq = _stricmp("Thanh", "Thao");
    if (kq < 0) cout << "s1 < s2 ";
    else if (kq == 0) cout << "s1 = s2";
    else cout << "s1 > s2";
    //6. Tìm ký tự trong chuỗi
    if (strchr(hoten, 'e') == NULL) cout << "Ten KO co ky tu e\n";
    else cout << strchr(hoten, 'e') << endl;
    //7. Tìm chuỗi con trong chuỗi lớn
    if (strstr(hoten, "Thi") == NULL) cout << "Ten KO co ky tu Thi\n";
    else cout << strstr(hoten, "Thi") << endl;
    //8. Đổi chữ hoa/thường
    _strupr_s(hoten);
    cout << "Ho ten chu IN HOA:\n" << hoten << endl;
    _strlwr_s(hoten);
    cout << "Ho ten chu thuong:\n" << hoten << endl;
    */

    cout << "So ky tu a: " << DemKyTu(hoten, 'a') << endl;
    cout << "Sotu: " << DemTu(hoten) << endl;
    VietHoaDauTu(hoten);
    cout << "Chuoi viet hoa dau tu:\n" << hoten << endl;

}

