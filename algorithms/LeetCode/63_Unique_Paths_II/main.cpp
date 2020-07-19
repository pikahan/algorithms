#include <bits/stdc++.h>


using namespace std;




class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        int topFlag = 0;
        int bottomFlag = 0;
        for (int i = 0; i < m; i++) {
            if (topFlag) {
                obstacleGrid[i][0] = 0;
            } else {
                if (obstacleGrid[i][0] == 1) { // 如果有阻挡, 则后边的都到达不了
                    topFlag = 1;
                    obstacleGrid[i][0] = 0;
                } else {
                    obstacleGrid[i][0] = 1;
                }
            }
        }
        for (int i = 1; i < n; i++) {
            if (bottomFlag) {
                obstacleGrid[0][i] = 0;
            } else {
                if (obstacleGrid[0][i] == 1) {
                    bottomFlag = 1;
                    obstacleGrid[0][i] = 0;
                } else {
                    obstacleGrid[0][i] = 1;
                }
            }        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                obstacleGrid[i][j]  = obstacleGrid[i][j] == 1 ? 0 : obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
            }
        }
        return obstacleGrid[m-1][n-1];
    }
};