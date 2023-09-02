#include <iostream>
#include <string.h>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int main() {
	int wordAmount;

	cin >> wordAmount;

	map<int, set<string>> wordMap;

	for (int i = 1; i <= 50; i++)
		wordMap.insert(make_pair(i, set<string>()));

	for (int i = 0; i < wordAmount; i++) {
		string word;

		cin >> word;

		wordMap[word.size()].insert(word);
	}
	
	for (int i = 0; i < wordMap.size(); i++) {
		for (auto j = wordMap[i].begin(); j != wordMap[i].end(); ++j)
			cout << (*j) << endl;
	}
}