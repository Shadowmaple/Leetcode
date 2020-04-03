# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for (auto it=nums.begin(); it < nums.end();) {
            if (it > nums.begin()+1 && *(it) == *(it-1) && *(it) == *(it-2))
                nums.erase(it);
            else it++;
        }
        return nums.size();
    }
};