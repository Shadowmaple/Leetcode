# include <iostream>
# include <vector>
# include <string>
using namespace std;

class Solution {
public:
    vector<int> v;
    vector<int> grayCode(int n) {
        string s(n, '0');
        backTracking(s, n, 0);
        return v;
    }

    void backTracking(string& s, int& n, int idx) {
        if (idx >= n) {
            string x(s);
            for (int i = n-1; i > 0; i--)
                x[i] = (x[i] == x[i-1]) ? '0' : '1';
            int num = 0;
            for (int i = 0; i < n; i++) {
                uint m = x[i] - '0' << (n - i - 1);
                num += m;
            }
            v.push_back(num);
            return ;
        }

        s[idx] = '0';
        backTracking(s, n, idx+1);
        s[idx] = '1';
        backTracking(s, n, idx+1);
    }
};