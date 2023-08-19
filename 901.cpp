#include <vector>

using namespace std;

class StockSpanner {
private:
  vector<int> vals;
  vector<int> spans;

public:
  StockSpanner() {}

  int next(int price) {
    if (vals.empty() || vals.back() > price) {
      vals.push_back(price);
      spans.push_back(1);
      return 1;
    }
    int span = 1;
    int i = vals.size() - 1;
    while (i > -1 && vals[i] <= price) {
      span += spans[i];
      i -= spans[i];
    }
    vals.push_back(price);
    spans.push_back(span);
    return span;
  }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */