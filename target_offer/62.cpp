# include <iostream>
# include <queue>
using namespace std;

// 队列模拟，显然超时
class Solution {
public:
    int lastRemaining(int n, int m) {
        queue<int> q;
        for (int i = 0; i < n; i++) q.push(i);
        int pc = 1;
        while (q.size() > 1) {
            int cur = q.front();
            q.pop();
            if (pc++ == m) {
                pc = 1;
                continue;
            }
            q.push(cur);
        }
        return q.front();
    }
};

// 约瑟夫环问题，递推公式
class Solution {
public:
    int lastRemaining(int n, int m) {
        int res = 0;
        for (int i = 2; i <= n; i++) {
            res = (res + m) % i;
        }
        return res;
    }
};