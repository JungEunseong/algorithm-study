#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool ConsonantTest(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return false;

	return true;
}

int main() {
	vector<pair<string, bool>> results;
	while (true) {
		string input;

		cin >> input;

		if (input.compare("end") == 0) break;

		char prev_character = input[0]; // 같은 문자 2개 연속 검사 변수
		int continuousWordsType = 1;    // 같은 타입(자음모음) 연속 횟수
		bool isCurrentWordConsonant = ConsonantTest(prev_character);    // 현재 문자 타입
		int vowelCount = !isCurrentWordConsonant;    // 모음 갯수(초기값 처음 단어 모음이면 1 자음이면 0)
		bool isAlreadyComeUpAnswer = false; // 이미 정답이 나왔는 지(중간에 발음 못하는 조건이 나왔는지)
		for (auto c = input.begin() + 1; c != input.end(); ++c) {

			// 연속 문자 2개 검사
			if (prev_character == (*c)
				&& (*c) != 'e' && (*c) != 'o')
			{
				results.push_back(make_pair(input, false));
				isAlreadyComeUpAnswer = true;
				break;
			}
			else prev_character = (*c);

			// 자음 모음 3개 검사
			if (ConsonantTest(*c) == isCurrentWordConsonant) {
				continuousWordsType++;

				if (continuousWordsType >= 3) {
					results.push_back(make_pair(input, false));
					isAlreadyComeUpAnswer = true;
					break;
				}
			}
			else
			{
				continuousWordsType = 1;
				isCurrentWordConsonant = ConsonantTest(*c);
			}


			// 모음 여부 검사
			vowelCount += !ConsonantTest(*c);
		}

		if (isAlreadyComeUpAnswer) continue;

		if (vowelCount <= 0) results.push_back(make_pair(input, false));
		else results.push_back(make_pair(input, true));
	}

	for (auto r : results) {
		cout << "<" << r.first<<">" << " is " << ((r.second) ? "" : "not ") << "acceptable." << endl;
	}

}

