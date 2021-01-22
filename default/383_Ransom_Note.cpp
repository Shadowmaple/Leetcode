# include <iostream>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int own[128] = {0};
        for (char c : magazine) {
            own[c]++;
        }
        for (char c : ransomNote) {
            own[c]--;
            if (own[c] < 0) return false;
        }
        return true;
    }
};