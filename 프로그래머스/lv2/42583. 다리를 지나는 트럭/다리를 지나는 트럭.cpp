#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	queue<pair<int,int>> current_truck; // 나갈 시간, 트럭 무게
	int current_pass_truck = 0;
	int total_weight = 0;
	int nextTruckIdx = 0;
	int time = 1;

	while (current_pass_truck < truck_weights.size()) {


		if (nextTruckIdx < truck_weights.size()) {

			int next_truck_weight = truck_weights[nextTruckIdx];

			if (total_weight + next_truck_weight <= weight) {
				current_truck.push(make_pair(time - 1  + bridge_length, next_truck_weight));
				nextTruckIdx++;
				total_weight += next_truck_weight;
			}

		}

		auto front_truck = current_truck.front();

		if (front_truck.first <= time) {
			current_truck.pop();
			total_weight -= front_truck.second;
			current_pass_truck++;
		}


		time++;
	}
	
	return time;
}