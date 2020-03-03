struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        if (!node || !node->next)
        {
            return;
        }
        ListNode *next = node->next;
        node->val = next->val;
        node->next = next->next;
        delete next;
    }
};