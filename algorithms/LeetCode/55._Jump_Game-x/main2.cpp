#include <bits/stdc++.h>


using namespace std;


/*
方法一：贪心
我们可以用贪心的方法解决这个问题。

设想一下，对于数组中的任意一个位置 yy，我们如何判断它是否可以到达？根据题目的描述，只要存在一个位置 xx，它本身可以到达，并且它跳跃的最大长度为 x + \textit{nums}[x]x+nums[x]，这个值大于等于 yy，即 x + \textit{nums}[x] \geq yx+nums[x]≥y，那么位置 yy 也可以到达。

换句话说，对于每一个可以到达的位置 xx，它使得 x+1, x+2, \cdots, x+\textit{nums}[x]x+1,x+2,⋯,x+nums[x] 这些连续的位置都可以到达。

这样以来，我们依次遍历数组中的每一个位置，并实时维护 最远可以到达的位置。对于当前遍历到的位置 xx，如果它在 最远可以到达的位置 的范围内，那么我们就可以从起点通过若干次跳跃到达该位置，因此我们可以用 x + \textit{nums}[x]x+nums[x] 更新 最远可以到达的位置。

在遍历的过程中，如果 最远可以到达的位置 大于等于数组中的最后一个位置，那就说明最后一个位置可达，我们就可以直接返回 True 作为答案。反之，如果在遍历结束后，最后一个位置仍然不可达，我们就返回 False 作为答案。

以题目中的示例一

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/jump-game/solution/tiao-yue-you-xi-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int length = nums.size();
        int maxDis = 0;
        for (int i = 0; i < length; i++) {
            if (i <= maxDis) {
                maxDis = max(maxDis, i + nums[i]);
                if (maxDis >= length - 1) return true;
            }
        }
        return false;
    }
};

int main() {
    int a[] = {2, 3, 1, 1, 4};
    vector<int> d(a, a + sizeof(a) / sizeof(int));
    cout << Solution().canJump(d);
}