//
//  main.cpp
//  pat
//
//  Created by 杨寒凌 on 2020/2/17.
//  Copyright © 2020 杨寒凌. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    string num;
    cin >> num;

    int sum = 0;
    for (auto ch : num) {
        sum += ch - '0';
    }
    string englishDigits[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    string retStr = to_string(sum);
    int firstFlag = 1;

    for (auto ch : retStr) {
        if (firstFlag) {
            firstFlag = 0;
        }  else {
            cout << ' ';
        }
        cout << englishDigits[ch-'0'];
    }

    return 0;
}


