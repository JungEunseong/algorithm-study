#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;

	vector<vector<int>> sort_board;
	stack<int> basket{};

	for (int i = 0; i < board.size(); i++)
	{
		sort_board.push_back({});
	}
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board.size(); j++)
		{
			sort_board[i].push_back(board[j][i]);
		}

		reverse(sort_board[i].begin(), sort_board[i].end());
	}


	for (int move : moves)
	{

		int idx = move - 1;

		while (!sort_board[idx].empty()) {

			int currentValue = sort_board[idx].back();
			sort_board[idx].pop_back();

			if (currentValue == 0) continue;

			if (basket.empty()) {
				basket.push(currentValue);
			}
			else {
				if (currentValue == basket.top())
				{
					basket.pop();
					answer += 2;
				}
				else basket.push(currentValue);
			}
			break;

		}
	}
	return answer;
}
