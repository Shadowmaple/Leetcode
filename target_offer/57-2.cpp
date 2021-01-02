# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> result;
        vector<int> v;
        int l = 1, r = 1;
        int sum = 0;
        while (r <= target/2+1) {
            sum += r;
            while (sum > target) {
                sum -= l;
                l++;
            }
            if (sum == target) {
                for (int i=l; i <= r; i++)
                    v.push_back(i);
                result.push_back(v);
                v.clear();
                sum -= l;
                l++;
            }
            r++;
        }
        return result;
    }
};