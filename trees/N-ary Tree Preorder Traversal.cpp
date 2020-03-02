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
    void preorder(Node *root, std::vector<int> &preorder_elems)
    {
        if (!root)
        {
            return;
        }
        preorder_elems.emplace_back(root->val);
        for (const auto &node : root->children)
        {
            preorder(node, preorder_elems);
        }
    }
    std::vector<int> preorder(Node *root)
    {
        std::vector<int> preorder_elems;
        preorder(root, preorder_elems);
        return preorder_elems;
    }
};