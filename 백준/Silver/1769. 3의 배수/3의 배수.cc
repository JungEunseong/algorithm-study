#include <iostream>
#include <string>

using namespace std;

int main() {
	string X;
	int Y = 0;
	int changeCount = 0;
	cin >> X;

	while (X.length() > 1) {
		Y = 0;
		for (int i = 0; i < X.length(); i++)
			Y += (int)X[i] - 48;
		
		X = to_string(Y);
		changeCount++;


	}

	int changeXtoInt = stoi(X);

	cout << changeCount << endl;

	switch (changeXtoInt)
	{
	case 3:
	case 6:
	case 9:
		cout << "YES";
		break;
	default:
		cout << "NO";
		break;
	}
}

