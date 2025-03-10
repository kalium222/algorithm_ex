#include <cstddef>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode *p = head, *last = nullptr, *temp;
        while (p)
        {
            temp = p->next;
            p->next = last;
            last = p;
            p = temp;
        }
        return last;
    }
};

int main(void)
{
    return 0;
}
