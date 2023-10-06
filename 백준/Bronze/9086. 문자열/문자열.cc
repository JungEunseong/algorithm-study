#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;


int main() {
	
	int count;
	vector<string> results;

	cin >> count;

	for (int i = 0; i < count; i++) {
		string str;

		cin >> str;

		string tmp;

		tmp += str[0];
		tmp += str[str.size()-1];

		results.push_back(tmp);
	}

	for (auto r : results)
		cout << r << endl;
}


