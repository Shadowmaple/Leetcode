# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        if (time.size() < 2) return 0;
        int res = 0;
        int num[60] = {0};
        for (auto t : time) {
            int temp = t % 60;
            if (!temp) res += num[0];
            else res += num[60-temp];
            num[temp]++;
        }
        return res;
    }
};