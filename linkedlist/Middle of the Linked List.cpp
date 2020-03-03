struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast->next)
        {
            return slow->next;
        }
        return slow;
    }
};