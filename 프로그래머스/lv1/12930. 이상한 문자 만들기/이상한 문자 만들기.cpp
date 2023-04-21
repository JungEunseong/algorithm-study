#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
	string answer = "";

	vector<char> wordData;

	for (const char& c : s)
		wordData.push_back(c);

	int idx = 0;

	for (int i = 0; i < wordData.size(); i++)
	{
		if (wordData[i] == ' ') { idx = 0; answer += ' '; continue; }

		answer += (idx % 2 == 0) ? toupper(wordData[i]) : tolower(wordData[i]);

		idx++;
	}
	return answer;
}
