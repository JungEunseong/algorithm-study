#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	
	vector<int> essayAssignmentStudent;

	
	for (int i = 0; i < 28; i++) {
		int num;
		cin >> num;
		essayAssignmentStudent.push_back(num);
	}


	for(int i = 1; i <= 30; i++){
		if (find(essayAssignmentStudent.begin(), essayAssignmentStudent.end(), i) == essayAssignmentStudent.end())
			cout << i << endl;
	}
}