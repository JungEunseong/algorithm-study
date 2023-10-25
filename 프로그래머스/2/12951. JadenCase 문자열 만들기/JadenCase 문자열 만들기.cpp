#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
	string answer = "";
	answer = s;
	bool isEmpty = true;
	for (int i = 0; i < answer.size(); i++) {
		char& currentWord = answer[i];
		if (currentWord == ' ') {
			isEmpty = true;
		}
		else {
			if (isEmpty == true) {
				currentWord = toupper(currentWord);
				isEmpty = false;
			}
			else
				currentWord = tolower(currentWord);
		}
	}

	return answer;
}

