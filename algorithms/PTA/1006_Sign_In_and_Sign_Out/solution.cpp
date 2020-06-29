//
// Created by 杨寒凌 on 2020/6/29.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int count;
    cin >> count;
    string earlierUnLockedTime = "23:59:59";
    string earlierUnLockedPerson;

    string earlierLockedTime =  "00:00:00";
    string laterLockedPerson;

    for (int i = 0; i < count; i++) {
        string name, unLockedTime, lockedTime;
        cin >> name >> unLockedTime >> lockedTime;
        if (unLockedTime < earlierUnLockedTime) {
            earlierUnLockedPerson = name;
            earlierUnLockedTime = unLockedTime;
        }
        if (lockedTime > earlierLockedTime) {
            laterLockedPerson = name;
            earlierLockedTime = lockedTime;
        }
    }
    cout << earlierUnLockedPerson << ' ' << laterLockedPerson;
}