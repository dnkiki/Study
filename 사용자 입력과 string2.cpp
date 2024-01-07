#include <iostream>

using namespace std;

int main() {
	char char1[20];
	char char2[20] = "jaguar";
	string str1;
	string str2 = "panda";
	//char = char2; 문자열은 직접 대입 불가

	str1 = str2; // string은 직접 대입이 가능
	cout << str1 << endl;
	return 0;
}