struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head)
    {
        ListNode* middle_after = findMiddleAfter(head);
        middle_after = reverseList(middle_after);
        ListNode *h1 = head, *h2 = middle_after;
        while (h2)
        {
            if (h2->val!=h1->val) return false;
            h2 = h2->next;
            h1 = h1->next;
        }
        return true;
    }

    ListNode* findMiddleAfter(ListNode* head)
    {
        ListNode *fast = head, *slow = head;
        while (fast)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast) fast = fast->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head)
    {
        ListNode *p = head, *last = nullptr, *next;
        while (p)
        {
            next = p->next;
            p->next = last;
            last = p;
            p = next;
        }
        return last;
    }
};
