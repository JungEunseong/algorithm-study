#include <iostream>
#include <queue>

using namespace std;

int main() {

	int X;
	int stickLenghSum = 0;
	int stickCount = 0;
	priority_queue<int> sticks;

	sticks.push(-64);
	stickLenghSum += 64;
	stickCount++;

	cin >> X;

	while (true) {

		if (stickLenghSum > X) {

			int minLengthStick = sticks.top() * -1; // 가장 작은 막대 구하기
			sticks.pop();
			stickLenghSum -= minLengthStick;
			stickCount--;

			minLengthStick /= 2; // 막대 자르기
			stickLenghSum += minLengthStick;
			stickCount++;
			sticks.push(minLengthStick * -1);
			if (stickLenghSum == X) { break; }

			else if (stickLenghSum < X) {
				stickLenghSum += minLengthStick;
				stickCount++;
				sticks.push(minLengthStick * -1);
			}

		}
		else if (stickLenghSum == X) break;


	}

	cout << stickCount << endl;

}
