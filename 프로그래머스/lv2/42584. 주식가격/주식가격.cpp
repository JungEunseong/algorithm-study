#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer(prices.size(), 0);
	stack<pair<int, int>> stock_up;
	int time = 0;

	for (int i = 0; i < prices.size(); i++) {

		time++;

		while (stock_up.empty() == false && prices[stock_up.top().second] > prices[i]) {
			answer[stock_up.top().second] += time - stock_up.top().first;
			stock_up.pop();
		}
		stock_up.push(make_pair(time, i));

	}


	while (stock_up.empty() == false) {
		answer[stock_up.top().second] = time - stock_up.top().first;
		stock_up.pop();
	}

	return answer;

}