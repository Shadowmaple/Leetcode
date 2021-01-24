# include <iostream>
# include <vector>
# include <queue>
# include <map>
# include <set>
using namespace std;

int n, m;
map<int, vector<int>> link;
// 这里直接这样即可，全局变量初始化为 0
int out[10000], in[10000];
int path[10000];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        link[a].push_back(b);
        in[b]++;
        out[a]++;
    }

    int count = 0;
    queue<int> q;

    // 获取入度为 0 的节点
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            q.push(i);
            path[i] = 1;
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto num : link[cur]) {
            in[num]--;
            path[num] += path[cur];
            path[num] %= 80112002;
            if (in[num] == 0) {
                if (out[num] == 0) {
                    count += path[num];
                    count %= 80112002;
                } else q.push(num);
            }
        }
    }

    cout << count << endl;

    return 0;
}

/*
总结：
这题题目看错了，以为是最长食物链的生物数，提交一直 WA，看了题解才知道是食物链数量

Tips:
ACM 中结果要取模时，一般都是中途取模，而不是最后取模
*/