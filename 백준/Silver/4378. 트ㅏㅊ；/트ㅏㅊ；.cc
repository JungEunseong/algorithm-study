#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main() {
	vector<vector<char>> qwerty = { {'`','1','2','3','4','5','6','7','8','9','0','-','='},
		{'Q','W','E','R','T','Y','U','I','O','P','[',']','\\'},
		{'A','S','D','F','G','H','J','K','L',';','\''},
		{'Z','X','C','V','B','N','M',',','.','/'}
	};

	string input;
	while (getline(cin, input)) {
		string result = "";

		if (input.empty()) break;

		for (char& in : input) {
			for (int t = 0; t < qwerty.size(); t++) {

				if (in == ' ') {
					cout << in;
					break;
				}

				auto iter = find(qwerty[t].begin(), qwerty[t].end(), in);

				if (iter != qwerty[t].end()) {
					cout << *(iter - 1);
					break;
				}
			}
		}

		cout << "\n";
	}

}

