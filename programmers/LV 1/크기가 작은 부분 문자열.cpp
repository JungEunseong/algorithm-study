#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string t, string p) {
	int answer = 0;
	int numLength = p.length();

	vector<long> numberList;

	for (int i = 0; i <= t.length() - numLength; i++)
		numberList.push_back(stoul(t.substr(i, numLength)));

	numberList.erase(remove_if(numberList.begin(), numberList.end(), [&p]( long x) -> bool { return stoul(p) < x; }), numberList.end());
	
	answer = numberList.size();
	return answer;
}
