# include <iostream>
# include <string>
using namespace std;


class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.length(), len2 = num2.length();
        string num(len1+len2, '0');
        for (int i = len2 - 1; i >= 0; i--) {
            int n = num2[i] - '0';
            for (int j = len1 - 1; j >= 0; j--) {
                // 乘运算和最后的加运算合并，相乘的同时相加，不将加运算独立出来
                // 相乘，再加上当前位
                int m = (num1[j] - '0') * n + (num[i+j+1] - '0');
                num[i+j+1] = m % 10 + '0'; // 当前位
                num[i+j] += m / 10; // 加上进位
                // num[i+j] = m / 10 + (num[i+j] - '0') + '0';
            }
        }

        // 去除首部的0
        for (int i = 0; i < num.length(); i++) {
            if (num[i] == '0') continue;
            return num.substr(i);
        }
        return "0";
    }
};