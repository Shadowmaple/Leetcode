# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for (int i = 1; i < n; i++) {
            int len = triangle[i].size();
            for (int j = 0; j < len; j++) {
                if (j && j < len-1)
                    triangle[i][j] += min(triangle[i-1][j], triangle[i-1][j-1]);
                else if (j)
                    triangle[i][j] += triangle[i-1][j-1];
                else
                    triangle[i][j] += triangle[i-1][j];
            }
        }
        int min = triangle[n-1][0];
        for (int x : triangle[n-1]) {
            if (x < min) min = x;
        }
        return min;
    }
};