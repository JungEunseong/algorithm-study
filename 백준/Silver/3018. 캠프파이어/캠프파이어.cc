#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <numeric>
#include <sstream>

using namespace std;


int main() {
    int N, E  = 0;
    long long allSong = 0;
    long long songBit = 1;
    cin >> N;
    cin >> E;

    vector<long long> hearedSong(N + 1);


    for (int i = 0; i < E; i++) {

        int num;
        cin >> num;

        vector<int> people;
        for (int j = 0; j < num; j++) {
            int personId;
            cin >> personId;
            people.push_back(personId);
        }

        bool seonyeong = find(people.begin(), people.end(), 1) != people.end();

        // 선영이가 있을 때
        if (seonyeong) {

            allSong |= (allSong << 1 | 1);

            for (int j = 0; j < num; j++)
                hearedSong[people[j]] |= songBit;

            songBit = songBit << 1;

        }
        else {
            long long song_union = 0;
            for (int j = 0; j < people.size(); j++)
                song_union |= hearedSong[people[j]];

            for (int j = 0; j < people.size(); j++)
                hearedSong[people[j]] = song_union;
        }
    }

    

    for (int i = 0; i < hearedSong.size(); i++)
        if ((hearedSong[i] & allSong) == allSong)
            cout << i << endl;


    return 0;
}    