#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
	vector<int> answer;
	vector<int> HallOfFame;

	for (int& s : score)
	{
		if (HallOfFame.size() + 1 <= k) HallOfFame.push_back(s);
		else HallOfFame[k - 1] = (HallOfFame[k - 1] > s) ? HallOfFame[k - 1] : s;

		sort(HallOfFame.begin(), HallOfFame.end(), greater<int>());
		answer.push_back(HallOfFame.back());
	}

	return answer;
}
