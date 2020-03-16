# include <iostream>
# include <string>
using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if (name[0] != typed[0]) return false;
        int i = 1, j = 1;
        while (i < name.length() && j < typed.length()) {
            if (name[i] == typed[j]) {
                i++;
                j++;
            } else if (typed[j] != typed[j-1])
                return false;
            else j++;
        }
        if (i < name.length()) return false;
        while (j < typed.length()) {
            if (typed[j] != typed[j-1]) return false;
            j++;
        }
        return true;
    }
};