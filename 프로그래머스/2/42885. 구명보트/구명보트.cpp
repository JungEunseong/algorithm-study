#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;

    sort(people.begin(),people.end(),greater<int>());

    int minIdx = people.size() -1;
    int maxIdx = 0;
    while(true){
        if(maxIdx == minIdx) break;

        if(people[maxIdx] + people[minIdx] <= limit && maxIdx != minIdx)
        {
            minIdx--;
            if(maxIdx == minIdx) break;
        }

        maxIdx++;
        answer++;
    }

    answer++; // 나머지 정리

    return answer;
}