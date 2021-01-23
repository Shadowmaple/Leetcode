# include <iostream>
# include <vector>
using namespace std;

int num[100][100], len[100][100];
int n, m;

int DFS(int row, int col, int pre) {
    if (row < 0 || col < 0 || row >= n || col >= m)
        return 0;
    if (num[row][col] <= pre) return 0;
    if (len[row][col] != 0) return len[row][col];
    len[row][col] = 1 + max(
            max(DFS(row+1, col, num[row][col]), DFS(row-1, col, num[row][col])),
            max(DFS(row, col+1, num[row][col]), DFS(row, col-1, num[row][col]))
        );
    return len[row][col];
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> num[i][j];
            len[i][j] = 0;
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res = max(res, DFS(i, j, -1));
        }
    }

    cout << res << endl;
    return 0;
}