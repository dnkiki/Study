#include <iostream>

using namespace std;

int main() {
	char char1[20];
	char char2[20] = "jaguar";
	string str1;
	string str2 = "panda";
	//char = char2; ���ڿ��� ���� ���� �Ұ�

	str1 = str2; // string�� ���� ������ ����
	cout << str1 << endl;
	return 0;
}