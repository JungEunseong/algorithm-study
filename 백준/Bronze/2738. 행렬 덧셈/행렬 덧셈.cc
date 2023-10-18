#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {

	int x, y;

	cin >> x >> y;

	vector<int> arr[2]{ vector<int>(),vector<int>() };
	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < x * y; i++) {
			int num;

			cin >> num;

			arr[j].push_back(num);
		}
	}

	for (int i = 0; i < x * y; i++) {
		cout << arr[0][i] + arr[1][i] << " ";

		if ((i + 1) % y == 0) cout << endl;
	}

}


