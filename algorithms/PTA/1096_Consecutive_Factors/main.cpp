#include <bits/stdc++.h>
using namespace std;


// 不需要求出各个因子, 只需要知道不断连乘, 判断能否整除就好

int main() {
    int num;
    cin >> num;
    int temp = sqrt(num);
    int retCount = 0;
    int start = 0;
    for (int i = 2; i <= temp; i++) {
        int s = 1;
        int j;
        for (j = i; j <= temp; j++) {
            s *= j;
            if (num % s != 0) {
                break;
            }
        }
        if (j - i > retCount) {
            start = i;
            retCount = j - i;
        }
    }
    if (start == 0) { cout << "1" << endl << num; return 0; }
    cout << retCount << endl;

    for (int i = 0; i < retCount; i++) {
        if (i == 0) {
            cout << start + i;
        } else
        cout << '*' << start + i;
    }
    return 0;
}