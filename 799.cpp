# include <iostream>
# include <vector>
using namespace std;

// 模拟
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        auto v = vector<vector<double>>(query_row+2, vector<double>(query_row+2, 0));
        v[0][0] = poured;
        for (int i = 0; i <= query_row; i++) {
            for (int j = 0; j <= i; j++) {
                if (v[i][j] <= 1) continue;
                v[i+1][j] += (v[i][j]-1) / 2;
                v[i+1][j+1] += (v[i][j]-1) / 2;
                v[i][j] = 1;
            }
        }
        return v[query_row][query_glass];
    }
};