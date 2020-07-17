#include <bits/stdc++.h>


using namespace std;

//我们用数组 merged 存储最终的答案。
//
//首先，我们将列表中的区间按照左端点升序排序。然后我们将第一个区间加入 merged 数组中，并按顺序依次考虑之后的每个区间：
//
//如果当前区间的左端点在数组 merged 中最后一个区间的右端点之后，那么它们不会重合，我们可以直接将这个区间加入数组 merged 的末尾；
//
//否则，它们重合，我们需要用当前区间的右端点更新数组 merged 中最后一个区间的右端点，将其置为二者的较大值。


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        if (intervals.size() <= 1) {
            return intervals;
        }
        sort(intervals.begin(), intervals.end());
        ret.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            int L = intervals[i][0];
            int R = intervals[i][1];
            if (L > ret.back()[1]) {
                ret.push_back(intervals[i]);
            } else {
                ret.back()[1] = max(R, ret.back()[1]);
            }
        }

        return ret;
    }
};