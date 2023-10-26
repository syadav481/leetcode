#include <algorithm>
#include <string>
#include <vector>

using std::max;
using std::min;
using std::string;
using std::vector;

class BrowserHistory
{
    vector<string> bh;
    int curr_page;

  public:
    BrowserHistory(string homepage)
    {
        curr_page = 0;
        bh.push_back(homepage);
    }

    void visit(string url)
    {
        // 0 1 2 3 4
        // a b c d e
        // If I'm on page 2 and I visit some other page
        // then I pop: 2 times
        // 2 = len() - curr - 1
        int pop_count = bh.size() - curr_page - 1;
        for (int i = 0; i < pop_count; ++i)
        {
            bh.pop_back();
        }
        bh.push_back(url);
        curr_page = bh.size() - 1;
    }

    string back(int steps)
    {
        curr_page = max(curr_page - steps, 0);
        return bh[curr_page];
    }

    string forward(int steps)
    {
        curr_page = min(curr_page + steps, (int)bh.size() - 1);
        return bh[curr_page];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */