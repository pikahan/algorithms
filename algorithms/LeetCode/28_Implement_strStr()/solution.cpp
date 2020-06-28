//
// Created by 杨寒凌 on 2020/6/28.
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int needleSize = needle.size();
        int haystackSize = haystack.size();
        if (needleSize == 0) return 0;
        if (needleSize > haystackSize) return -1;
        int ret = -1;
        for(int i = 0; i < haystackSize - needleSize + 1; i++) {
            if (haystack[i] == needle[0]) {
                int flag = 1;
                int needlePos = 1;
                while (needlePos < needleSize) {
                    if (i+needlePos < haystackSize && haystack[i+needlePos] == needle[needlePos]) {
                        needlePos++;
                    } else {
                        flag = 0;
                        break;
                    }
                }
                if (flag) {
                    return i;
                }
            }
        }
        return ret;
    }
};