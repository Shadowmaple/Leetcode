# include <iostream>
# include <vector>
# include <queue>
# include <set>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if (target == "0000") return 0;
        queue<string> q;
        set<string> st; // 保存已访问过的节点
        int path = 0;
        // 直接将 deadends 加入 st 中，就不用另外一个 set 了
        for (auto s : deadends) st.insert(s);

        if (!st.count("0000")) q.push("0000");
        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                string cur = q.front();
                q.pop();
                if (cur == target) return path;
                for (int i = 0; i < 4; i++) {
                    string s1 = cur, s2 = cur;
                    s1[i] = s1[i] < '9'? s1[i] + 1:'0';
                    s2[i] = s2[i] > '0'? s2[i] - 1:'9';

                    if (!st.count(s1)) {
                        st.insert(s1);
                        q.push(s1);
                    }
                    if (!st.count(s2)) {
                        st.insert(s2);
                        q.push(s2);
                    }
                }
            }
            path++;
        }
        return -1;
    }
};
