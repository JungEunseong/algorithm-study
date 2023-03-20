#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
	vector<int> answer(id_list.size(),0);
	report.erase(unique(report.begin(), report.end()), report.end());
	
	map<string, int> id_idx;
	map<string, set<string>> report_info;

	for (int i = 0; i < id_list.size(); i++)
	{
		id_idx.insert(make_pair(id_list[i], i));
	}
	for (const string& id : id_list) {
		report_info.insert(make_pair(id, set<string>()));
	}

	for (const string& re : report) {
		stringstream ss(re);
		string temp;
		vector<string> splitReport;

		while (getline(ss, temp, ' '))
			splitReport.push_back(temp);
		
		report_info[splitReport[1]].insert(splitReport[0]);
	}

	for (auto& info : report_info) {
		if (info.second.size() >= k)
		{
			for (const string& reportId : info.second) {
				answer[id_idx[reportId]]++;
			}
		}
	}
	
	return answer;
}
