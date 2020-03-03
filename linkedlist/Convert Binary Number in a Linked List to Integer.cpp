struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

#include <stack>
class Solution
{
public:
    int getDecimalValue(ListNode *head)
    {
        std::stack<ListNode *> stk;
        int dec_val = 0;
        while (head)
        {
            stk.push(head);
            head = head->next;
        }
        int i = 0;
        while (!stk.empty())
        {
            dec_val += (stk.top()->val * pow(2, i));
            ++i;
            stk.pop();
        }
        return dec_val;
    }
};