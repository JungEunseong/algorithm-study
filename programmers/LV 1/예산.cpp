#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
	int answer = 0;
	sort(d.begin(), d.end(), [](int a, int b) {return a < b; });

	for (int i = 0; i < d.size(); i++)
	{
		budget -= d[i];
		if (budget < 0) break;
		else answer++;
	}
	return answer;
}
