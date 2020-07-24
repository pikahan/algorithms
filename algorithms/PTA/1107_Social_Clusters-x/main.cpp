#include <bits/stdc++.h>
using namespace std;

#define SIZE 1010

// hobby[i]表示的是第一个喜欢i号hobby的人的编号
vector<int> counter, father;

bool cmpl(int a, int b) {
    return a > b;
}

int find(int x) {
    int temp = x;
    while (x != father[x]) {
        x = father[x];
    }

    // 压缩路径, 防止长长的链式寻找
    while (temp != father[temp]) {
        int t = temp;
        temp = father[temp];
        father[t] = x;
    }

    return x;
}

void unionHelper(int a, int b) {
    int fatherA = find(a);
    int fatherB = find(b);
    if (fatherA != fatherB) {
        father[fatherA] = fatherB;
    }
}

int main() {
    int n;
    cin >> n;
    counter.resize(n+1);
    father.resize(n+1);
    int hobby[1001] = {0};
    for (int i = 1; i <= n; i++) father[i] = i; // 初始节点就是其本身

    for (int i = 1; i <= n; i++) {
        int hobbyNum;
        cin >> hobbyNum;
        string blank;
        cin >> blank;
        for (int j = 0; j < hobbyNum; j++) {
            int hobbyId;
            cin >> hobbyId;
            if (hobby[hobbyId] == 0) hobby[hobbyId] = i;
            unionHelper(i, hobby[hobbyId]);
        }
    }

    for (int i = 1; i <= n; i++) counter[find(i)]++;

    // 判断有多少圈子
    int sum = 0;
    for (int i = 1; i <= n; i++) if (counter[i] != 0) sum++;
    cout << sum << endl;

    sort(counter.begin(), counter.end(), cmpl);
    for (int i = 0; i < sum; i++) {
        if (i == 0) printf("%d", counter[i]);
        else printf(" %d", counter[i]);
    }

    return 0;
}
