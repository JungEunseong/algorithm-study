#include <string>
#include <vector>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
	string answer = "";


	int RT = 0;
	int CF = 0;
	int JM = 0;
	int AN = 0;

	for (int i = 0; i < survey.size(); i++)
	{
		const string& s = survey[i];

		bool isLeft = (choices[i] < 4);
		int score = abs((choices[i] - 4));

		if (s.compare("RT") == 0 || s.compare("TR") == 0)
		{
			if (s[0] == 'R') {
				if (isLeft) {
					score *= -1;
				}
			}
			else {
				if (!isLeft) {
					score *= -1;
				}
			}

			RT += score;
		}
		else if (s.compare("CF") == 0 || s.compare("FC") == 0)
		{
			if (s[0] == 'C') {
				if (isLeft) {
					score *= -1;
				}
			}
			else {
				if (!isLeft) {
					score *= -1;
				}
			}

			CF += score;
		}
		else if (s.compare("JM") == 0 || s.compare("MJ") == 0) {
			if (s[0] == 'J') {
				if (isLeft) {
					score *= -1;
				}
			}
			else {
				if (!isLeft) {
					score *= -1;
				}
			}

			JM += score;
		}
		else {
			if (s[0] == 'A') {
				if (isLeft) {
					score *= -1;
				}
			}
			else {
				if (!isLeft) {
					score *= -1;
				}
			}

			AN += score;
		}
	}

	answer += (RT <= 0) ? 'R' : 'T';
	answer += (CF <= 0) ? 'C' : 'F';
	answer += (JM <= 0) ? 'J' : 'M';
	answer += (AN <= 0) ? 'A' : 'N';
	return answer;
}