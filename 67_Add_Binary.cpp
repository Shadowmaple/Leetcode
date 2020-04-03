# include <iostream>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string n;
        int i = a.length()-1, j = b.length()-1;
        int flag = 0, x;
        for (; i >= 0 || j >= 0; i--, j--) {
            if (i < 0)
                x = b[j] - '0' + flag;
            else if (j < 0)
                x = a[i] - '0' + flag;
            else
                x = (a[i] - '0') + (b[j] - '0') + flag;
            flag = x / 2;
            char c = x % 2 + '0';
            n = c + n;
        }
        if (flag) n = '1' + n;
        return n;
    }
};

int main() {
    Solution s;
    cout << s.addBinary("1010", "1011") << endl;
    return 0;
}
