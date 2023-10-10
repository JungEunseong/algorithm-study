#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


int main() {

	vector<int> nums;

	for (int i = 0; i < 9; i++) {
		int num;

		cin >> num;

		nums.push_back(num);
	}


	auto iterator = max_element(nums.begin(),nums.end());
	

	cout << *iterator << endl;

	cout << (iterator - nums.begin()) + 1;
}


