#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string rtrim(const std::string& s)
{
	size_t end = s.find_last_not_of(' ');
	return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

int main() {
	int wordCount;
	cin >> wordCount;

	vector<string> results;
	for (int i = 0; i < wordCount; i++) {
		int R, C;
		string word;

		cin >> C;
		cin >> R;
		cin >> word;

		vector<vector<char>> procession;

		// vector 초기화
		for (int j = 0; j < C; j++) {

			vector<char> tmp;
			for (int k = 0; k < R; k++) {
				tmp.push_back(word[j * R + k]);
			}
			procession.push_back(tmp);
		}

		int wordIdx[2] = { 0,0 }; //현재 y,x 값
		int wordCount = 0; //글자 몇개
		int rowAmount = C;	// 컬럼 개수 2번마다 -1
		int columnAmount = R; // 컬럼 개수 2번마다 -1

		int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} }; // x,y 증가값 우,하,좌,상
		int changeDirCount = 0; // 방향이 바뀐 횟수(2번마다 컬럼개수 줄이기 용)
		string decodeBinaryString; // 해독한 2진수 문자열98
		string decodeString;

		// 해독 과정
		for (int j = 0; j < columnAmount; j++) {
			decodeBinaryString += procession[wordIdx[1]][wordIdx[0]];
			wordCount++;
			if (j == columnAmount - 1) changeDirCount++;

			wordIdx[0] += dir[changeDirCount % 4][0];
			wordIdx[1] += dir[changeDirCount % 4][1];
		}

		rowAmount--;

		while (true) {
			bool isHorizontallyMove = ((changeDirCount - 1) % 2) != 0;


			int* decreasePtr = (isHorizontallyMove) ? &columnAmount : &rowAmount;
			
			for (int j = 0; j < *decreasePtr; j++) {
				decodeBinaryString += procession[wordIdx[1]][wordIdx[0]];
				wordCount++;
				if (j == (*decreasePtr) - 1) changeDirCount++;

				wordIdx[0] += dir[changeDirCount % 4][0];
				wordIdx[1] += dir[changeDirCount % 4][1];

				if (wordCount == word.size()) break;
			}

			if (isHorizontallyMove) rowAmount--; else columnAmount--;
			if (wordCount == word.size()) break;

		}

		// 10진수 구하기
		for (int j = 0; j < decodeBinaryString.size() / 5; j++)
		{
			string dividedString = decodeBinaryString.substr(j * 5, 5);

			int decodeInt = stoi(dividedString, 0, 2);
			
			char Alphabet = (decodeInt + 64);
			if (Alphabet == 64) Alphabet = ' ';

			decodeString += Alphabet;
		}

		decodeString = rtrim(decodeString);
		results.push_back(decodeString);
		}

	for (string& s : results)
		cout << s << endl;
}

