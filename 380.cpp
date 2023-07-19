#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>
using namespace std;

class RandomizedSet {
private:
  vector<int> v;
  map<int, int> m;
  random_device rd;
  mt19937 generator;

public:
  RandomizedSet() : generator(rd()) {}

  bool insert(int val) {
    if (m.find(val) == m.end()) {
      v.push_back(val);
      m[val] = v.size() - 1;
      return true;
    }
    return false;
  }

  bool remove(int val) {
    if (m.find(val) == m.end()) {
      return false;
    }
    if (m[val] == v.size() - 1) {
      v.pop_back();
    } else {
      int idxOfOriginal = m[val];
      int idxOfLast = v.size() - 1;
      int last = v[v.size() - 1];
      v[idxOfOriginal] = v[idxOfLast];
      m[last] = idxOfOriginal;
      v.pop_back();
    }
    m.erase(val);
    return true;
  }

  int getRandom() {
    uniform_int_distribution<int> distribution(0, v.size() - 1);
    return v[distribution(generator)];
  }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

// test 1:

int main() {
  RandomizedSet rs;
  assert(rs.remove(0) == false);
  assert(rs.remove(0) == false);
  assert(rs.insert(0) == true);
  assert(rs.remove(0) == true);
  assert(rs.insert(0) == true);
}
