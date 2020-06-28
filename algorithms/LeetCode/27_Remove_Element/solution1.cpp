//
// Created by 杨寒凌 on 2020/6/28.
//

#include <bits/stdc++.h>
using namespace std;

// 遇到就跳过, 没遇到就复制
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};