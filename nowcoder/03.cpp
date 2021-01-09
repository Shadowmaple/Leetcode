// 回溯超时……
// 滑动窗口，为什么想不到！菜是原罪！

# include <iostream>
# include <vector>
using namespace std;

vector<int> building;
long n, d;

int main() {
    cin >> n >> d;
    building = vector<int>(n);
    int val;
    for (int i = 0; i < n; i++) {
        cin >> val;
        building[i] = val;
    }
    int l = 0, r = 2;
    long res = 0;
    while (l < n - 2) {
        while (r < n && building[r] - d <= building[l]) r++;
        long len = r - l - 1;
        res += len * (len-1) / 2;
        l++;
    }
    cout << res % 99997867 << endl;

    return 0;
}