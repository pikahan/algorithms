#include <bits/stdc++.h>
using namespace std;

bool isDigit(char ch) {
    return ch >= '0' && ch <= '9';
}

bool isNumberStr(string str) {
    if (str.size() == 0) return false;
    bool fuFlag = false;
    bool dianFlag = false;
    int dianDigitSum = 0;
    for (int i = 0; i < str.size(); i++) {
        char ch = str[i];
        if (i == 0 && ch == '-') {
            fuFlag = true;
            if (!isDigit(str[1])) return false;
        } else if (isDigit(ch)) {
            if (dianFlag) {
                dianDigitSum++;
            }
        } else {
            if (ch == '.' ) {
                if (dianFlag) return false;
                dianFlag = true;
            } else {
                return false;
            }
        }
    }


    bool retFlag = true;

    if (dianFlag) {
        retFlag =   dianDigitSum < 3;
    }

    if (fuFlag) {
        if (dianFlag) {
            retFlag = retFlag && str.size() > 2;
        } else {
            retFlag = retFlag && str.size() > 1;
        }
    }
    return retFlag;
}

int main() {
    int n;
//    cout << isNumberStr("-.1") << endl;
//    cout << isNumberStr("-3.1") << endl;
//    cout << isNumberStr("-2.12") << endl;
//    cout << isNumberStr("-2.122") << endl;

    cin >> n;
    double sum = 0;
    int counter = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (isNumberStr(s)) {
            stringstream ss;
            ss << s;
            double number;
            ss >> number;
            if (number > 1000 || number < -1000) {
                printf("ERROR: %s is not a legal number\n", s.c_str());
            } else {
                counter++;
                sum += number;
            }
        } else {
            printf("ERROR: %s is not a legal number\n", s.c_str());
        }
    }
    if (counter == 0) {
        printf("The average of 0 numbers is Undefined");
    } else if (counter == 1) {
        printf("The average of %d number is %.2f", counter, sum/counter);
    } else {
        printf("The average of %d numbers is %.2f", counter, sum/counter);

    }

    return 0;
}
