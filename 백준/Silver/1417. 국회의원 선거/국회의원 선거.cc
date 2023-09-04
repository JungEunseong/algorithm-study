#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int candidateAmount;
	int dasom_votes = 0;
	int buyCount = 0;
	vector<int> other_votes;

	cin >> candidateAmount;

	for (int i = 0; i < candidateAmount; i++) {
		int votes;
		cin >> votes;
		if (i == 0) dasom_votes = votes;
		else other_votes.push_back(votes);
	}

	if (candidateAmount != 1) {
		auto maxNum = max_element(other_votes.begin(), other_votes.end());

		while ((*maxNum) >= dasom_votes) {
			dasom_votes++;
			(*maxNum)--;

			maxNum = max_element(other_votes.begin(), other_votes.end());
			buyCount++;
		}

		cout << buyCount << endl;
	}
	else
		cout << 0 << endl;
}