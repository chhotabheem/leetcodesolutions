struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (!l1 && !l2)
        {
            return nullptr;
        }
        if (!l1)
        {
            return l2;
        }
        if (!l2)
        {
            return l1;
        }
        ListNode temp(0);
        ListNode *curr = &temp;
        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                curr->next = l1;
                l1 = l1->next;
            }
            else
            {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        if (!l1)
        {
            curr->next = l2;
        }
        if (!l2)
        {
            curr->next = l1;
        }
        return temp.next;
    }
};