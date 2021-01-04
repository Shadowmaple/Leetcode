# include <iostream>
using namespace std;

class Solution {
public:
    int add(int a, int b) {
        while (b) {
            int temp = (unsigned)(a & b) << 1;
            a ^= b;
            b = temp;
        }
        return a;
    }
};

// 递归版本
class Solution {
public:
    int add(int a, int b) {
        if (!b) return a;
        int temp = (unsigned)(a & b) << 1;
        a ^= b;
        return add(a, temp);
    }
};