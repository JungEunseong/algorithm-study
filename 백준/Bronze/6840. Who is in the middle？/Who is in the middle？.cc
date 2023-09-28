#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
	vector<int> numbers;

	
	for (int i = 0; i < 3; i++) {
		int tmp = 0;
		cin >> tmp;

		numbers.push_back(tmp);
	}


	sort(numbers.begin(), numbers.end());

	cout << numbers[numbers.size() / 2];

}	