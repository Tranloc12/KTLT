#include <iostream>
#include <time.h>
using namespace std;
#define MAX 100

void nhapmang(int &n)
{
	do {
		cout << "vui long nhap so luong mang (1-" << MAX << "): ";
		cin >> n;
		if (n <= 0 || n > MAX) {
			cout << "Vui lòng nhập lại." << endl;
		}
	} while (n <= 0 || n > MAX);

}
// Nhập mảng 1 chiều bằng con trỏ
void inputArr(int*& a, int& n) {

	nhapmang(n);

	a = new int[n]; // Cấp phát bộ nhớ

	for (int i = 0; i < n; i++) {
		cout << "Nhap mang a[" << i << "]: ";
		cin >> *(a + i); // Nhập giá trị cho mảng
	}
}

void outputArr(int* a, int n) {
	if (a != NULL)
	{
		cout << "Mang ban nhap la: ";
		for (int i = 0; i < n; i++) {
			cout << *(a + i) << "\t"; // Xuất giá trị của mảng
		}
		cout << endl;
	}

}

int* concat(int* a, int n, int* b, int m) {
	int* c = new int[n + m]; // Cấp phát cho mảng kết hợp
	int l = 0;

	for (int i = 0; i < n; i++) {
		c[l++] = a[i]; // Sao chép từ a
	}

	for (int j = 0; j < m; j++) {
		c[l++] = b[j]; // Sao chép từ b
	}
	return c; // Trả về mảng kết hợp
}

void hoanvi(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}

void DaoNguocMang(int *a, int n)
{
	int *l = a;
	int *r = (a + n - 1);
	while (l < r)
	{
		hoanvi(*l++, *r--);
	}


}
int* timMAX(int *a, int n) {
	if (a != NULL)
	{
		int vtMax = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] > a[vtMax])
			{
				a[vtMax] = i;
			}
			return &a[vtMax];
		}

	}
	return NULL;
}

int random(int *a, int n) {
	nhapmang(n);
	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		*(a + 1) = rand() * 100 % +1;
	}
}

int main() {
	int* a = NULL, n; // Khai báo mảng a
	int* b = NULL, m; // Khai báo mảng b
	int* c = NULL, l; // Khai báo mảng kết hợp

	// Nhập và xuất mảng a
	inputArr(a, n);
	outputArr(a, n);

	//// Nhập và xuất mảng b
	inputArr(b, m);
	outputArr(b, m);
	cout << "RANDOM";
	srand((int)time(NULL));
	random(a, n);

	// Kết hợp và xuất mảng c
	l = n + m;
	c = concat(a, n, b, m);
	cout << "Mảng kết hợp là: ";
	outputArr(c, n + m);
	DaoNguocMang(a, n);
	cout << "MANG DAO NGUOC\n";
	outputArr(a, n);
	cout << "SO LON NHAT\n";
	cout << timMAX(a, n);
	outputArr(a, n);

	// Giải phóng 
	delete[] a;
	delete[] b;
	delete[] c;

	return 1;
}
