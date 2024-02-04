#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    vector<int> allNumbers;


    std::sort(A.begin(), A.end());
    std::sort(B.rbegin(), B.rend());

    for (int i = 0; i < A.size(); ++i) {
        int maxNum = A[i];
        int minNum = B[i];

        answer += maxNum * minNum;
    }

    return answer;
}