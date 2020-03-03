struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode *curr = head;
        ListNode *next = head->next;
        while (next)
        {
            if (curr->val == next->val)
            {
                ListNode *temp = next->next;
                delete next;
                next = temp;
            }
            else
            {
                curr->next = next;
                curr = curr->next;
                next = next->next;
            }
        }
        curr->next = nullptr;
        return head;
    }
};