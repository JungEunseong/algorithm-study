#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;
	vector<int> nums;

	while (n > 0)
	{
		nums.push_back(n % 3);
		n /= 3;
	}

	int digitCnt = 1;

	while(nums.size() > 0)
	{
		int n = nums.back();
		nums.pop_back();
		answer += n * digitCnt;
		digitCnt *= 3;
	}
	return answer;
}