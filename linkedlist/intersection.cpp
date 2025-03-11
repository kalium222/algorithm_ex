#include <cstdlib>
#include <iostream>

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int lenA = 0, lenB = 0;
        int delta_len;
        ListNode *a = headA, *b = headB;
        ListNode *long_head, *short_head;
        ListNode *long_p, *short_p;
        while (a)
        {
            a = a->next;
            lenA++;
        }
        while (b) 
        {
            b = b->next;
            lenB++;
        }
        delta_len = std::abs(lenB-lenA);
        if (lenA>=lenB)
        {
            long_head = headA;
            short_head = headB;
        }
        else
        {
            long_head = headB;
            short_head = headA;
        }
        long_p = long_head;
        short_p = short_head;
        for (int i=0; i<delta_len; i++) 
            long_p = long_p->next;
        while (long_p && short_p)
        {
            if (long_p==short_p)
                return long_p;
            long_p = long_p->next;
            short_p = short_p->next;
        }
        return nullptr;
    }
};

int main(void)
{
    ListNode a0, a1, a2, a3, a4;
    ListNode b0, b1, b2, b3, b4, b5;
    b0 = a0 = ListNode(5);
    b1 = a1 = ListNode(4, &a0);
    b2 = a2 = ListNode(8, &a1);
    a3 = ListNode(1, &a2);
    b3 = ListNode(1, &b2);
    a4 = ListNode(4, &a3);
    b4 = ListNode(0, &b3);
    b5 = ListNode(5, &b4);
    auto a = &a4, b = &b5;
    while (a)
    {
        std::cout << a->val << ", " << a << "; ";
        a = a->next;
    }
    std::cout << std::endl;
    while (b)
    {
        std::cout << b->val << ", " << b << "; ";
        b = b->next;
    }
    std::cout << std::endl;
    Solution s = Solution();
    std::cout << s.getIntersectionNode(&a4, &b5) << std::endl;
    return 0;
}

