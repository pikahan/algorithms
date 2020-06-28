//
// Created by 杨寒凌 on 2020/6/28.
//

#include <bits/stdc++.h>
using namespace std;

// 双指针
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        int leftPos = 1;
        int rightPos = 1;
        while (rightPos != nums.size()) {
            if (nums[rightPos] != nums[rightPos-1]) {
                nums[leftPos] = nums[rightPos];
                leftPos++;
            }
            rightPos++;
        }
        return leftPos;
    }
};