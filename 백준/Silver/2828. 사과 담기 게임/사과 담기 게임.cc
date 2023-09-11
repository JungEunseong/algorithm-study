#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	int basketPos = 1;
	int moveCount = 0;

	int screenWidth;
	int basketWidth;
	cin >> screenWidth;
	cin >> basketWidth;
	basketWidth--;
	
	int appleCount;
	cin >> appleCount;

	for (int i = 0; i < appleCount; i++) {
		int applePos;
		cin >> applePos;

		if (applePos >= basketPos && applePos <= basketPos + basketWidth) continue;
		else if (applePos < basketPos) {
			moveCount += basketPos - applePos;
			basketPos -= basketPos - applePos;
		}
		else if (applePos > basketPos + basketWidth)
		{
			moveCount += applePos - (basketPos + basketWidth);
			basketPos += applePos - (basketPos + basketWidth);
		}
	}

	cout << moveCount << endl;

}