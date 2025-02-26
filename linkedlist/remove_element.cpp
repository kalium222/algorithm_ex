struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val)
    {
        return solve1(head, val);
    }

    ListNode* solve1(ListNode* head, int val)
    {
        auto fast = head, slow = head;
        auto new_head = slow;
        while (fast)
        {
            if (fast->val==val)
            {
                if (fast==slow)
                {
                    fast = fast->next;
                    delete slow;
                    new_head = slow = fast;
                }
                else
                {
                    slow->next = fast->next;
                    delete fast;
                    fast = slow->next;
                }
            }
            else
            {
                if (fast!=slow)
                    slow = slow->next;
                fast = fast->next;
            }
        }
        return new_head;
    }

    ListNode* solve2(ListNode* head, int val)
    {
        auto virt_head = ListNode(0, head);
        auto p = &virt_head;
        while(p->next)
        {
            if (p->next->val==val)
            {
                auto temp = p->next;
                p->next = temp->next;
                delete temp;
            }
            else
            {
                p = p->next;
            }
        }
        return virt_head.next;
    }
};
