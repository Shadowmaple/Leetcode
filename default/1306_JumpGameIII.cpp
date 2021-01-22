# include <iostream>
# include <vector>
# include <queue>
# include <set>
using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        q.push(start);
        int n = arr.size();
        set<int> visited;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            int left = cur - arr[cur], right = cur + arr[cur];
            if (left >= 0 && !arr[left] || right < n && !arr[right])
                return true;
            if (left >= 0 && !visited.count(left)) {
                q.push(left);
                visited.insert(left);
            }
            if (right < n && !visited.count(right)) {
                q.push(right);
                visited.insert(right);
            }
        }
        return false;
    }
};