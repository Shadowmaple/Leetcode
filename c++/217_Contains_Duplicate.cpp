# include <iostream>
# include <vector>
# include <map>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, bool> visited;

        for (int n : nums) {
            if (!visited[n]) return true;
            visited[n] = true;
        }
        return false;
    }
};