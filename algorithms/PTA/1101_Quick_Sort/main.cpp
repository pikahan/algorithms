#include <bits/stdc++.h>
using namespace std;

int main() {

    int num;
    cin >> num;
    vector<int> v;
    vector<int> min(num);
    vector<int> max(num);
    vector<int> ret;
    int m = INT_MIN;
    for (int i = 0; i < num; i++) {
        int n;
        cin >> n;
        min[i] = m;
        if (n > m) {
            m = n;
        }
        v.push_back(n);
    }

    m = INT_MAX;
    for (int i = v.size()-1; i >= 0; i--) {
        int n = v[i];
        max[i] = m;
        if (n < m) {
            m = n;
        }
    }

    for (int i = 0; i < v.size(); i++) {
        int n = v[i];
        int minN = min[i];
        int maxN = max[i];
        if (n > minN && n < maxN) {
            ret.push_back(n);
        }
    }
    if (ret.size() == 0) {
        cout << 0 << endl;
        cout << endl; // 天知道为什么要输出两行
        return 0;
    }
    cout << ret.size() << endl;
    sort(ret.begin(), ret.end());

    for (int i = 0; i < ret.size(); i++) {
        if (i == 0) cout << ret[i];
        else cout << ' ' << ret[i];
    }

    return 0;
}