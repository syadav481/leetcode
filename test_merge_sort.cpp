#include "148.h"
// DON'T NORMALLY #INCLUDE A CPP FILE
#include <assert.h>

using std::cout;
using std::endl;

void test3()
{
    cout << "\ntest3\n";
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(1);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(5);
    l1->next->next->next->next = new ListNode(2);
    l1->next->next->next->next->next = new ListNode(10);
    Solution s;
    cout << "original:\t" << l1;
    l1 = s.mergesort(l1);
    cout << "sorted:\t\t" << l1;
}
void test2()
{
    cout << "\ntest2\n";
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(1);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(5);
    l1->next->next->next->next = new ListNode(2);
    l1->next->next->next->next->next = new ListNode(10);
    cout << "original:\t" << l1;
    Solution s;
    auto p = s.split(l1);
    cout << "u:\t\t" << p.u;
    cout << "v:\t\t" << p.v;
}
void test1()
{
    cout << "\ntest1\n";
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(1);
    l1->next->next = new ListNode(3);
    ListNode *l2 = new ListNode(2);
    Solution s;
    auto head = s.merge(l1, l2);
    cout << head;
}
int main()
{
    test1();
    test2();
    test3();
}
