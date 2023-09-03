#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {

	string board;

	cin >> board;


	while (true) {
		if (board.find("XXXX") == board.npos) break;
		board = board.replace(board.find("XXXX"), 4, "AAAA");
	}

	while (true) {
		if (board.find("XX") == board.npos) break;
		board = board.replace(board.find("XX"), 2, "BB");
	}


	if (find(board.begin(), board.end(), 'X') != board.end())
		cout << "-1" << endl;
	else
		cout << board << endl;
}