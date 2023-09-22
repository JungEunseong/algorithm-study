	#include <iostream>
	#include <vector>

	using namespace std;

	int main() {

		vector<int> results{ 1, 1, 2, 2, 2, 8 };

		for (int i = 0; i < 6; i++) {
			int num;

			cin >> num;

			results[i] -= num;
		}

		for (int& n : results)
			cout << n << " ";
	}

