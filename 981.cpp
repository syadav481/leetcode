#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class TimeMap {
  struct Val {
    string value;
    int timestamp;
    Val(string value_in, int timestamp_in)
        : value(value_in), timestamp(timestamp_in) {}
  };

public:
  TimeMap() {}

  unordered_map<string, vector<Val>> m;
  void set(string key, string value, int timestamp) {
    m[key].emplace_back(value, timestamp);
  }

  string get(string key, int timestamp) {
    auto it = m.find(key);
    if (it == m.end()) {
      return "";
    }
    auto nums = it->second;
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int m = (r - l) / 2 + l;
      if (nums[m].timestamp < timestamp) {
        l = m + 1;
      } else if (nums[m].timestamp > timestamp) {
        r = m - 1;
      } else {
        return nums[m].value;
      }
    }
    if (r >= 0) {
      return nums[r].value;
    }
    return "";
  }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
void test1() {
  TimeMap t;
  t.set("love", "high", 10);
  t.set("love", "low", 20);
  t.get("love", 5);
  t.get("love", 10);
  t.get("love", 15);
  t.get("love", 20);
  t.get("love", 25);
}
void test2() {
  TimeMap t;
  t.set("love", "high", 10);
  t.set("love", "low", 20);
  cout << t.get("love", 5) << endl;
  cout << t.get("love", 10) << endl;
  cout << t.get("love", 15) << endl;
  cout << t.get("love", 20) << endl;
  cout << t.get("love", 25) << endl;
}
int main() {
  test1();
  test2();
}