# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> anum, bnum;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (!matrix[i][j]) {
                    anum.push_back(i);
                    bnum.push_back(j);
                }
            }
        }
        for (int i = 0; i < anum.size(); i++) {
            change(matrix, anum[i], bnum[i]);
        }
    }

    void change(vector<vector<int>>& matrix, int a, int b) {
        for (int i = a-1; i >= 0; i--)
            matrix[i][b] = 0;
        for (int i = a+1; i < matrix.size(); i++)
            matrix[i][b] = 0;
        for (int i = b-1; i >= 0; i--)
            matrix[a][i] = 0;
        for (int i = b+1; i < matrix[0].size(); i++)
            matrix[a][i] = 0;
    }
};
