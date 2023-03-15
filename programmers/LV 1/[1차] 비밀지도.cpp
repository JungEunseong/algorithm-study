#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer(n, "");

	for (int i = 0; i < n; i++)
	{
		int line = (arr1[i] | arr2[i]);
		for (int j = 0; j < n; j++)
		{
			answer[i] += (line >> j & 1) ? "#" : " ";
		}

		reverse(answer[i].begin(), answer[i].end());
	}
	return answer;
}
