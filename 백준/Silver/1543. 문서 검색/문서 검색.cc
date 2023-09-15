#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string sentence;
	string searchKeyword;
	int result = 0;

	getline(cin, sentence);
	getline(cin, searchKeyword);

	while (true) {

		auto iter = sentence.find(searchKeyword);

		if (iter == string::npos) break;
		for (int i = 0; i < searchKeyword.size(); i++) {
			sentence[iter + i] = ' ';
		}
		result++;
	}

	cout << result++;
}

