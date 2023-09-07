#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int num;

	cin >> num;

	for (int i = 0; i < 9; i++) {
		cout << num << " * " << (i + 1) << " = " << num * (i + 1) << endl;
	}

}