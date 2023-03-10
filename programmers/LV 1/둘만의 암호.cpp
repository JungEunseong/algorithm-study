#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
	string answer = "";

	for (int i = 0; i < s.length(); i++)
	{
		char* word = &s[i];
		for (int j = 0; j < index; j++)
		{
			if (skip.find((*(word) + 1 > 'z') ? 'a' : *(word) + 1) != skip.npos)
				j--;
			(*word)++;
			if (*word > 'z')
				*word = 'a';
		}

		answer += *word;
	}
	return answer;
}
