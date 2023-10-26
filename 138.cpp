#include <unordered_map>

using namespace std;
class Node
{
  public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
  public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
        {
            return nullptr;
        }
        unordered_map<Node *, Node *> m;
        auto curr = head;
        while (curr)
        {
            m[curr] = new Node(curr->val);
            curr = curr->next;
        }
        curr = head;
        while (curr)
        {
            if (curr->next)
            {
                m[curr]->next = m[curr->next];
            }
            if (curr->random)
            {
                m[curr]->random = m[curr->random];
            }
            curr = curr->next;
        }
        return m[head];
    }
};