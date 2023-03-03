#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<int> numbers, string hand) {

    string answer = "";

    int keyPad[4][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9},
        {10,11,12},
    };

    vector<int> leftNum{ 1,4,7 };
    vector<int> rightNum{ 3,6,9 };

    int leftHandPos[2] = { 3,0 }; // y, x
    int rightHandPos[2] = { 3,2 }; // y, x

    for (int num : numbers)
    {
        if (find(leftNum.begin(), leftNum.end(), num) != leftNum.end()) { // �޼�
            answer += "L";
            leftHandPos[0] = (num / 3);   // y
            leftHandPos[1] = 0;   // x

        }
        else if (find(rightNum.begin(), rightNum.end(), num) != rightNum.end()) { // ������
            answer += "R";
            rightHandPos[0] = (num / 3) - 1; // y
            rightHandPos[1] = 2; // x
        }
        else { // ���
            int numPos[2] = { (num == 0) ? 3 : (num / 3), 1 };

            int leftHandDistance = abs(leftHandPos[0] - numPos[0]) + abs(leftHandPos[1] - numPos[1]);
            int rightHandDistance = abs(rightHandPos[0] - numPos[0]) + abs(rightHandPos[1] - numPos[1]);

            if (leftHandDistance < rightHandDistance) {// �޼��� �� �����
                answer += "L";
            }
            else if (leftHandDistance > rightHandDistance) { // �������� �� �����
                answer += "R";
            }
            else { // ����
                if (hand == "left") { // �޼�����
                    answer += "L";
                }
                else { // ������ ����
                    answer += "R";
                }
            }

            if (answer.at(answer.size() - 1) == 'L') {
                leftHandPos[0] = numPos[0];
                leftHandPos[1] = numPos[1];
            }
            else {
                rightHandPos[0] = numPos[0];
                rightHandPos[1] = numPos[1];
            }
        }
    }

    return answer;
}
