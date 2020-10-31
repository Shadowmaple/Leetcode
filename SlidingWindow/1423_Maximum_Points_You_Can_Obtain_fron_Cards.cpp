# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int len = cardPoints.size();
        int cap = len - k;
        int r = cap - 1, idx = r;
        int num = 0, sum = 0;
        for (int i = 0; i < len; i++) {
            sum += cardPoints[i];
            if (i < cap) num += cardPoints[i];
        }
        int cur = num;
        while (++r < len) {
            cur += cardPoints[r] - cardPoints[r - cap];
            if (cur < num) {
                num = cur;
                idx = r;
            }
        }
        return sum - num;
    }
};