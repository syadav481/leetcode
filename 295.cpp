#include <queue>
#include <vector>

class MedianFinder {
public:
  std::priority_queue<int> maxheap;
  std::priority_queue<int, std::vector<int>, std::greater<int>> minheap;
  MedianFinder() {}

  void addNum(int num) {
    // maxheap stores the n/2 smallest elements
    // minheap stores the n/2 largest elements

    if (maxheap.size() == 0 || num > maxheap.top()) {
      minheap.push(num);
    } else {
      maxheap.push(num);
    }
    if (maxheap.size() < minheap.size()) {
      int curr = minheap.top();
      minheap.pop();
      maxheap.push(curr);
    } else if (minheap.size() < maxheap.size()) {
      int curr = maxheap.top();
      maxheap.pop();
      minheap.push(curr);
    }
  }

  double findMedian() {
    // maxheap stores the n/2 smallest elements
    // minheap stores the n/2 largest elements
    if (maxheap.size() == minheap.size()) {
      double sum = minheap.top() + maxheap.top();
      return sum / 2;
    } else if (maxheap.size() > minheap.size()) {
      return maxheap.top();
    }
    return minheap.top();
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
