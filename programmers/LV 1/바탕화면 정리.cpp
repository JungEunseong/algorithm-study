#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
	vector<int> answer;

	vector < vector<char>> grid;
	
	int minX = 1000000;
	int minY = 1000000;
	int maxX = -1;
	int maxY = -1;

	for (int i = 0; i < wallpaper.size(); i++)
	{
		grid.push_back(vector<char>());
		for (int j = 0; j < wallpaper[0].size(); j++)
		{
			grid[i].push_back(wallpaper[i][j]);
		}
	}

		for (int i = 0; i < wallpaper.size(); i++) {
		for (int j = 0; j < wallpaper[0].size(); j++)
		{
			if (grid[i][j] == '#') {
				if (i < minY) minY = i;
				if (i > maxY) maxY = i;
				if (j < minX) minX = j;
				if (j > maxX) maxX = j;
			}
		}
	}

	answer.push_back(minY);
	answer.push_back(minX);
	answer.push_back(maxY + 1);
	answer.push_back(maxX + 1);
	return answer;
}
