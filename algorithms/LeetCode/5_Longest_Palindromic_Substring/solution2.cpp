//
// Created by 杨寒凌 on 2020/6/1.
//
#include <bits/stdc++.h>
using namespace std;

// 动态规划法

/*
第 1 步：定义状态
        dp[i][j] 表示子串 s[i..j] 是否为回文子串，这里子串 s[i..j] 定义为左闭右闭区间，可以取到 s[i] 和 s[j]。

第 2 步：思考状态转移方程
        在这一步分类讨论（根据头尾字符是否相等），根据上面的分析得到：

dp[i][j] = (s[i] == s[j]) and dp[i + 1][j - 1]
说明：

「动态规划」事实上是在填一张二维表格，由于构成子串，因此 i 和 j 的关系是 i <= j ，因此，只需要填这张表格对角线以上的部分。

看到 dp[i + 1][j - 1] 就得考虑边界情况。

边界条件是：表达式 [i + 1, j - 1] 不构成区间，即长度严格小于 2，即 j - 1 - (i + 1) + 1 < 2 ，整理得 j - i < 3。

这个结论很显然：j - i < 3 等价于 j - i + 1 < 4，即当子串 s[i..j] 的长度等于 2 或者等于 3 的时候，其实只需要判断一下头尾两个字符是否相等就可以直接下结论了。

如果子串 s[i + 1..j - 1] 只有 1 个字符，即去掉两头，剩下中间部分只有 11 个字符，显然是回文；
如果子串 s[i + 1..j - 1] 为空串，那么子串 s[i, j] 一定是回文子串。
因此，在 s[i] == s[j] 成立和 j - i < 3 的前提下，直接可以下结论，dp[i][j] = true，否则才执行状态转移。

第 3 步：考虑初始化
        初始化的时候，单个字符一定是回文串，因此把对角线先初始化为 true，即 dp[i][i] = true 。

事实上，初始化的部分都可以省去。因为只有一个字符的时候一定是回文，dp[i][i] 根本不会被其它状态值所参考。

第 4 步：考虑输出
        只要一得到 dp[i][j] = true，就记录子串的长度和起始位置，没有必要截取，这是因为截取字符串也要消耗性能，记录此时的回文子串的「起始位置」和「回文长度」即可。
        https://leetcode-cn.com/problems/longest-palindromic-substring/solution/zhong-xin-kuo-san-dong-tai-gui-hua-by-liweiwei1419/
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) return s;
        int maxLen = 1;
        int begin = 0;
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        for (int j = 1; j < n; j++) {
            for (int i = 0; i < j; i++) {
                if (s[i] != s[j]) {
                    dp[i][j] = 0;
                } else {
                    if (j - i > 2) { // 能构成区间
                        dp[i][j] = dp[i+1][j-1];
                    } else { // 不能构成区间
                        dp[i][j] = 1;
                    }
                }

                if (dp[i][j] && j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxLen);

    }
};

int main() {
    Solution().longestPalindrome("cbbd");


    return 0;
}