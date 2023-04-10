#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    
    sort(numbers.begin(),numbers.end());
    
    for(int i = 0; i <= 9 ; i++)
        if(binary_search(numbers.begin(),numbers.end(),i) == false) answer += i;
    
    return answer;
}
