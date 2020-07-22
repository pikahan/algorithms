#include <bits/stdc++.h>
using namespace std;

int main() {
    int familyCount, personCount;
    unordered_map<int, vector<int>> map;
    queue<int> queue;
    cin >> personCount >> familyCount;
    vector<int> ret(personCount, 0);
    int level = 2;
    ret[1] = 1;
    for (int i = 0; i < familyCount; i++) {
        int id;
        cin >> id;
        map[id] = {};
        int num;
        cin >> num;
        for (int j = 0; j < num; j++) {
            int childId;
            cin >> childId;
            map[id].push_back(childId);
        }
    }
    queue.push(1);
    queue.push(-1);
    while (!queue.empty()) {
        int id = queue.front();
        queue.pop();
        if (id == -1 && queue.size() > 1) {
            queue.push(-1);
            level++;
            continue;
        }

        auto p = map.find(id);
        if (p == map.end()) continue;
        ret[level] += p->second.size();
        for (int & i : p->second) {
            queue.push(i);
        }
    }
    int maxCount = 0;
    int maxLevel = 0;
    for (int i = 1; i <= ret.size(); i++) {
        if (ret[i] > maxCount) {
            maxCount = ret[i];
            maxLevel = i;
        }
    }
    cout << maxCount << ' ' << maxLevel;
    return 0;
}