#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	int xLen, yLen;

	cin >> yLen;
	cin >> xLen;

	vector<vector<int>> _2dArray;

	for (int i = 0; i < yLen; i++) {
		_2dArray.push_back(vector<int>());
		for (int j = 0; j < xLen; j++) {
			int num;
			cin >> num;
			_2dArray[i].push_back(num);
		}
	}

	int sumCount;

	cin >> sumCount;

	vector<int> results;

	for (int i = 0; i < sumCount; i++) {
		int pos[4];
		for (int j = 0; j < 4; j++) {
			int p;
			cin >> p;
			pos[j] = p;
		}
		
		int sum = 0;

		for (int k = pos[1] -1; k < pos[3]; k++) {
			for (int l = pos[0] - 1; l < pos[2]; l++) {
				sum += _2dArray[l][k];
			}
		}

		results.push_back(sum);

	}

	for (int& re : results)
		cout << re << endl;
}