# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> v;
        for (int n : A) {
            v.push_back(n*n);
        }
        sort(begin(v), end(v));
        return v;
    }
};

class Solution2 {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> v;
        int l = 0, r = A.size()-1;
        int lx = A[l]*A[l], rx = A[r]*A[r];
        while (l <= r) {
            if (lx > rx) {
                v.push_back(lx);
                l++;
                lx = A[l]*A[l];
            } else {
                v.push_back(rx);
                r--;
                if (r >= 0) rx = A[r]*A[r];
            }
        }
        reverse(v.begin(), v.end());
        return v;
    }
};