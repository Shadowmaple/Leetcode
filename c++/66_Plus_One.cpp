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

        digits.push_back(0);
        digits.at(0) = 1;
        return digits;
    }
};
