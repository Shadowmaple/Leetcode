# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> v;
    bool *cols, *mainDia, *subDia;
    vector<vector<string>> solveNQueens(int n) {
        vector<int> cmb;
        cols = new bool[n]{false};
        mainDia = new bool[n*2]{false};;
        subDia = new bool[n*2]{false};
        backTracing(0, n, cmb);
        return v;
    }

    void backTracing(int row, int& n, vector<int>& cmb) {
        if (row == n) {
            vector<string> arr;
            for (int i = 0; i < n; i++) {
                string s(n, '.');
                s[cmb[i]] = 'Q';
                arr.push_back(s);
            }
            v.push_back(arr);
            return ;
        }

        for (int i = 0; i < n; i++) {
            if (cols[i] || mainDia[i-row+n] || subDia[i+row])
                continue;

            cols[i] = mainDia[i-row+n] = subDia[i+row] = true;
            cmb.push_back(i);
            backTracing(row+1, n, cmb);
            cmb.pop_back();
            cols[i] = mainDia[i-row+n] = subDia[i+row] = false;
        }
    }
};