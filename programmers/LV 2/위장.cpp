#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 0;

	map<string, int> clothesType;

	for (int i = 0; i < clothes.size(); i++)
		clothesType[clothes[i][1]] += 1;
	
	int num = 1;
	for (auto clothes : clothesType) {
		if (clothesType.size() <= 1) {
			num = clothes.second + 1;
			break;
		}
		else clothes.second += 1;
		num *= clothes.second;
	}
	answer += num -1;
	return answer;
}
