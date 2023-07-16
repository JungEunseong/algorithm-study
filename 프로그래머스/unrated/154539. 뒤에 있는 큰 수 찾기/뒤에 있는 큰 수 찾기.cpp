#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
	vector<int> answer(numbers.size(),-1);

	stack<int> notCompletedIdx;

	for (int i = 0; i < numbers.size(); i++) {

		int num = numbers[i];

		while (notCompletedIdx.empty() == false && numbers[notCompletedIdx.top()] < num) {
			answer[notCompletedIdx.top()]= num;
			notCompletedIdx.pop();
		}

		notCompletedIdx.push(i);

	}
	return answer;
}