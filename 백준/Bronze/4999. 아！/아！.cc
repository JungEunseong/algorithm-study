#include <iostream>
#include <string.h>

using namespace std;

int main() {

	string Jeahwan;
	string Doctor;
	int jeahwanCount = 0, doctorCount = 0;
	cin >> Jeahwan;
	cin >> Doctor;
	
	for (int i = 0; i < Jeahwan.length(); i++) {
		if (Jeahwan[i] == 'a') {
			jeahwanCount++;
		}
	}

	for (int i = 0; i < Doctor.length(); i++) {
		if (Doctor[i] == 'a') {
			doctorCount++;
		}
	}

	if (jeahwanCount >= doctorCount)
		cout << "go" << endl;
	else
		cout << "no" << endl;
}