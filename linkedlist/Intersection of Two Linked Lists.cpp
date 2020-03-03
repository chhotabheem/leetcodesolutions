struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

#include<cmath>

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (!headA || !headB)
        {
            return nullptr;
        }
        ListNode *curr = headA;
        int count1 = 0;
        while (curr)
        {
            ++count1;
            curr = curr->next;
        }
        curr = headB;
        int count2 = 0;
        while (curr)
        {
            ++count2;
            curr = curr->next;
        }
        ListNode *curr1 = headA, *curr2 = headB;
        int diff = abs(count1 - count2);
        if (diff)
        {
            if (count1 > count2)
            {
                curr1 = headA;
                curr2 = headB;
            }
            else
            {
                curr1 = headB;
                curr2 = headA;
            }
            while (diff--)
            {
                curr1 = curr1->next;
            }
        }
        while (curr1 && curr2)
        {
            if (curr1 == curr2)
            {
                return curr1;
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        return nullptr;
    }
};