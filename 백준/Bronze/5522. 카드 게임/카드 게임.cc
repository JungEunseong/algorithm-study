#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {

	vector<int> nums;

	for (int i = 0; i < 5; i++) {
		int num;

		cin >> num;

		nums.push_back(num);
	}



	cout << accumulate(nums.begin(),nums.end(),0) << endl;
}


