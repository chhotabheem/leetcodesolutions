struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

#include <tuple>
class Solution
{
public:
    ListNode *reverseList(ListNode *node)
    {
        if (!node)
        {
            return nullptr;
        }
        ListNode *prev = nullptr;
        while (node)
        {
            ListNode *next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
        return prev;
    }

    std::tuple<ListNode *, ListNode *, ListNode *> split(ListNode *head)
    {
        std::tuple<ListNode *, ListNode *, ListNode *> result(nullptr, nullptr, nullptr);
        if (!head)
        {
            return result;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        std::get<0>(result) = head;
        std::get<1>(result) = slow;
        std::get<2>(result) = slow->next;
        slow->next = nullptr;
        return result;
    }

    bool isPalindrome(ListNode *head)
    {
        if (!head || !head->next)
        {
            return true;
        }
        ListNode *head1 = nullptr, *tail1 = nullptr, *head2 = nullptr;
        std::tie(head1, tail1, head2) = split(head);
        ListNode *reversehead2 = reverseList(head2);
        head2 = reversehead2;
        while (head1 && head2)
        {
            if (head1->val != head2->val)
            {
                tail1->next = reverseList(reversehead2);
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        tail1->next = reverseList(reversehead2);
        return true;
    }
};