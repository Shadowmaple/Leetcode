# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        if (numRows < 1) return v;

        v.push_back(vector<int>{1});
        vector<int> row;
        for (int i=1; i < numRows; i++) {
            for (int j=0; j <= i; j++) {
                int l = (j == 0)? 0 : v[i-1][j-1];
                int r = (j == i)? 0 : v[i-1][j];
                row.push_back(l + r);
            }
            v.push_back(row);
            row.clear();
        }
        return v;
    }
};
