#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	map<string, int> completionCnt;


	for (int i = 0; i < completion.size(); i++)
	{
		completionCnt[completion[i]]++;
	}

	for (int j = 0; j < participant.size(); j++)
	{
		completionCnt[participant[j]]--;
	}

	for (auto completion : completionCnt)
	{
		if(completion.second != 0){
			answer = completion.first;
			break;
		}
	}
	return answer;
}
