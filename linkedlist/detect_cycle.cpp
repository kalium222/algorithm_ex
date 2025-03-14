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
    ListNode *detectCycle(ListNode *head)
    {
        return sol0(head);
    }

    ListNode *sol0(ListNode *head)
    {
        ListNode *fast, *slow, *target;
        fast = slow = target = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast==slow)
            {
                while (target!=fast)
                {
                    target = target->next;
                    fast = fast->next;
                }
                return target;
            }
        }
        return nullptr;
    }

    ListNode *sol1(ListNode *head)
    {
        ListNode *fast, *slow;
        bool start = true;
        fast = slow = head;
        while (fast&&slow)
        {
            if (fast==slow&&!start)
                return getIntersection(head, fast);
            if (fast->next) fast = fast->next->next;
            else return nullptr;
            slow = slow->next;
            start = false;
        }
        return nullptr;
    }

    ListNode *getIntersection(ListNode *head, ListNode *meet)
    {
        ListNode *p1, *p2, *target;
        p1 = meet, p2 = head;
        while (p1!=p2)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};

int main(void)
{
    ListNode a0, a1, a2, a3;
    a0 = ListNode(3);
    a1 = ListNode(2);
    a2 = ListNode(0);
    a3 = ListNode(-4);
    a0.next = &a1;
    a1.next = &a2;
    a2.next = &a3;
    a3.next = &a1;
    auto s = Solution();
    s.detectCycle(&a0);
    return 0;
}
