# include<iostream>
# include<string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string str[numRows];
        int len = s.length(), i = 0;
        while (i < len) {
            for (int j = 0; j < numRows && i < len; j++)
                str[j].push_back(s[i++]);

            for (int j = numRows-2; j > 0 && i < len; j--)
                str[j].push_back(s[i++]);
        }
        s = str[0];
        for (i = 1; i < numRows; i++)
            s.append(str[i]);

        return s;
    }
};

int main() {
    Solution c;
    cout << c.convert("LEETCODEISHIRING", 4) << endl;
    return 0;
}