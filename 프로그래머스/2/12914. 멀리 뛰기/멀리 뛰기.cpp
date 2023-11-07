#include <string>
#include <map>
using namespace std;

long long dp_pibonacci(map<int,int>& dp, int n) {
    if (n == 1) return 1;
    if (n == 2) return 1;
    if (dp[n] != 0) return dp[n];

    return dp[n] = (dp_pibonacci(dp,n - 1) + dp_pibonacci(dp,n - 2)) % 1234567;
}

long long solution(int n) {
    long long answer = 0;
    
    map<int, int> dp_map;
    answer = dp_pibonacci(dp_map, n + 1);
    answer %= 1234567;
    return answer;
}