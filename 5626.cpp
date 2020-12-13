# include <iostream>
using namespace std;

// 本以为是BFS、DFS，甚至动态规划
// 结果TMD竟然是“奥数题”！
// 核心是二进制数的思想
// BFS、DFS都超时orz
class Solution {
public:
    int minPartitions(string n) {
        int num = 0;
        for (auto c : n) num = max(num, c - '0');
        return num;
    }
};