#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string sentence;
    cin >> sentence;

    for (auto i = sentence.rbegin(); i != sentence.rend(); ++i) {
        cout << *i;
    }
}

