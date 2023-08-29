#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;

	priority_queue<long long> PQ;

	for (int& i : scoville)
		PQ.push(i * -1);

	while (true) {

		if (PQ.top() * -1 >= K) return answer;

		if (PQ.size() == 1) return -1;


		int minFood = PQ.top();
		PQ.pop();
		int secondFood = PQ.top();
		PQ.pop();

		int newFood = minFood + (secondFood * 2);

		PQ.push(newFood);
		
		answer++;
	}

	return answer;
}
