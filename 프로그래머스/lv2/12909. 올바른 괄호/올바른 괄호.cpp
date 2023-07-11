#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
	bool answer = true;
	
	int flag = 0;
	for (int i = 0; i < s.length(); i++) {
		char c = s[i];

		if (flag == 0)
			if (c == ')')
				return false;

		if (c == '(') flag += 1;
		if (c == ')') flag -= 1;
	}

	answer = (flag == 0);
	
	return answer;
}