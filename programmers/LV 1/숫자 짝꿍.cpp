#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
string solution(string X, string Y) {
	string answer = "";

	map<char, int> duplicationNumber;

	for (const char& c : X) duplicationNumber[c]++;

	for (char& c : Y)
	{
		if (duplicationNumber[c] != 0) {
			duplicationNumber[c]--;
			
			answer += c;
		}
	}

	if (answer.length() == 0)
		return "-1";

	sort(answer.begin(), answer.end(), greater<>());
 		
	return (answer[0] == '0') ? "0" : answer;
}
