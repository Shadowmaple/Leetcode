# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int l = 0, r = 0;
        int result = 0, n = grumpy.size();
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) result += customers[i];
        }
        int num = result;
        while (r < n) {
            if (grumpy[r] == 0) {
                r++;
                continue;
            } else if (r - l + 1 <= X) {
                num += customers[r];
                r++;
                continue;
            }
            result = max(result, num);
            if (grumpy[l] == 1) num -= customers[l];
            l++;
        }
        return max(result, num);
    }
};