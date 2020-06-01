//
// Created by 杨寒凌 on 2020/5/31.
//
#include <bits/stdc++.h>

using namespace std;

//
// Created by 杨寒凌 on 2020/5/31.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int ret = 0;
        int temp = x;
        while (temp != 0) {
            if (ret > INT_MAX / 10) return 0;
            if (ret < INT_MIN / 10) return 0;
            ret = ret * 10 + temp % 10;
            temp /= 10;
        }
        return ret;
    }
};