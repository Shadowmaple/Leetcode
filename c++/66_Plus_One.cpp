# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() - 1;
        int flag = 1;
        do {
            int x = digits.at(n) + flag;
            digits.at(n--) = x % 10;
            flag = x / 10;
        } while (flag && n >= 0);

        if (!flag || n >= 0) {
            return digits;
        }

        vector<int> d;
        d.push_back(flag);
        for (int i=0; i < digits.size(); i++) {
            d.push_back(digits.at(i));
        }
        return d;
    }
};
