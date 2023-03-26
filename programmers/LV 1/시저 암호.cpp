#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
	string answer = "";
	
	for (char& c : s) {

		for (int i = 0; i < n; i++) {
			if (c >= 'a' && c <= 'z')
				c = (++c > 'z') ? 'a' : c;
			else if (c >= 'A' && c <= 'Z')
				c = (++c > 'Z') ? 'A' : c;
		}
	}
	
	answer = s;
	return answer;
}
