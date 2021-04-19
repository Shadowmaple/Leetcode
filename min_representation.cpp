# include <iostream>
# include <string>
using namespace std;

// 最小表示法
// 用于求一个字符串，其所有循环同构的字符串中字典序最小的
// 如 8224，其备选有 8244、2248、2482、4822，字典序最小的是2248
int Foo(string& s) {
    int len = s.length();
    int i = 0, j = 1, k = 0;
    while (i < len && j < len && k < len) {
        int temp = s[(i+k)%len] - s[(j+k)%len];
        if (temp == 0) {
            k++;
            continue;
        } else if (temp > 0) {
            i += k + 1;
        } else {
            j += k + 1;
        }
        if (i == j) j++;
        k = 0;
    }
    return min(i, j);
}

int main() {
    string s;
    s = "8335226";
    int idx = Foo(s);
    cout << idx << endl;
    string temp;
    for (int i = idx; i < s.length(); i++) {
        temp += s[i];
    }
    for (int i = 0; i < idx; i++) {
        temp += s[i];
    }
    cout << temp << endl;

    return 0;
}