#include <iostream>
#include<string>
#include<stack>

using namespace std;
int solution(string s)
{
    int answer = -1; 

    stack<char> characterStack;

    for(char& c : s){
        if(characterStack.empty() != true) {
            if (characterStack.top() == c)
                characterStack.pop();
            else
                characterStack.push(c);
        }
        else
            characterStack.push(c);
    }

    answer = (characterStack.empty() == true) ? 1 : 0;

    return answer;
}