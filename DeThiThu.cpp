#include<iostream>
using namespace std;

void inRaSoNguyen(int *a, int& n)
{
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 100 + 10;
		cout << "mang thu a[" << i << "] = " << a[i];

	}
}



void inRaDiaChiSNT(int *a, int& n){

	for (int i = 2; i < n; i++)
	{
		for (int j = 2; j*j <= i; j++)
		{
			if (i%j == 0)
				break;
			else if (j + 1 > sqrt(i)) {
				cout << i << endl;
				cout << "mang thu a[" << i << "] = " << &a[i];
			}

		}
	}
	

}

int kiemTraChan(int *a, int n){
	for (int i = 0; i < n; i++)
	{

		if (n % 2 == 0)
			cout << *(a + i);
	}
}

int demSoLuong(int *a, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0)
			count++;
	}
	return count;
}



int main() {
	//khai báo 
	
	int *a = NULL, n;
	do
	{
		cout << "vui long nhap so luong phan tu " << " ";
		cin >> n;
	} while (n<=0||n>50);
	
	a = new int[n];
    
	inRaSoNguyen(a, n);

	inRaDiaChiSNT(a, n);

	cout << demSoLuong(a, n);
	delete[] a;

	return 1;
 }