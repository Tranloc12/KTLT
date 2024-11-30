#include <iostream>
#include <ctime>
using namespace std; 

#define MAX 100

//Cau 1: Cap phat dong mang 1 chieu
void sinhMangNN(int *&a, int &n) {
	do {
		cout << "Nhap so luong phan tu: ";
		cin >> n;
		if (n <= 0 || n > MAX)
			cout << "Nhap sai! Nhap lai!\n";
	} while (n <= 0 || n > MAX);
	//Cap phat
	a = new int[n];
	for (int i = 0; i < n; i++)
		a[i] = rand() % 50 + 1;
}

void xuatMang(int *a, int n) {
	if (a != NULL) {
		for (int i = 0; i < n; i++) {
			cout << a[i] << "\t";
		}
		cout << endl;
	}
}

//Cau 2: Tim so nguyen to sau cung
bool isNguyenTo(int n) {
	if (n < 2)
		return false;
	else {
		for (int i = 2; i <= sqrt(n); i++) {
			if (n%i == 0)
				return false;
		}
		return true;
	}
}

int* findLastPrime(int *a, int n) {
	if (a != NULL) {
		for (int i = n - 1; i >= 0; i--) {
			if (isNguyenTo(a[i]) == true)
				return &a[i];
		}
	}
	return NULL;
}

//Cau 3: de quy duoi dem so chan trong mang
int demSoChan(int *a, int n, int count = 0) {
	if (n < 0)
		return count;

	if (a[n] % 2 == 0)
		return demSoChan(a, n - 1, count + 1);
	else
		return demSoChan(a, n-1, count);
}

//Cau 4: dung de quy sap xep mang 1 chieu
int asc(int a, int b) {
	if (a > b)
		return 1;
	else if (a < b)
		return -1;
	else
		return 0;
}

int desc(int a, int b) {
	return -asc(a, b);
}

void sapXep(int *a, int n, int cmp(int, int)=asc) {
	if (n == 1)
		return;
	sapXep(a, n-1, cmp);
	if (cmp(a[n-2], a[n - 1])==1) {
		swap(a[n-2], a[n - 1]);
		sapXep(a, n - 1, cmp);
	}
}

//Cau 5: Loc du lieu
void pushBackArr(int *&a, int &n, const int x) {
	if (a == NULL) {
		n = 1;
		a = new int[n];
		a[0] = x;
	}
	else {
		int *aPrev = a;

		a = new int[n + 1];
		int j = 0;
		for (int i = 0; i < n; i++)
			a[j++] = aPrev[i];
		a[n++] = x;

		delete[]aPrev;
		aPrev = NULL;
	}
}

bool isChan(const int x) {
	return x % 2 == 0;
}

bool isLe(int x) {
	return x % 2 != 0;
}

bool isAm(int x) {
	return x < 0;
}

int* filter(int *a, int n, int &sl, bool func(int)) {
	int *res = NULL;

	for (int i = 0; i < n; i++) {
		if (func(a[i]))
			pushBackArr(res, sl , a[i]);
	}

	return res;
}

int main() {
	int *a, n;
	srand((int)time(NULL));
	sinhMangNN(a, n);
	xuatMang(a, n);

	/*int *res = findLastPrime(a, n);
	if (res != NULL)
		cout << "SNT cuoi cung: " << res << " - " << *res << endl;
	else
		cout << "Khong co SNT nao!\n";

	cout << "So phan tu chan: " << demSoChan(a, n - 1) << endl;*/

	sapXep(a, n, asc);
	xuatMang(a, n);

	/*int *res, m;

	res = filter(a, n, m, isLe);
	cout << "=============LOC SO CHAN============\n";
	xuatMang(res, m);*/

	delete[]a;
	return 1;
}