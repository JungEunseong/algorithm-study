#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    int turn = 0;
    int people = 0;
    vector<string> useWords;   
    bool isSuccess = true;
    for (int i = 0; i < words.size(); i++) {

            
           if (useWords.size() != 0 &&
            words[i][0] != words[i - 1][words[i-1].length() - 1]) { isSuccess = false; break; }

        if (words[i].length() == 1) { isSuccess = false; break; }

        if (find(useWords.begin(), useWords.end(), words[i]) == useWords.end())
            useWords.push_back(words[i]);
        else { answer = { turn, people + 1 }; isSuccess = false; break; }

        if (++people == n) { turn++; people = 0; }

    }
    if (isSuccess == false) answer = {people + 1, turn + 1 };
    else answer = { 0, 0 };

    return answer;
}
