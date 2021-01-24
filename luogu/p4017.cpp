# include <iostream>
# include <vector>
# include <queue>
# include <map>
using namespace std;

int n, m;
vector<int> process; // 生产者
map<int, vector<int>> link;

// 未通过
int main() {
    cin >> n >> m;
    int visited[5000] = {0};
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        link[a].push_back(b);
        visited[b] = 1;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) q.push(i);
    }
    long depth = 0;
    while (!q.empty()) {
        int size = q.size();
        depth++;
        while (size--) {
            int cur = q.front();
            q.pop();
            for (auto i : link[cur]) {
                q.push(i);
            }
        }
    }
    cout << depth % 80112002 << endl;

    return 0;
}