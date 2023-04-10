#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    auto minIter = min_element(arr.begin(),arr.end());
    arr.erase(minIter);
    answer = arr;
    
    if(arr.size() == 0) answer.push_back(-1);
    
    return answer;
}
