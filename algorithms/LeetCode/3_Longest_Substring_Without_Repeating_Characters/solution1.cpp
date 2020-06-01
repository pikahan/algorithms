//
// Created by 杨寒凌 on 2020/6/1.
//
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
//        内存空间占用的更多
//        string str;
//        int ret = 0;
//        for (auto it = s.begin(); it != s.end(); it++) {
//            char ch = *it;
//            int pos;
//            if ((pos = str.find(ch)) != string::npos) {
//                str = str.substr(pos + 1) + ch;
//            } else {
//                str += ch;
//                ret = ret > str.size() ? ret : str.size();
//            }
//        }
//        return ret;
        unordered_set<char> set;
        int left = 0;
        int ret = 0;
        for (int i = 0; i < s.size(); i++) {
            while (set.find(s[i]) != set.end()) {
                set.erase(s[left]);
                left++;
            }

            set.insert(s[i]);
            ret = max(ret, i - left + 1);
        }
        return ret;
    }
};