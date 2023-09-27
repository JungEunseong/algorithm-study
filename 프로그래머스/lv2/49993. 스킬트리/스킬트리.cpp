#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    vector<char> skillTree;
    int nextSkilltreeIdx =0;

    for (char& s : skill)
        skillTree.push_back(s);

    for (string& currentSkill : skill_trees) {
        bool CanSkillTree = true;
        for (char& s : currentSkill) {
            auto isSkillInTree = find(skillTree.begin(), skillTree.end(), s);
            if (isSkillInTree != skillTree.end()) {
                if (skillTree[nextSkilltreeIdx] != s) {
                    CanSkillTree = false;
                    break;
                }
                else nextSkilltreeIdx++;
            }
        }


        if (CanSkillTree) answer++;

        nextSkilltreeIdx = 0;
    }

    return answer;
}