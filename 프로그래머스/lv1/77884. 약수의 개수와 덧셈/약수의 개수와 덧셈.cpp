#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int solution(int left, int right) {
	int answer = 0;

	for (int i = left; i <= right; i++) {
		vector<int> divisors;

		for (int j = 1; j <= sqrt(i); j++) if (i % j == 0) divisors.push_back(j);

		vector<int> tmpDivisors = divisors;
		for (const int& d : tmpDivisors)
			if (!count(divisors.begin(),divisors.end(), i / d)) divisors.push_back(i / d);
		
		if (divisors.size() % 2 == 0) answer += i;
		else answer -= i;
	}
	return answer;
}
