#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	string num;

	cin >> num;


	sort(num.rbegin(), num.rend());

	cout << num << endl;
}