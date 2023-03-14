#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
vector<int> solution(vector<string> keymap, vector<string> targets) {
	vector<int> answer(targets.size(),0);
	map<char, int> key;

	for (int i = 0; i < keymap.size(); i++)
	{
		for (char c : keymap[i])
		{
			int idx = find(keymap[i].begin(), keymap[i].end(), c) - keymap[i].begin() + 1;
			auto result = key.insert(make_pair(c, idx));

			if (!result.second && key[c] > idx) key[c] = idx;
		}
	}
	
	for (int i = 0; i < targets.size(); ++i)
	{
		for (const char& c : targets[i])
		{
			auto result = key.find(c);

			if (result == key.end()) { answer[i] = -1; break;}
			else answer[i] += key[c];
		}
	}

	return answer;
}
