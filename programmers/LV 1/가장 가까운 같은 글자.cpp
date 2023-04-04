#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string s) {
	vector<int> answer;
	unordered_map<char, int> alphabetIdx;

	for (int i = 0; i < s.size(); i++)
	{
		char currentAlphabet = s[i];
		if (alphabetIdx.find(currentAlphabet) == alphabetIdx.end()) {
			alphabetIdx[currentAlphabet] = i;
			answer.push_back(-1);
		}
		else {
			answer.push_back(i - alphabetIdx[currentAlphabet]);
			alphabetIdx[currentAlphabet] = i;
		}
	}
	return answer;
}
