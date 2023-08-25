#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	
	for (int i = 0; i < commands.size(); i++) {
		vector<int> currentCommands = commands[i];
		vector<int> slicedArray(array.begin() + currentCommands[0] -1,array.begin() + currentCommands[1]);
		sort(slicedArray.begin(), slicedArray.end());

		answer.push_back(slicedArray[currentCommands[2]- 1]);
	}
	
	return answer;
}
