#include <bits/stdc++.h>


using namespace std;

int main()
{
    int preStep = 0;
    int sum = 0;
    int count;
    cin >> count;
    for (int i = 0; i < count; i++) {
        int currStep;
        cin >> currStep;
        int dis = currStep - preStep;
        if (dis > 0) {
            sum += dis * 6 + 5;
        } else if (dis < 0) {
            sum += -dis * 4 + 5;
        } else {
            sum += 5;
        }
        preStep = currStep;
    }
    cout << sum;
    return 0;
}