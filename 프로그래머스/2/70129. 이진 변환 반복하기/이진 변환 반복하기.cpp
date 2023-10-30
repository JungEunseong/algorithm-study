#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int subZeroCount = 0;

    string currentStr = s;

    int loopCnt = 0;
    while (currentStr.length() != 1) {
        loopCnt++;

        int zeroCount = count(currentStr.begin(), currentStr.end(), '0');
       


        while(currentStr.find('0') != string::npos)
            currentStr.erase(currentStr.find('0'), 1);

        subZeroCount += zeroCount;


        int sLen = currentStr.length();
        
        string tmpStr;
        while (sLen != 0) {
            tmpStr += (sLen % 2 == 0) ? '0' : '1';

            sLen /= 2;
        }

        reverse(tmpStr.begin(), tmpStr.end());




        currentStr = tmpStr;
    }

    answer = vector<int>{ loopCnt,subZeroCount };
    return answer;
}
