#include <iostream>
#include <cmath>
using namespace std;

void inRaSoNguyen(int *a, int n) {
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 100 + 10;  
		cout << "mang thu a[" << i << "] = " << a[i] << endl;  // Print the array values
	}
}

void soNguyenTo(int x) {
	for (int i = 2; i <= x; i++) {
		bool isPrime = true;
		for (int j = 2; j * j <= i; j++) {
			if (i % j == 0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime) {
			cout << i << " is prime" << endl;
		}
	}
}

void inRaDiaChiSNT(int *a, int n) {
	for (int i = 0; i < n; i++) {
		cout << "Address of a[" << i << "] = " << &a[i] << endl;  // Print the address of each element
	}
}

void kiemTraChan(int *a, int n) {
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			cout << "Even number a[" << i << "] = " << a[i] << endl;
		}
	}
}

int demSoLuong(int *a, int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0)
			count++;
	}
	return count;
}

int main() {
	int *a = NULL, n;
	do {
		cout << "vui long nhap so luong phan tu " << " ";
		cin >> n;
	} while (n <= 0 || n > 50);

	a = new int[n];
	inRaSoNguyen(a, n);
	inRaDiaChiSNT(a, n);
	kiemTraChan(a, n);
	cout << "So luong phan tu chan: " << demSoLuong(a, n) << endl;
	delete[] a;
	return 0;
}
