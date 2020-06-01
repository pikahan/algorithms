//
// Created by 杨寒凌 on 2020/6/1.
//
#include <bits/stdc++.h>
using namespace std;

// 中心扩散法
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 0) return "";
        string ret(1, s[0]);
        for (int i = 0; i < s.size(); i++) {
            int leftPos = i-1;
            int rightPos = i+1;

            while (leftPos >= 0 && rightPos < s.size() && s[leftPos] == s[rightPos]) {
                leftPos--;
                rightPos++;
            }
            int palindromicLength = rightPos - leftPos - 1;
            if (palindromicLength > ret.length()) {
                ret = s.substr(leftPos + 1, palindromicLength);
            }

            leftPos = i;
            rightPos = i + 1;
            while (leftPos >= 0 && rightPos < s.size() && s[leftPos] == s[rightPos]) {
                leftPos--;
                rightPos++;
            }
            palindromicLength = rightPos - leftPos - 1;
            if (palindromicLength > ret.length()) {
                ret = s.substr(leftPos + 1, palindromicLength);
            }
        }
        return ret;
    }
};

int main() {
    Solution().longestPalindrome("cbbd");


    return 0;
}