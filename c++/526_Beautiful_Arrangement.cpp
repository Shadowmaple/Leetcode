# include <iostream>
# include <string>
# include <vector>
using namespace std;

class Solution {
public:
    int countArrangement(int N) {
        int num = 0;
        vector<bool> used(N, false);
        backTracking(used, num, 1, N);
        return num;
    }

    void backTracking(vector<bool>& used, int& num, int idx, int& N) {
        if (idx > N) {
            num++;
            return ;
        }

        for (int i = 1; i <= N; i++) {
            if (used[i-1] || i % idx && idx % i)
                continue;

            used[i-1] = true;
            backTracking(used, num, idx+1, N);
            used[i-1] = false;
        }
    }
};