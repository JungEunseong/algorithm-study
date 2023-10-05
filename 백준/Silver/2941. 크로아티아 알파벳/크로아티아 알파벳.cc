#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;


int main() {
	vector<string> croatiaAlphabets{ "c=","c-","dz=","d-", "lj","nj","s=","z=" };
	
	string alphabets;

	cin >> alphabets;
	
		for (string& al : croatiaAlphabets) {

			while (true) {
				auto iter = alphabets.find(al);

				if (iter == alphabets.npos) break;
				else if (iter != alphabets.npos) {
					alphabets = alphabets.replace(iter, al.size(), "*");
				}
			}
		}

	cout << alphabets.size();
}


