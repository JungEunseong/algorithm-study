#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
	int toppingCount;
	cin >> toppingCount;

	unordered_map<string, int> toppings;

	for (int i = 0; i < toppingCount; i++)
	{
		string topping;
		cin >> topping;

		if (topping.length() < 6) continue;

		if (topping.substr(topping.length() - 6, topping.length()) == "Cheese")
			toppings[topping]++;
	}

	if (toppings.size() < 4) {
		cout << "sad"; 
		return 0;
	}

	for (auto i = toppings.begin(); i != toppings.end(); ++i) {
		if (i->second > 1) {
			cout << "sad";
			return 0;
		}
	}

	cout << "yummy";
}
