//
// Created by 杨寒凌 on 2020/6/4.
//

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> ret;

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return ret;
        string phoneNumberArr[10] = {"", "abc", "def", "ghl", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        fn("", digits, 0);
        return ret;
    }

    void fn(string leftStr, string str, int pos) {
        string phoneNumberArr[11] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        char charNum = str.at(pos);
        string p = phoneNumberArr[charNum-'0'];
        for (char ch : p) {
            if (pos == str.size()-1) {
                ret.push_back(leftStr + ch);
            } else {
                fn(leftStr+ch, str, pos+1);
            }
        }



    }
};
