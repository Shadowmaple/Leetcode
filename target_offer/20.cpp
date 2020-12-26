# include <iostream>
using namespace std;

// 真正的面向测试用例编程
// 未过；测试点：1458/1480
class Solution {
public:
    bool isNumber(string s) {
        s.erase(0,s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);

        if (s.length() == 0) return false;

        int len = s.length();
        // 整数部分
        int idx = 0;
        while (idx < len && s[idx] != '.' && s[idx] != 'e' && s[idx] != 'E') {
            // 只允许数字或首位为正负号
            if (!idx && (s[idx] == '+' || s[idx] == '-') ||
                (s[idx] <= '9' && s[idx] >= '0')) {
                idx++;
                continue;
            }
            return false;
        }

        if (idx < len && s[idx] == '.') {
            // 只有 . 前有数值或后面有数值才是
            if (!(idx && s[idx-1] <= '9' && s[idx-1] >= '0' ||
                idx < len-1 && s[idx+1] <= '9' && s[idx+1] >= '0'))
            return false;
            idx++;
        }

        // 小数部分
        while (idx < len && s[idx] != 'e' && s[idx] != 'E') {
            if (s[idx] <= '9' && s[idx] >= '0') {
                idx++;
                continue;
            }
            return false;
        }

        if (idx < len && (s[idx] == 'E' || s[idx] == 'e')) {
            // E/e 前必须要有数字，后必须要有数字或正负号
            if (!(idx && (s[idx-1] <= '9' && s[idx-1] >= '0' || s[idx-1] == '.') ||
                idx < len-1 && s[idx+1] <= '9' && s[idx+1] >= '0'))
            return false;
            idx++;
        }

        // 允许首位为正负号，但不能为末尾
        if (idx < len && (s[idx] == '+' || s[idx] == '-')) {
            if (idx == len-1) return false;
            idx++;
        }

        // 指数部分
        while (idx < len) {
            if (s[idx] <= '9' && s[idx] >= '0') {
                idx++;
                continue;
            }
            return false;
        }
        return true;
    }
};

// 100%
class Solution2 {
public:
    int idx = 0;
    bool isNumber(string s) {
        s.erase(0,s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);

        if (s.length() == 0) return false;
        s += "#";

        bool numeric = scanInt(s);
        if (s[idx] == '.') {
            idx++;
            // 1.小数点左边有整数
            // 2.小数点右边有整数
            // 3.两边都有数字
            numeric = scanUnsingedInt(s) || numeric;
        }
        if (s[idx] == 'E' || s[idx] == 'e') {
            idx++;
            // e/E 需两边皆有整数
            numeric = numeric && scanInt(s);
        }

        return numeric && s[idx] == '#';
    }

    bool scanInt(string& s) {
        if (s[idx] == '+' || s[idx] == '-')
            idx++;
        return scanUnsingedInt(s);
    }

    bool scanUnsingedInt(string& s) {
        int before = idx;
        while (s[idx] <= '9' && s[idx] >= '0')
            idx++;
        return idx > before;
    }
};