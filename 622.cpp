#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class MyCircularQueue {
public:

    vector<int> q;
    int f_ptr = 0; 
    int b_ptr = 0;
    uint64_t count = 0;

    MyCircularQueue(int k) {
        q.resize(k, -1); 
    }
    
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        q[b_ptr] = value;
        b_ptr = (b_ptr + 1) % q.size(); 
        count += 1; 
        return true; 
    }
    
    bool deQueue() {
        if (isEmpty()){
            return false; 
        }
        f_ptr = (f_ptr + 1) % q.size();
        count -= 1; 
        return true;
    }
    
    int Front() {
        if (isEmpty()) {
            return -1; 
        }
        return q[f_ptr];  
    }
    
    int Rear() {
        if (isEmpty()) {
            return -1; 
        }
        int idx = (b_ptr + q.size() - 1) % q.size(); 
        return q[idx];
    }
    
    bool isEmpty() {
        return count == 0; 
    }
    
    bool isFull() {
        return count == q.size(); 
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

int main() {}