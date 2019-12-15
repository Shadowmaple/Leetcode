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

int main() {
    Solution s;
    cout << s.totalNQueens(8) << endl;
    return 0;
}
