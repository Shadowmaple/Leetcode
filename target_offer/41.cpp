# include <iostream>
# include <queue>
using namespace std;

class MedianFinder {
public:
    // 大根堆，维护数组前半段，最大的是中位数
    priority_queue<int, vector<int>, less<int>> bigHeap;
    // 小根堆，维护数组的后半段，最小的是中位数
    priority_queue<int, vector<int>, greater<int>> smallHeap;
    MedianFinder() {}

    void addNum(int num) {
        if (!bigHeap.empty() && num < bigHeap.top())
            bigHeap.push(num);
        else smallHeap.push(num);

        int bigSize = bigHeap.empty()? 0:bigHeap.size();
        int smallSize = smallHeap.empty()? 0:smallHeap.size();

        // 如果小根堆（后半段）比大根堆多一个以上，那么先将元素放到大根堆上
        if (bigSize > smallSize) {
            smallHeap.push(bigHeap.top());
            bigHeap.pop();
        } else if (smallSize-1 > bigSize) {
            bigHeap.push(smallHeap.top());
            smallHeap.pop();
        }
    }

    double findMedian() {
        if (smallHeap.size() > bigHeap.size())
            return smallHeap.top();

        return double(smallHeap.top() + bigHeap.top()) / 2;
    }
};

// 参考题解的，逻辑更严密和优雅，但效率却比上面的低？
class MedianFinder {
public:
    // 大根堆，维护数组前半段，最大的是中位数
    priority_queue<int, vector<int>, less<int>> bigHeap;
    // 小根堆，维护数组的后半段，最小的是中位数
    priority_queue<int, vector<int>, greater<int>> smallHeap;
    MedianFinder() {}

    void addNum(int num) {
        // 数组长度是偶数，则插入至小根堆，否则至大根堆
        if (bigHeap.size() == smallHeap.size()) {
            bigHeap.push(num);
            smallHeap.push(bigHeap.top());
            bigHeap.pop();
        } else {
            smallHeap.push(num);
            bigHeap.push(smallHeap.top());
            smallHeap.pop();
        }
    }

    double findMedian() {
        if (smallHeap.size() > bigHeap.size())
            return smallHeap.top();

        return double(smallHeap.top() + bigHeap.top()) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */