//
// Created by 杨寒凌 on 2020/6/5.
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pos = nums.size()-1;
        while (pos > 0 && nums[pos] <= nums[pos-1]) pos--;
        reverse(nums.begin() + pos, nums.end());
        if (pos > 0) {
            auto it = upper_bound(nums.begin()+pos, nums.end(), nums[pos-1]);
            swap(*it, nums[pos-1]);
        }
    }
};