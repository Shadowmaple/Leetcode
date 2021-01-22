# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0, minP = INT32_MAX;
        for (int p : prices) {
            result = max(p - minP, result);
            minP = min(p, minP);
        }
        return result;
    }
};