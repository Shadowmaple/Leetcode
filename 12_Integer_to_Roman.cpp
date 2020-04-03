# include <iostream>
# include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string s;
        string roman[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        int power[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        for (int i = 12; i >= 0; i--) {
            while (num >= power[i]) {
                s += roman[i];
                num -= power[i];
            }
        }
        return s;
    }
};