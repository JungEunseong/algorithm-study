#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	queue<pair<int,int>> priorityQueue;

	for (int i = 0; i < priorities.size(); i++)
		priorityQueue.push(make_pair(i, priorities[i]));

	sort(priorities.begin(), priorities.end(),greater<int>());

	int popCount = 0;
	while (true) {
		auto number = priorityQueue.front();
		priorityQueue.pop();

		if (number.second == priorities[0]) {
			popCount++;
			if (number.first == location)
				return popCount;

			priorities.erase(priorities.begin());
		}
		else {
			priorityQueue.push(number);
		}
	}
}