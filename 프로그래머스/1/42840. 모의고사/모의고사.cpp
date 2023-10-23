#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;

	vector<int> CorrectCount{ 0,0,0 };

	vector<int> first{ 1,2,3,4,5 };
	vector<int> second{ 2,1,2,3,2,4,2,5 };
	vector<int> third{ 3,3,1,1,2,2,4,4,5,5 };


	for (int i = 0; i < answers.size(); i++) {
		if (first[i % first.size()] == answers[i])
			CorrectCount[0]++;
		if (second[i % second.size()] == answers[i])
			CorrectCount[1]++;
		if (third[i % third.size()] == answers[i])
			CorrectCount[2]++;
	}

	auto maxNum = max_element(CorrectCount.begin(), CorrectCount.end());

	for (int i = 0; i < 3; i++) {
		if(CorrectCount[i] == *maxNum){
			answer.push_back(i + 1);
		}
	}

	return answer;
}