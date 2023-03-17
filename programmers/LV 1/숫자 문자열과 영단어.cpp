#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = 0;
	vector<string> Num{ "zero", "one", "two", "three","four","five","six","seven","eight","nine" };

	for (int i = 0; i < Num.size(); i++)
	{
		while (s.find(Num[i]) != s.npos) {
			int idx = s.find(Num[i]);
			s.replace(idx, Num[i].size(), to_string(i));
		}
	}
	answer = stoi(s);

	return answer;
}
