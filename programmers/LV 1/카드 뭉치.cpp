#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
	string answer = "Yes";

	int c1_LastAnswer_idx = 0;
	int c2_LastAnswer_idx = 0;

	bool isSuccess = false;
	for (string& g : goal) {
		auto isExist = find(cards1.begin(), cards1.end(), g);



		if (isExist != cards1.end()) {
			int idx = distance(cards1.begin(), isExist);

			*isExist = "";
			c1_LastAnswer_idx = idx;
			isSuccess = true;
			if (c1_LastAnswer_idx > idx) {
				answer = "No";
				isSuccess = false;
			}

			for (auto i = cards1.begin(); i != isExist; ++i)
			{
				if ((*i) != "") {
					answer = "No";
					isSuccess = false;
				}
			}

		}

		isExist = find(cards2.begin(), cards2.end(), g);

		if (isExist != cards2.end()) {
			int idx = distance(cards2.begin(), isExist);

			*isExist = "";
			c1_LastAnswer_idx = idx;
			isSuccess = true;

			if (c2_LastAnswer_idx > idx) {
				answer = "No";
				isSuccess = false;
			}

			for (auto i = cards2.begin(); i != isExist; ++i)
			{
				if ((*i) != "") {
					answer = "No";
					isSuccess = false;
				}
			}

		}

		if (isSuccess == false)
			break;
	}

	return answer;
}