#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int p = 0;
    int y = 0;
    
    for(const char& c : s){
        if(c == 'p' || c == 'P') p++; 
        else if(c == 'y'|| c == 'Y') y++;
    }

    answer = p == y;
    return answer;
}
