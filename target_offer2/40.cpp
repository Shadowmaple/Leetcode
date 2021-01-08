# include <iostream>
# include <vector>
# include <queue>
using namespace std;

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res;
        if (!k) return res;

        priority_queue<int, vector<int>, greater<int>> q;
        for (int n : arr) q.push(n);

        while (k--) {
            res.push_back(q.top());
            q.pop();
        }

        return res;
    }
};