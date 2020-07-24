#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> m;
double minPrice = DBL_MAX, rate;
int counter = 0;

void dfs(int index, double currPrice) {
    if (m[index].size() == 0) {
        if (currPrice < minPrice) {
            counter = 1;
            minPrice = currPrice;
        } else if (currPrice == minPrice) {
            counter++;
        }
        return;
    }

    for (auto i: m[index]) {
        dfs(i, currPrice * (1 + rate));
    }
}

int main() {
    int n;
    double rootPrise;
    cin >> n >> rootPrise >> rate;
    rate /= 100;
    m = vector<vector<int>>(n);
    for (int i = 0; i < n; i++) {
        int number;
        cin >> number;
        vector<int> l(number);
        for (int j = 0; j < number; j++) {
            int t;
            cin >> t;
            l[j] = t;
        }
        m[i] = l;
    }
    dfs(0, rootPrise);
    printf("%.4f %d", minPrice, counter);
    return 0;
}
