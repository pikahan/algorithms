#include <bits/stdc++.h>
using namespace std;
bool globalFlag = true;
void inOrder(map<string, pair<string, string>> map, string id) {

    auto p = map[id];
    string left = p.first;
    string right = p.second;

    if (right != "-") {
        inOrder(map, right);
    }

    if (globalFlag) {
        cout << id;
        globalFlag = false;
    } else {
        cout << " " << id;
    }


    if (left != "-") {
        inOrder(map, left);
    }
}

int main() {
    int num;
    cin >> num;
    map<string, pair<string, string>> map;
    vector<int> set(num, 0);
    for (int i = 0; i < num; i++) {
        string id = to_string(i);
        string left;
        string right;
        cin >> left;
        cin >> right;

        if (right != "-") {
            stringstream ss;
            ss << right;
            int n;
            ss >> n;
            set[n] = 1;
        }
        if (left != "-") {
            stringstream ss;
            ss << left;
            int n;
            ss >> n;
            set[n] = 1;
        }
        map[id] = {left, right};
    }
    int id;
    for (id = 0; id < num; id++) {
        if (set[id] == 0) break;
    }
    string idStr = to_string(id);

    queue<string> q;
    q.push(idStr);
    int first = 1;
    while (!q.empty()) {
        string currId = q.front();
        q.pop();
        if (first) {
            cout << currId;
            first = 0;
        } else {
            cout << ' ' << currId;
        }
        auto p = map[currId];
        string left = p.first;
        string right = p.second;

        if (right != "-") {
            q.push(right);
        }
        if (left != "-") {
            q.push(left);
        }
    }
    cout << endl;
    inOrder(map, idStr);

    return 0;
}