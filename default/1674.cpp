# include <iostream>
# include <vector>
# include <map>
# include <set>
# include <algorithm>
using namespace std;

struct Node {
    long value;
    int count;
    Node(long value): value(value), count(0) {};
    Node(long value, int count): value(value), count(count) {};
};

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        map<long, int> mp;
        set<long> sums;
        for (int i=0, j=n-1; i < j; i++, j--) {
            mp[nums[i]+nums[j]]++;
            sums.insert(nums[i]+nums[j]);
        }
        if (sums.size() == 1) return 0;
        vector<Node*> v;
        for (auto sum : sums) {
            v.push_back(new Node(sum, mp[sum]));
        }
        sort(v.begin(), v.end(), [](Node* n1, Node* n2){return n1->count > n2->count;});
        int idx = 0;
        int res = n/2;
        while (idx < v.size()) {
            long target = v[idx]->value;

            int count = 0;
            bool flag = true;
            for (int i=0, j=n-1; i < j; i++, j--) {
                if (nums[i]+nums[j] == target) continue;
                int left = target-nums[i], right = target-nums[j];
                // 只需变一边
                if (left > 0 && left <= limit || right > 0 && right <= limit)
                    count++;
                // 需变两边
                else {
                    if (target / 2 > limit) {
                        flag = false;
                        break;
                    }
                    count += 2;
                }
            }
            if (flag) return count;
            idx++;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = vector<int>{1,2,2,1};
    cout << s.minMoves(nums, 2) << endl;
    return 0;
}