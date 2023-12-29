#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class LRUCache {
public:
    inline static int M[10001];
    inline static int16_t L[10002][2];
    int cap, size = 0;
    const int NONE = 10001;
    int head = NONE, tail = NONE;
    
    LRUCache(int capacity) : cap(capacity) {
        memset(M, 0xff, sizeof M);
    }
    
    inline void erase(int key) {
        const int pre = L[key][0];
        const int nxt = L[key][1];
        L[pre][1] = nxt;
        L[nxt][0] = pre;
        if (head == key) head = nxt;
        if (tail == key) tail = pre;
    }
    
    inline void push_front(int key) {
        L[key][0] = NONE;
        L[key][1] = head;
        L[head][0] = key;
        head = key;
        if (tail == NONE)
            tail = key;
    }
    
    inline int pop_back() {
        int ret = tail;
        tail = L[tail][0];
        L[tail][1] = NONE;
        if (tail == NONE)
            head = NONE;
        return ret;
    }
    
    int get(int key) {
        if (M[key] == -1) return -1;
        erase(key);
        push_front(key);
        return M[key];
    }
    
    void put(int key, int value) {
        if (M[key] != -1) {
            erase(key);
        } else {
            if (size == cap) {
                int poped = pop_back();
                M[poped] = -1;
                size -= 1;
            }
            size += 1;
        }
        push_front(key);
        M[key] = value;
    }
};

#include <unistd.h>
static char buf[20000000];

int mgetchar() {
    static int pos = 0;
    pos++;
    return buf[pos-1] == '\0' ? EOF : buf[pos-1];
}

int getmethod() {
    int c = mgetchar();
    while (mgetchar() != '"');
    return c;
}

int getinput(vector<int>& ret) {
    int c;
    while((c = mgetchar()) != EOF && c != '[');
    while ((c = mgetchar()) != EOF) {
        if (c == '"')
            ret.push_back(getmethod());
        else if (c == ']')
            return 1;
    }
    return 0;
}

int getone() {
    while(mgetchar() != '[');
    int ans = 0, c;
    while((c = mgetchar()) != ']') {
        if (isdigit(c))
            ans = ans * 10 + c - '0';
    }
    return ans;
}

pair<int,int> gettwo() {
    while(mgetchar() != '[');
    pair<int,int> ans;
    int c;
    while((c = mgetchar()) != ',') {
        if (isdigit(c))
            ans.first = ans.first * 10 + c - '0';
    }
    while((c = mgetchar()) != ']') {
        if (isdigit(c))
            ans.second = ans.second * 10 + c - '0';
    }
    return ans;
}

void getpara(FILE *fp, vector<int>& funcs) {
    while(mgetchar() != '[');
    LRUCache lru(getone());
    for (int i = 0; i < funcs.size(); i++) {
        auto f = funcs[i];
        if (f == 'L') {
        } else if (f == 'g') {
            int v = lru.get(getone());
        } else {
            pair<int,int> v = gettwo();
            lru.put(v.first, v.second);
        }
    }
}