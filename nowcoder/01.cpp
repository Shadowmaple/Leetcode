# include <iostream>
using namespace std;

string fix(string s) {
    string res;
    int l = -1, r = 0;
    while (r < s.length()) {
        // aaa
        if (l > 0 && s[r] == res[l] && res[l] == res[l-1]) {
            r++;
            continue;
        }
        // aabb
        if (l > 1 && res[l-1] == res[l-2] && res[l] == s[r]) {
            r++;
            continue;
        }
        res += s[r];
        r++;
        l++;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    string s;
    while (n--) {
        cin >> s;
        cout << fix(s) << endl;
    }
    return 0;
}