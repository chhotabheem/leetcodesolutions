struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (!head)
        {
            return false;
        }
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast && fast->next && fast->next->next)
        {
            if (fast == slow)
            {
                return true;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        return false;
    }
};