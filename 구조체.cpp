#include <iostream>
#include <cstring>

using namespace std;

int main() {
	struct MyStruct {
		string name;
		string position;
		int height;
		int weight;
	}B;

	MyStruct A;
	A.name = "son";
	A.position = "Striker";
	A.height = 184;
	A.weight = 78;



	/*MyStruct A = {
	"Son",
	"Striker",
	183,
	77
	};*/

	cout << A.name << endl;
	cout << A.position << endl;
	cout << A.height << endl;
	cout << A.weight << endl;

	B = { };

	cout << B.height << endl;

	MyStruct C[2] = {
		{"park", "mid", 177, 71},
		{"kim", "defence", 188, 82}
	};

	cout << C[0].name << endl;
	return 0;
}