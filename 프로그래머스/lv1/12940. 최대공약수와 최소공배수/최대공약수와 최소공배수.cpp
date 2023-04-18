#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int m) {
	vector<int> answer;

	int lowerNum = min(n, m);

	int gcd = 0;
	int lcm = 0;

	for (int i = 1; i <= lowerNum; i++)
	{
		if (n % i == 0 && m % i == 0)
			gcd = i;
	}

	lcm = n * m / gcd;
	
	answer.push_back(gcd);
	answer.push_back(lcm);

	return answer;
}