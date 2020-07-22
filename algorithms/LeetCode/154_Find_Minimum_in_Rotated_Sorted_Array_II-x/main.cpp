#include <bits/stdc++.h>


using namespace std;



class Solution {
public:
    int minArray(vector<int>& numbers) {
        int l = 0;
        int r = numbers.size() - 1;
        int mid;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (numbers[mid] > numbers[r]) {
                l = mid + 1;
            } else if (numbers[mid] < numbers[r]) {
                r = mid;
            } else {
                r--;
            }
        }
        return numbers[l];
    }
};