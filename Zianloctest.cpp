#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void isSpaceFirst(char*str, int& len) {
	//xóa khoảng trắng đầu chuỗi 
	for (int i = 0; i < len; i++) {
		if (isspace(str[i]) == true)
		{
			for (int j = 0; j < len; j++)
			{
				str[j] = str[j + 1];
				len--;
				i--;
			}
		}
		else break;
	}

	//xóa khoảng trắng ở cuối chuỗi 
	while (isspace(str[len - 1]) == true)
	{
		str[len - 1] = '\0';
		len--;
	}


	//xóa khaorng trắng ở giữa chuỗi 

	for (int i = 0; i < len; i++)
	{
		if (isspace(str[i]) || isspace(str[i + 1])) {
			for (int j = 1; j < len; j++) {
				str[j] = str[j + 1];
				len--;
				i--;
			}
		}
	}

}



void capital(char *str, int& len) {
	//viết hoa kí tự đầu của mỗi từ 

	for (int i = 0; i < len; i++) {
		if (i == 0 || isspace(str[i - 1]))
		{
			str[i] = toupper(str[i]);
		}
		else
		{
			str[i] = tolower(str[i]);
		}
	}


}

int main() {
	//"  tRuong  dAi  hOc  mo  tpHCM "

	char str[] = "  tRuong  dAi  hOc  mo  tpHCM ";
	int len = strlen(str);


	isSpaceFirst(str, len);
	capital(str, len);

	cout << str << " ";

	return 1;


}
