#include <iostream>
//#define PIE 3.141592

using namespace std;

int main() {
	/*C++는 복합데이터형을 제공
	-> 사용자 정의대로 새로운 데이터형을 만들 수 있다
	복합데이터형 : 기본 정수형과 부동소수점형의 조합
	*/
	/*
	배열(arry) : 같은 데이터형의집합
	typeName arrayName[arraySize];
	*/

	short month[12] = { 1,2,3 };

	cout << month[1] << endl;

	/*
	배열 원소에 대입합 값들을 콤마로 구분하여 중괄호로 묶어 선언한다.
	초기화를 선언 이후에 나중에 불가하다
	배열을 다른 배열에 통째로 대입할 수 없다.
	아래와 같이 사용 불가
	short month[5] = {...}
	shrot year[12] = {...}
	year = month; 

	초기화 값의 개수를 배열 원소의 개수보다 적게 제공 가능
	배열을 부분적으로 초기화하면, 나머지 원소들은 모두 0으로 초기화
	즉, 명시적으로 첫 번째 원소만 0으로 초기화하면, 나머지 원소들은 모두 0으로 초기화
	배열을 초기화할때 대괄호 속을 비워두면 컴파일러가 초기화 값의 개수를 헤아려 배열 원소 개수를 저장
	*/
	// 문자열 : 문자의 열.
	char a[6] = { 'H', 'E', 'L', 'L', 'O', '\0'};
	char b[] = "Hello";
	cout << a << endl; 
	cout << b << endl;

	return 0;
}

