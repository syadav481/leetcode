struct Node
{
    Node *next;
    int val;
    Node(int val_in, Node *next)
    {
        this->val = val_in;
        this->next = next;
    }
    Node(int val_in)
    {
        this->val = val_in;
        this->next = nullptr;
    }
    Node()
    {
        this->val = 0;
        this->next = nullptr;
    }
};

class MyLinkedList
{
  private:
    Node *head;

  public:
    MyLinkedList()
    {
        head = nullptr;
    }

    int get(int index)
    {
        int idx = 0;
        auto curr = head;
        while (curr)
        {
            if (idx == index)
            {
                return curr->val;
            }
            idx += 1;
            curr = curr->next;
        }
        return -1;
    }

    void addAtHead(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void addAtTail(int val)
    {
        int idx = 0;
        Node *newNode = new Node(val);
        auto curr = head;
        if (!curr)
        {
            head = newNode;
            return;
        }
        while (curr->next)
        {
            curr = curr->next;
        }
        curr->next = newNode;
    }

    void addAtIndex(int index, int val)
    {
        if (index == 0)
        {
            addAtHead(val);
            return;
        }
        Node *newNode = new Node(val);
        int idx = 0;
        auto curr = head;
        while (curr)
        {
            if (idx == index - 1)
            {
                newNode->next = curr->next;
                curr->next = newNode;
            }
            curr = curr->next;
            idx += 1;
        }
    }

    void deleteAtIndex(int index)
    {
        int idx = 0;
        auto curr = head;
        if (index == 0 && curr)
        {
            head = head->next;
            return;
        }
        while (curr)
        {
            if (idx == index - 1 && curr->next)
            {
                curr->next = curr->next->next;
            }
            curr = curr->next;
            idx += 1;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */