#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void isSpaceFirst(char*str, int& len) {
	// Xóa khoảng trắng đầu chuỗi
	int i = 0;
	while (i < len && isspace(str[i])) {
		for (int j = i; j < len; j++) {
			str[j] = str[j + 1];
		}
		len--;
	}

	// Xóa khoảng trắng ở cuối chuỗi
	while (len > 0 && isspace(str[len - 1])) {
		str[len - 1] = '\0';
		len--;
	}

	// Xóa khoảng trắng ở giữa chuỗi
	i = 0;
	while (i < len - 1) {
		if (isspace(str[i]) && isspace(str[i + 1])) {
			for (int j = i + 1; j < len; j++) {
				str[j] = str[j + 1];
			}
			len--;
		}
		else {
			i++;
		}
	}
}

void capital(char *str, int& len) {
	// Viết hoa ký tự đầu của mỗi từ
	for (int i = 0; i < len; i++) {
		if (i == 0 || isspace(str[i - 1])) {
			str[i] = toupper(str[i]);
		}
		else {
			str[i] = tolower(str[i]);
		}
	}
}

char* token(char *str){

	char* res = new char(strlen(str));
	res[0] = '\0';
	char* token = strtok(str, " ");
	while (token != NULL)
	{
		strcat(res, token);
		token = strtok(NULL, " ");
		if (token != NULL) {
			strcat(res, " ");
		}
	}
	return res;




}

int main() {
	char str[] = "  tRuong  dAi  hOc  mo  tpHCM ";
	int len = strlen(str);

	//isSpaceFirst(str, len);
	//capital(str, len);
	char* res = token(str);
	cout << str << endl;
	delete[] res;
	return 0;
}
