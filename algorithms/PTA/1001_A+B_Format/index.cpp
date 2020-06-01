//
// Created by 杨寒凌 on 2020/6/1.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    stack<int> s;
    int sum = a + b;
    if (sum < 0) {
        cout << '-';
        sum *= -1;
    };

    do {
        int n = sum % 1000;
        s.push(n);
        sum /= 1000;
    } while (sum != 0);

    cout << s.top();
    s.pop();
    while (!s.empty()) {
        int digit = s.top();
        printf(",%03d", digit);
        s.pop();
    }

}
