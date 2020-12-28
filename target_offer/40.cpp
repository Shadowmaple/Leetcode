# include <iostream>
# include <vector>
# include <queue>
using namespace std;

// 小顶堆，优先队列
// 时间击败34%
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> v;
        if (!arr.size() || !k) return v;

        priority_queue<int, vector<int>, greater<int>> q;

        for (int n : arr) {
            q.push(n);
        }

        while (k-- && !q.empty()) {
            v.push_back(q.top());
            q.pop();
        }

        return v;
    }
};

// 快排思想
// 写快排：击败76%
// 快排细想（快速选择）：击败97.6%
class Solution2 {
public:
    int k;
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> v;
        if (!arr.size() || !k) return v;

        this->k = k;
        part(arr, 0, arr.size()-1);

        for (int i=0; i < k; i++)
            v.push_back(arr[i]);

        return v;
    }

    void part(vector<int>& arr, int begin, int end) {
        if (begin >= end) return ;
        int key = arr[begin];
        int l = begin, r = end;
        while (l < r) {
            while (l < r && arr[r] >= key) r--;
            if (l >= r) break;
            arr[l] = arr[r];
            while (l < r && arr[l] <= key) l++;
            if (l >= r) break;
            arr[r] = arr[l];
        }
        arr[l] = key;
        if (l == k-1) return ;

        if (l > k-1) return part(arr, begin, l-1);
        return part(arr, l+1, end);
    }
};