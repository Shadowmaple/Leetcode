# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> list;
        vector<int> v;
        int n = 1;

        while (n <= groupSizes.size()) {
            for (int i = 0; i < groupSizes.size(); i++) {
                if (groupSizes.at(i) != n) continue;

                v.push_back(i);
                if (v.size() >= n) {
                    list.push_back(v);
                    v.clear();
                }
            }
            n++;
        }
        return list;
    }
};

int main() {
    return 0;
}