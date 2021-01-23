# include <iostream>
# include <vector>
using namespace std;

int n;
int nums[20]; // 每个地窖的地雷数
int path[20][20]; // 地窖之间是否连通，无向连通图
int visited[20], res;
vector<int> v, result;

void DFS(int idx, int cur) {
    cur += nums[idx];
    v.push_back(idx);
    visited[idx] = 1;

    bool isEnd = true;
    for (int i = 0; i < n; i++) {
        if (idx == i || !path[idx][i] || visited[i])
            continue;
        DFS(i, cur);
        isEnd = false;
    }
    if (isEnd && res < cur) {
        res = cur;
        result = v;
    }

    visited[idx] = 0;
    v.pop_back();
    return ;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> nums[i];
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = i+1; j < n; j++) {
            cin >> path[i][j];
            path[j][i] = 0;
        }
    }
    res = 0;
    for (int i = 0; i < n; i++)
        DFS(i, 0);

    for (int i = 0; i < result.size(); i++) {
        if (i) cout << ' ';
        cout << result[i] + 1;
    }
    cout << endl << res << endl;

    return 0;
}