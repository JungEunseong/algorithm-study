#include <iostream>
#include <string.h>

using namespace std;

int main() {
	long long int N, M;
	
	cin >> N >> M;

	long long int difference = N - M;

	cout << abs(difference) << endl;
}