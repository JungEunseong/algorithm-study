#include <string>
#include <vector>
#include <numeric>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    answer = accumulate(arr.begin(),arr.end(),0) / static_cast<double>(arr.size());

    return answer;
}
