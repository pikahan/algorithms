#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n));
        int targetNum = n * n;
        int currDigit = 1;
        int topBound = 0;
        int rightBound = n-1;
        int bottomBound = n-1;
        int leftBound = 0;
        while (currDigit <= targetNum) {
            for (int i = leftBound; i <= rightBound; i++) {
                ret[topBound][i] = currDigit;
                currDigit++;
            }
            if (currDigit > targetNum) return ret;
            topBound++;

            for (int i = topBound; i <= bottomBound; i++) {
                ret[i][rightBound] = currDigit;
                currDigit++;
            }
            if (currDigit > targetNum) return ret;
            rightBound--;

            for (int i = rightBound; i >= leftBound; i--) {
                ret[bottomBound][i] = currDigit;
                currDigit++;
            }
            if (currDigit > targetNum) return ret;
            bottomBound--;

            for (int i = bottomBound; i >= topBound; i--) {
                ret[i][leftBound] = currDigit;
                currDigit++;
            }
            if (currDigit > targetNum) return ret;
            leftBound++;
        }
        return ret;
    }
};