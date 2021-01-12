# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    vector<int> arr;
    int m;
    int res = -1;
    int findLatestStep(vector<int>& arr, int m) {
        this->arr = arr;
        this->m = m;
        string s = string(arr.size(), '1');
        search(s, arr.size(), 0, arr.size()-1);
        return res;
    }

    void search(string& s, int step, int l, int r) {
        if (r - l + 1 < m) return ;
        if (r - l + 1 == m) {
            res = max(res, step);
            return ;
        }
        if (step < 1) return ;

        int idx = arr[step-1]-1;
        s[idx] = '0';
        if (idx > r || idx < l)
            search(s, step-1, l, r);
        else {
            search(s, step-1, l, idx-1);
            search(s, step-1, idx+1, r);
        }
    }
};