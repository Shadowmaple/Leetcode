# include <iostream>
# include <math.h>
# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    int numSquarefulPerms(vector<int>& A) {
        sort(A.begin(), A.end());
        vector<bool> visited(A.size(), false);
        vector<int> cmb;
        return DFS(A, visited, 0, 0);
    }

    int DFS(vector<int>& A, vector<bool>& visited, int pre, int idx) {
        if (idx == A.size())
            return 1;

        int count = 0;
        for (int i = 0; i < A.size(); i++) {
            if (visited[i] || i > 0 && A[i] == A[i-1] && !visited[i-1])
                continue;
            if (idx) {
                int n = pre + A[i], x = sqrt(n);
                if (pow(x, 2) != n) continue;
            }
            visited[i] = true;
            count += DFS(A, visited, A[i], idx+1);
            visited[i] = false;
        }
        return count;
    }
};