//
//  main.cpp
//  pat
//
//  Created by 杨寒凌 on 2020/2/17.
//  Copyright © 2020 杨寒凌. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

// BFS做法

int main() {
    queue<string> queue;
    unordered_map<string, vector<string>> myMap;
    vector<int>countForLeafNode(1, 0);
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
    queue.push("01");
    int level = 0;
    while (!queue.empty()) {
        int queueSize = queue.size();
        for (int i = 0; i < queueSize; i++) {
            string id = queue.front();
            queue.pop();
            if (myMap.find(id) == myMap.end() || myMap[id].empty()) {
                countForLeafNode[level]++;
            } else {
                for (const auto& childId: myMap[id]) {
                    queue.push(childId);
                }
            }
        }

        if (level == 0) cout << countForLeafNode[0];
        else cout << ' ' << countForLeafNode[level];

        countForLeafNode.push_back(0);
        level++;
    }
    return 0;
}


