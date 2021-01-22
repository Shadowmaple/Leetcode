# include <iostream>
# include <string>
# include <vector>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> sk;
        string s;
        int len = path.length();
        for (int i = 0; i < len; i++) {
            if (path[i] != '/') {
                s += path[i];
                if (i != len-1) continue;
            }
            if (s == "") continue;
            if (s == ".." && !sk.empty())
                sk.pop_back();
            else if (s != ".." && s != ".")
                sk.push_back(s);

            s.clear();
        }
        if (sk.empty()) return "/";
        for (string x : sk)
            s += "/" + x;

        return s;
    }
};

int main() {
    Solution s;
    cout << s.simplifyPath("/a/../../b/../c//.//") << endl;
    return 0;
}