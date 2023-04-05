#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<int> food) {
	string answer = "";
	
	for (int& f : food) f /= 2;

	for (int i = 0; i < food.size(); i++)
	{
		while (food[i] != 0) {
			answer += to_string(i);
			food[i]--;
		}
	}
	string reverseAnswer = answer;
	reverse(reverseAnswer.begin(), reverseAnswer.end());
	answer += "0" + reverseAnswer;

	return answer;
}
