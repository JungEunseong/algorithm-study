#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
	string answer = "";

	if (find_if(numbers.begin(), numbers.end(), [](int a) {return a != 0; }) == numbers.end())
		return "0";

	vector<pair<string, int>> numberToString;

	for (int& n : numbers) {
		string nToStr = to_string(n);
		int numberInitSize = nToStr.size();

		while (nToStr.size() < 4)
			nToStr += nToStr;

		nToStr = nToStr.substr(0,4);

		numberToString.push_back(make_pair(nToStr, numberInitSize));
	}

	sort(numberToString.rbegin(), numberToString.rend());

	for (auto i = numberToString.begin(); i != numberToString.end(); ++i)
		answer += (*i).first.substr(0,(*i).second);

	return answer;
}