# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        int pre[1000] = {0};
        while (1) {
            int num = 0;
            while (n) {
                num += (n % 10) * (n % 10);
                n /= 10;
            }
            cout << num << endl;
            if (num == 1) return true;
            if (pre[num]) return false;
            pre[num] = 1;
            n = num;
        }
        return false;
    }
};