# include <iostream>
# include <queue>
using namespace std;

int main() {
    int n = 100, m = 5;
    queue<int> q;
    q.push(n);
    int count = 0;
    while (!q.empty()) {
        int size = q.size();
        count++;

        int temp = m;
        while (size-- && temp--) {
            int cur = q.front();
            q.pop();
            int x = cur >> 1;
            if (x > 1) q.push(x);
            if (cur - x > 1) q.push(cur - x);
        }
    }
    cout << count << endl;
    return 0;
}