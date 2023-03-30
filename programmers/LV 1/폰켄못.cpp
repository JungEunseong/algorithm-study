#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
	int answer = 0;
	int selectAmount = nums.size() / 2;
	map<int, int> selectType;

	for (const int& num : nums) selectType[num]++;
	
	answer = (selectType.size() >= selectAmount) ? selectAmount : selectType.size();
	return answer;
}
