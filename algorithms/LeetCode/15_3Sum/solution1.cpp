//
// Created by 杨寒凌 on 2020/6/1.
//
#include <bits/stdc++.h>
using namespace std;

//双指针, 难点主要是处理重复的问题, 因此排序后非常好处理, 如果还是按照2Sum的做法, 重复的问题非常难以处理, 所以此题使用了双指针的方式

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        if (nums.size() < 3) {
            return {};
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;

            int targetValue = -nums[i];
            int leftPos = i + 1;
            int rightPos = nums.size() - 1;
            while (leftPos < rightPos) {
                int sum = nums[leftPos] + nums[rightPos];
                if (sum == targetValue && leftPos < rightPos) {
                    ret.push_back({ nums[i], nums[leftPos], nums[rightPos] });
                    leftPos++;
                    rightPos--;
                    while (nums[leftPos] == nums[leftPos-1] && leftPos < rightPos) leftPos++;
                    while (nums[rightPos] == nums[rightPos+1] && leftPos < rightPos) rightPos--;
                } else {
                    if (sum > targetValue) rightPos--;
                    else if (sum < targetValue) leftPos++;
                }


            }

        }
        return ret;
    }
};


int main() {
    vector<int> v(4,2);
    Solution().threeSum(v);


    return 0;
}