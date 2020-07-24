#include <bits/stdc++.h>
using namespace std;

// 参考网址 https://blog.csdn.net/qq_34649947/article/details/81208186

vector<int> numList;
vector<int> ret, temp;
int maxSum = INT_MIN;
int counter;
int number;

void dfs(int index, int currSum, int currCount, int digitSum) {
    if (index < 1) return;
    int currNumber = numList[index];
    if (currSum != number && currCount >= counter) return;
    if (currSum >= number && currCount != counter) return;
    if (currSum == number && currCount == counter) {
        if (digitSum > maxSum) {
            maxSum = digitSum;
            ret = temp;
            return;
        }
    }
    temp.push_back(index);
    dfs(index, currSum + currNumber, currCount+1, digitSum + index);
    temp.pop_back();
    dfs(index-1, currSum, currCount, digitSum);
}

int main() {
    int p;
    cin >> number >> counter >> p;
    int tempNum = number;
    if (p > 1) {
        tempNum = sqrt(number);
    }
    numList.push_back(0);
    for (int i = 1; i <= tempNum; i++) {

        // p次方若大于number就不要了
        int x = pow(i, p);
        if (x > number) break;
        numList.push_back(x);
    }
    dfs(numList.size()-1, 0, 0, 0);
    if (maxSum == INT_MIN) {
        cout << "Impossible" << endl;
    } else {
        printf("%d = %d^%d", number, ret[0], p);
        for (int i = 1; i < ret.size(); i++) {
            printf(" + %d^%d", ret[i], p);
        }
    }

    return 0;
}