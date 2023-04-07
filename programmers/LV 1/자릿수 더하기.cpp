#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    string numToStr = to_string(n);
    
    for(const char& c : numToStr)
        answer += static_cast<int>(c) - '0';

    return answer;
}
