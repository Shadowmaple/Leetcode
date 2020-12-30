# include <iostream>
# include <string>
using namespace std;

class Solution {
public:
    int translateNum(int num) {
        string s = to_string(num);
        return DFS(s, 0);
    }

    int DFS(string& s, int idx) {
        if (idx >= s.length()) return 1;

        int num = DFS(s, idx+1);
        if (s[idx] != '0' && idx < s.length()-1 && stoi(s.substr(idx, 2)) < 26)
            num += DFS(s, idx+2);
        return num;
    }
};