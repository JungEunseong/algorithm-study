#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    std::sort(score.rbegin(), score.rend());
    
    int box_count = score.size() / m;

    for(int i = 0; i < box_count; ++i)
    {
        int min_score = score[i * m];
        
        for(int j = 0; j < m; ++j)
            min_score = min(min_score, score[i * m + j]);

        answer += min_score * m;
    }

    return answer;
}