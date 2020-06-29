//
// Created by 杨寒凌 on 2020/6/29.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int count;
    cin >> count;
    int ret = INT_MIN/2;
    int currSum = INT_MIN/2;
    int leftNum;
    int currLeftNum;
    int rightNum;
    int currRightNum;
    int flag = 1;
    int firstNum;
    int lastNum;
    for (int i = 0; i < count; i++) {
        int number;
        cin >> number;
        if (i == 0) firstNum = number;
        if (i == count - 1) lastNum = number;

        if (number >= 0) flag = 0;
//        int r = currSum + number;
        if (number >= currSum + number) {
            currSum = number;
            currLeftNum = number;
        } else {
            currSum = currSum + number;
        }

        if (currSum > ret) {
            leftNum = currLeftNum;
            rightNum = number;
            ret = currSum;
        }
    }
    if (flag) {
        cout << 0 << ' ' << firstNum << ' ' << lastNum;
    } else {
        cout << ret << ' ' << leftNum << ' ' << rightNum;
    }
}