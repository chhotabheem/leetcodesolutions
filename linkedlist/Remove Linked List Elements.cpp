struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        if (!head)
        {
            return nullptr;
        }
        ListNode temp(0);
        ListNode *result = &temp;
        while (head)
        {
            if (head->val == val)
            {
                ListNode *next = head->next;
                delete head;
                head = next;
            }
            else
            {
                result->next = head;
                head = head->next;
                result = result->next;
            }
        }
        result->next = nullptr;
        return temp.next;
    }
};