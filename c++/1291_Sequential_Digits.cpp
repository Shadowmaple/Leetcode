# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> v;
        for (int n = 1; n <= 9; n++) {
            int num = n;
            for (int i = n+1; num <= high && i <= 9; i++) {
                if (num >= low) v.push_back(num);
                num = num * 10 + i;
            }
            if (num <= high && num >= low)
                v.push_back(num);
        }
        sort(v.begin(), v.end());
        return v;
    }
};