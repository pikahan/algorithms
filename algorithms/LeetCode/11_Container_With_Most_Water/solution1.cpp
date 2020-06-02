//
// Created by 杨寒凌 on 2020/6/2.
//

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ret = 0;
        int leftPos = 0, rightPos = height.size() - 1;
        while (leftPos != rightPos) {
            int w = rightPos - leftPos;
            int sum;
            if (height[leftPos] > height[rightPos]) {
                sum = w * height[rightPos];
                rightPos--;
            } else {
                sum = w * height[leftPos];
                leftPos++;
            }
            ret = max(ret, sum);
        }
        return ret;
    }
};