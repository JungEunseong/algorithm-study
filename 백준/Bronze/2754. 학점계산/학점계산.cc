#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string credit;
	double score;
	
	cin >> credit;
	switch (credit[0])
	{
	case 'A':
		score = 4.3;
		break;
	case 'B':
		score = 3.3;
		break;
	case 'C':
		score = 2.3;
		break;
	case 'D':
		score = 1.3;
		break;
	default:
		score = 0;
		printf("%.1f\n", score);
		return 0;
	}

	switch (credit[1])
	{
	case '+':
		break;
	case '0':
		score -= 0.3;
		break;
	case '-':
		score -= 0.6;
		break;
	}
	printf("%.1f\n", score);
}

