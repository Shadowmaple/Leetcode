# include <iostream>
# include <queue>
# include <vector>
using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> hugeQueue;
    priority_queue<int, vector<int>, greater<int>> smallQueue;
    MedianFinder() {}

    void addNum(int num) {
        if (hugeQueue.size() == smallQueue.size()) {
            smallQueue.push(num);
            hugeQueue.push(smallQueue.top());
            smallQueue.pop();
        } else {
            hugeQueue.push(num);
            smallQueue.push(hugeQueue.top());
            hugeQueue.pop();
        }
    }

    double findMedian() {
        if (hugeQueue.size() == smallQueue.size())
            return double(hugeQueue.top() + smallQueue.top()) / 2;
        return hugeQueue.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */