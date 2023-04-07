#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;

    string numToStr = to_string(x);
    int eachDigitSum = 0;

    for (const char& c : numToStr)
        eachDigitSum += static_cast<int>(c) - '0';

    if (x % eachDigitSum != 0) answer = false;

    return answer;
}
