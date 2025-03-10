struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode* swapPairs(ListNode* head)
    {
        auto virt_head = ListNode(0, head);
        ListNode *p = head, *last = &virt_head;
        if (!p) return head;
        auto next = p->next;
        while (p && next)
        {
            last->next = next;
            p->next = next->next;
            next->next = p;

            last = p;
            p = p->next;
            if (p) next = p->next;
        }
        return virt_head.next;
    }
};
