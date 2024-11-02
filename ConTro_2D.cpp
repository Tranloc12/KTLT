#include <iostream>
using namespace std;
//mảng 2 chiều con trỏ chưa biết r,c 

void nhapMang(int** &a, int &r, int &c)
{
	do {

		cout << "vui long nhap so dong: " << " ";
		cin >> r;
		cout << "vui long nhap so cot: " << " ";
		cin >> c;
		if (r <= 0 || r > 100 || c <= 0 || r > 100)
		{
			cout << "vui long nhap lai" << " ";
		}

	} while (r <= 0 || r > 100 || c <= 0 || r > 100);

	//cấp phát dòng 
	a = new int*[r];
	//cấp phát cột
	for (int i = 0; i < r; i++)
	{

		a[i] = new int[c];
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << "mang a[" << i << "][" << j << "]"<<" ";
			cin >> a[i][j];
		}
	}
}
void xuatMang(int** a,  int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout<< a[i][j]<<"\t";
		}
		cout << endl;
	}
}




int main() {

	//khai báo
	int ** a, r, c;


	//cấp phát
	xuatMang(a, r, c);
	nhapMang(a, r, c);


	//thao tác


	//giải phóng 
	for (int i = 0; i < r; i++)
	{
		delete[] a[i];
	}

	delete[] a;

	return 1;

}