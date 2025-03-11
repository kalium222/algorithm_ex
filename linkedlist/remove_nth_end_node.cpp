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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode virt_head = ListNode(0, head);
        ListNode *fast = head, *slow = &virt_head;
        while (fast && n>1)
        {
            fast = fast->next;
            n--;
        }
        while (fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
        auto temp = slow->next;
        slow->next = temp->next;
        return virt_head.next;
    }
};
