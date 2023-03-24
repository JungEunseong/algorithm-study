#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

vector<string> split(string& target, char standard) {
	
	vector<string> result;
	stringstream ss(target);
	string temp;
	while (getline(ss, temp, standard)) {
		result.push_back(temp);
	}

	return result;
}
vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
	vector<int> answer;

	int YYYY, MM, DD;
	map<string, int> termMap;
	auto todaySplitResult = split(today, '.');
	YYYY = stoi(todaySplitResult[0]); MM = stoi(todaySplitResult[1]); DD = stoi(todaySplitResult[2]);
	
	for (string& term : terms) {
		auto splitResult = split(term,' ');
		termMap.insert(make_pair(splitResult[0], stoi(splitResult[1])));
	}

	for (int i = 0; i < privacies.size(); i++)
	{
		string currentPrivacies = privacies[i];
		auto splitResult = split(currentPrivacies, ' ');

		auto date = split(splitResult[0], '.');
		int monthSum = 0;
		monthSum += (YYYY - stoi(date[0])) * 12;
		monthSum += MM - stoi(date[1]);
	
		if (monthSum > termMap[splitResult[1]]) answer.push_back(i + 1);
		else if (monthSum == termMap[splitResult[1]])
			if (DD - stoi(date[2]) >= 0) answer.push_back(i + 1);;
	}

	return answer;
}
