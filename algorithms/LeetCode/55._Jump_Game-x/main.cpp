#include <bits/stdc++.h>


using namespace std;


/*
 *
 * 如果某一个作为 起跳点 的格子可以跳跃的距离是 3，那么表示后面 3 个格子都可以作为 起跳点。
可以对每一个能作为 起跳点 的格子都尝试跳一次，把 能跳到最远的距离 不断更新。
如果可以一直跳到最后，就成功了。

作者：ikaruga
链接：https://leetcode-cn.com/problems/jump-game/solution/55-by-ikaruga/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int length = nums.size();
        int maxDis = nums[0];
        for (int i = 1; i < length; i++) {
            if (maxDis < i) return false;
            maxDis = max(maxDis, i + nums[i]);
        }
        return true;
    }

};

int main() {
    int a[] = {2, 3, 1, 1, 4};
    vector<int> d(a, a + sizeof(a) / sizeof(int));
    cout << Solution().canJump(d);
}