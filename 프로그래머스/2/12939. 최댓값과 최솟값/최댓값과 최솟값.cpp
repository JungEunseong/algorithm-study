#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";

    vector<int> nums;
    stringstream ss(s);
    string temp;

    while (getline(ss, temp, ' ')) {
        nums.push_back(stoi(temp));
    }

    answer += to_string(*min_element(nums.begin(), nums.end()));
    answer += ' ';
    answer += to_string((*max_element(nums.begin(), nums.end())));


    return answer;
}