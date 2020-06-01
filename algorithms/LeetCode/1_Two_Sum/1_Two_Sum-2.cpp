//
// Created by 杨寒凌 on 2020/5/30.
//

// 两次遍历哈希

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>map;
        for (int i = 0; i < nums.size(); i++) {
            map.insert(pair<int, int>(nums[i], i));
        }

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            auto it = map.find(target - num);
            if (it != map.end() && it->second != i) {
                return {i, it->second};
            }
        }
        return {};
    }
};
