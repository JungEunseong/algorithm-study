#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    string numToStr = to_string(n);
	vector<int> nums;
	for (int i = numToStr.size() - 1; i >= 0; i--)
		nums.push_back(static_cast<int>(numToStr[i]) - '0');

	sort(nums.begin(), nums.end(), greater<int>());

	string reverseNum;

	for (int& n : nums)
		reverseNum += static_cast<char>(n + '0');

	answer = stoll(reverseNum);

    return answer;
}
