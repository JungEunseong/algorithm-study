#include <iostream>
#include <string>

using namespace std;

int main() {
	string sentence;

	cin >> sentence;


	for (int i = 0; i < sentence.size(); i++) {
		if (sentence[i] >= 65 && sentence[i] <= 90) {
			sentence[i] += 32;
		}
		else if (sentence[i] >= 97 && sentence[i] <= 122) {
			sentence[i] -= 32;
		}
	}

	cout << sentence << endl;
}