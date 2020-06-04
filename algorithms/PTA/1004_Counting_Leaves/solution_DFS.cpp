//
//  main.cpp
//  pat
//
//  Created by 杨寒凌 on 2020/2/17.
//  Copyright © 2020 杨寒凌. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

// DFS做法
unordered_map<string, vector<string>> myMap;
vector<int>countForLeafNode(1, 0);

void dfs(string id, int level) {
    if (countForLeafNode.size() < level+1) {
        countForLeafNode.push_back(0);
    }
    auto it = myMap.find(id);
    if (it == myMap.end() || it->second.empty()) {

        countForLeafNode[level]++;
    } else {
        for (string childId : it->second) {
            dfs(childId, level+1);
        }
    }
}

int main() {

    int nodeNum, nonLeafNodeNum;
    cin >> nodeNum >> nonLeafNodeNum;
    for (int i = 0; i < nonLeafNodeNum; i++) {
        string id;
        int childNum;

        cin >> id;
        cin >> childNum;
        for (int j = 0; j <childNum; j++) {
            string childId;
            cin >> childId;
            if (myMap.find(id) == myMap.end()) {
                myMap[id] = vector<string>(1, childId);
            } else {
                myMap[id].push_back(childId);
            }
        }
    }
    dfs("01", 0);
    for (int i = 0; i < countForLeafNode.size(); i++) {
        if (i == 0) cout << countForLeafNode[0];
        else cout << ' ' << countForLeafNode[i];
    }

    return 0;
}


