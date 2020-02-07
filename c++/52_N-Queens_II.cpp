# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        vector<int> v;
        int count = 0, i = 0, num = n * n;
        do {
            while (i < num && v.size() < n) {
                if (isValid(v, n, i)) {
                    v.push_back(i);
                    i = (i / n + 1) * n;
                    continue;
                }
                i++;
            }
            if (v.size() >= n) {
                count++;
            } else
                i = v.back() + 1;

            v.pop_back();
        } while (i < num || !v.empty());

        return count;
    }

    bool isValid(vector<int>& v, int n, int e) {
        int e_col = e % n, e_row = e / n;
        for (int i = 0; i < v.size(); i++) {
            int col = v[i] % n;
            int row = v[i] / n;
            if (col == e_col || abs(col - e_col) == abs(row - e_row))
                return false;
        }
        return true;
    }
};

class Solution2 {
public:
    int count;
    int totalNQueens(int n) {
        count = 0;
        bool mainDia[n*2] = {false}, subDia[n*2] = {false}, cols[n] = {false};
        backTacking(n, 0, mainDia, subDia, cols);
        return count;
    }

    void backTacking(int& n, int row, bool* mainDia, bool* subDia, bool* cols) {
        if (row == n) {
            count++;
            return ;
        }

        for (int i = 0; i < n; i++) {
            if (cols[i] || mainDia[row-i+n] || subDia[row+i])
                continue;

            mainDia[row-i+n] = true;
            subDia[row+i] = true;
            cols[i] = true;

            backTacking(n, row+1, mainDia, subDia, cols);

            mainDia[row-i+n] = false;
            subDia[row+i] = false;
            cols[i] = false;
        }
    }
};

int main() {
    Solution2 s;
    cout << s.totalNQueens(8) << endl;
    return 0;
}
