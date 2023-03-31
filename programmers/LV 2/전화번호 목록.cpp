#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	
	unordered_map<string, int> phones;

	for (const string& phone : phone_book) phones[phone] = 1;

	for (int i = 0; i < phone_book.size(); i++)
	{
		for (int j = 0; j < phone_book[i].size(); j++)
		{
			string key = phone_book[i].substr(0, 1 + j);
			if (phones[key] && phone_book[i] != key) return false;
		}
	}

	return answer;
}
