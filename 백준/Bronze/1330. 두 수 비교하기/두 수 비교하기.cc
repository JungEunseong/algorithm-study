#include <iostream>
#include <string.h>

using namespace std;

int main() {
	int A, B;
	
	cin >> A >> B;

	cout << ((A > B) ? ">" : (A == B) ? "==" : "<");
}