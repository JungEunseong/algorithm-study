#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;    
    string numToStr = to_string(n);
    
    for(int i = numToStr.size() -1; i >= 0; i--)
        answer.push_back(numToStr[i] - '0');
        
    
    return answer;
}
