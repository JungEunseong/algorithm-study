#include <iostream>
#include <string.h>

using namespace std;

int main() {
	int starCount;

	cin >> starCount;

	for (int i = 0; i < starCount; i++) {
		for (int j = 0; j <= i; j++) {
			cout << "*";
		}

		cout << endl;
	}
}