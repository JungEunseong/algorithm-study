#include <string>
#include <algorithm>
#include <regex>

using namespace std;

string solution(string new_id) {
	string answer = "";
	
	//1
	for (char& c : new_id)
	{
		c = tolower(c);
	}
	//2
	new_id = regex_replace(new_id, regex("[^a-z0-9-_.]"), "");

	//3
	for (int i = 1; i < new_id.length(); i++)
	{
		if (new_id[i - 1]  == '.' && new_id[i] == '.') {
			new_id.erase(new_id.begin() + i);
			i--;
			continue;
		}
	}
	//4
	while (*(new_id.begin()) == '.' || *(new_id.end() - 1) == '.') {
		
		if(*(new_id.begin()) == '.')
			new_id.erase(new_id.begin());
		else if (*(new_id.end() - 1) == '.') {
			new_id.erase(new_id.end() - 1);
		}
	}

	//5
	if (new_id.empty()) {
		new_id = 'a';
	}

	//6
	if (new_id.length() > 15) {
		new_id.erase(new_id.begin() + 15, new_id.end());
		
		if (*(new_id.end() - 1) == '.') {
			new_id.erase(new_id.end() - 1);
		}
	}

	//7
	if (new_id.length() < 3) {
		char lastWord = *(new_id.end() - 1);

		while (true) {
			if (new_id.length() > 2) {
				break;
			}

			new_id += lastWord;
		}
	}

	answer = new_id;
	return answer;
}
