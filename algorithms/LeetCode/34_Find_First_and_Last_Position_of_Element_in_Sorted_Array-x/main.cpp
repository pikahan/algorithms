#include <bits/stdc++.h>


using namespace std;



class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (find(nums.begin(), nums.end(), target) == nums.end()) {
            return {-1, -1};
        }
       int left = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
       int right = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
       return {left, right-1};
    }
};