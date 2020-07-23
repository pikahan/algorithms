#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> m1 = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    vector<string> m2 = {"null", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

    string countStr;
    getline(cin, countStr);
    int count;
    stringstream ss;
    ss << countStr;
    ss >> count;
    for (int i = 0; i < count; i++) {
        string str;
        getline(cin, str);
        if (str[0] >= '0' && str[0] <= '9') {
            stringstream ss;
            int num;
            ss << str;
            ss >> num;
            int ge = num % 13;
            int shi = num / 13;
            if (shi) {
                if (ge == 0) {
                    cout << m2[shi];
                } else {
                    cout << m2[shi] << ' ' << m1[ge];

                }
            } else {
                cout << m1[ge];
            }
        } else {
            auto blank = str.find(' ');
            if (blank == -1) { // x0 || x
                auto r = find(m2.begin(), m2.end(), str) - m2.begin();
                if (r < 13) {
                    cout << r * 13;
                } else {
                    auto l = find(m1.begin(), m1.end(), str) - m1.begin();
                    cout << l;
                }
            } else {
                string leftStr = str.substr(0, blank);
                string rightStr = str.substr(blank+1, str.size() - blank);
                auto r = find(m2.begin(), m2.end(), leftStr) - m2.begin();
                auto l = find(m1.begin(), m1.end(), rightStr) - m1.begin();
                cout << r * 13 + l;
            }
        }
        cout << endl;
    }

    return 0;
}