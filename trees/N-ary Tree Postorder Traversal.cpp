#include <vector>
class Node
{
public:
    int val;
    std::vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, std::vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    void postorder(Node *root, std::vector<int> &postorder_elems)
    {
        if (!root)
        {
            return;
        }
        for (const auto &node : root->children)
        {
            postorder(node, postorder_elems);
        }
        postorder_elems.emplace_back(root->val);
    }
    std::vector<int> postorder(Node *root)
    {
        std::vector<int> postorder_elems;
        postorder(root, postorder_elems);
        return postorder_elems;
    }
};