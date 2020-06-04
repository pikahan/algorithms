//
//  main.cpp
//  pat
//
//  Created by 杨寒凌 on 2020/2/17.
//  Copyright © 2020 杨寒凌. All rights reserved.
//

#include <bits/stdc++.h>


using namespace std;

int main() {
    int cityNum, rowNum, source, target;
    cin >> cityNum >> rowNum >> source >> target;
    int* dis = new int[cityNum]; // 存储起始城市到各城市的最短距离
    int* visited = new int[cityNum]; // 判断每个节点是否被访问过
    int* pathSum = new int[cityNum]; // 存储到达每个城市的最短路径条数
    int* rescueTeamsForCity = new int[cityNum]; // 存储每个城市的救援人数
    int* maxRescueTeams = new int[cityNum]; // 存储最大救援人数

    for (int i = 0; i < cityNum; i++) {
        cin >> rescueTeamsForCity[i];
    }

    vector<vector<int>> matrix(cityNum, vector<int>(cityNum, INT_MAX));



    for (int i = 0; i < rowNum; i++) {
        int c1, c2, l;
        cin >> c1 >> c2 >> l;
        matrix[c1][c2] = matrix[c2][c1] = l;
    }

    for (int i = 0; i < cityNum; i++) {
        dis[i] = matrix[source][i];
    }

    dis[source] = 0;
    maxRescueTeams[source] = rescueTeamsForCity[source];
//    visited[source] = 1;
    pathSum[source] = 1;
    for (int count = 1; count < cityNum; count++) { // 只用执行n-1次循环体
        int midCityPos = -1, min = INT_MAX;
        for (int i = 0; i < cityNum; i++) {
            if (!visited[i] && dis[i] < min) {
                midCityPos = i;
                min = dis[i];
            }
        }

        visited[midCityPos] = 1;

        // 以midCityPos为中间节点, 修正距离
        for (int targetCityPos = 0; targetCityPos < cityNum; targetCityPos++) {
            if (matrix[midCityPos][targetCityPos] == INT_MAX) {
                continue;
            }

            int distanceWithMidCity = matrix[midCityPos][targetCityPos] + dis[midCityPos];
            if (distanceWithMidCity < dis[targetCityPos]) {
                dis[targetCityPos] = distanceWithMidCity;
                pathSum[targetCityPos] = pathSum[midCityPos];
                maxRescueTeams[targetCityPos] = rescueTeamsForCity[targetCityPos] + maxRescueTeams[midCityPos];
            } else if (distanceWithMidCity == dis[targetCityPos]) {
                pathSum[targetCityPos] += pathSum[midCityPos];
                if (rescueTeamsForCity[targetCityPos] + maxRescueTeams[midCityPos] > maxRescueTeams[targetCityPos]) {
                    maxRescueTeams[targetCityPos] = rescueTeamsForCity[targetCityPos] + maxRescueTeams[midCityPos];
                }
            }
        }
    }
    cout << pathSum[target] << ' ' << maxRescueTeams[target] << endl;

    return 0;
}
