# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());

        int count = 0;
        int i = 0, j = 0;
        while (i < g.size() && j < s.size()) {
            if (g[i] <= s[j]) {
                count++;
                i++;
            }
            j++;
        }
        return count;
    }
};