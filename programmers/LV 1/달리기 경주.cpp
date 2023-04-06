#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
	vector<string> answer;
	unordered_map<string, int> playerRank_NameToRank;
	unordered_map<int, string> playerRank_RankToName;

	for (int i = 0; i < players.size(); i++) {
		playerRank_NameToRank.insert(make_pair(players[i], i));
		playerRank_RankToName.insert(make_pair(i, players[i]));
	}

	for (const string& c : callings) {
		int rank = playerRank_NameToRank[c];
		string frontRankName = playerRank_RankToName[rank-1];

		swap(playerRank_NameToRank[c], playerRank_NameToRank[frontRankName]);
		swap(playerRank_RankToName[rank], playerRank_RankToName[rank - 1]);
	}

	for (int i = 0; i < players.size(); i++)
		answer.push_back(playerRank_RankToName[i]);

	return answer;
}
