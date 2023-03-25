#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
using namespace std;

int solution(int number, int limit, int power) {
	int answer = 0;
	vector<vector<int>> divisors(number,vector<int>());
	vector<int> powers;
	for (int i = 1; i <= number; i++)
	{
		for (int j = 1; j <= sqrt(i); j++)
		{
			if (i % j == 0) divisors[i - 1].push_back(j);
			else continue;

			int nextDivisor = i / j;
			if (find(divisors[i - 1].begin(), divisors[i - 1].end(), nextDivisor) == divisors[i - 1].end())
				divisors[i - 1].push_back(nextDivisor);
		}
	}

	for (int i = 0; i < number; i++) {
		if (divisors[i].size() > limit) powers.push_back(power);
		else powers.push_back(divisors[i].size());

	}
	answer = accumulate(powers.begin(), powers.end(), 0);
	return answer;
}
