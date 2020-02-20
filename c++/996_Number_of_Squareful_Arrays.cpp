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
        return DFS(A, cmb, visited);
    }

    int DFS(vector<int>& A, vector<int>& cmb, vector<bool>& visited) {
        if (cmb.size() == A.size()) {
            for (int i = 0; i < cmb.size()-1; i++) {
                int n = cmb[i] + cmb[i+1];
                int x = sqrt(n);
                if (pow(x, 2) != n) return 0;
            }
            return 1;
        }

        int count = 0;
        for (int i = 0; i < A.size(); i++) {
            if (visited[i] || i > 0 && A[i] == A[i-1] && !visited[i-1])
                continue;
            visited[i] = true;
            cmb.push_back(A[i]);
            count += DFS(A, cmb, visited);
            cmb.pop_back();
            visited[i] = false;
        }
        return count;
    }
};