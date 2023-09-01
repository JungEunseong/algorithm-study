#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;

int main() {
	int number[5];
	int result = 0;

	for (int i = 0; i < 5; i++)
		cin >> number[i];
	
	for (int i = 0; i < 5; i++) {
		result += pow(number[i], 2);
	}

	cout << result % 10 << endl;
	
}