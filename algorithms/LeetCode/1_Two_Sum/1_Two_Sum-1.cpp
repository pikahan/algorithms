//
// Created by 杨寒凌 on 2020/5/30.
//

//一次遍历哈希

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>map;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            auto it = map.find(target - num);
            if (it == map.end()) {
                map[num] = i;
            } else {
                return {it->second, i};
            }
        }
        return {};
    }
};
