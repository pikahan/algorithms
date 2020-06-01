//
// Created by 杨寒凌 on 2020/6/1.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    map<int, float> map;
    for (int i = 0; i < 2; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            int n;
            float a;
            cin >> n >> a;
            if (map.find(n) == map.end()) {
                map[n] = a;
            } else {
                map[n] = map[n] + a;
            }

        }
    }
    string ret;
    int size = 0; // 不能直接输出size, 因为要排除系数为0的情况
    for (auto it = map.rbegin(); it != map.rend(); it++) {
        if (it->second != 0) {
            char str[20];
            size++;
            sprintf(str, " %d %.1f", it->first, it->second);
            ret += str;
        }
    }
    cout << size << ret;
    return 0;
}
