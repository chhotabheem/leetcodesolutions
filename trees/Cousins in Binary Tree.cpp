struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#include <map>
struct NodeDetails
{
    int height;
    int width;
    TreeNode *parent;
};
class Solution
{
public:
    void fillCousinsMap(TreeNode *root, int x, int y, int height, int width, TreeNode *parent,
                        std::map<int, NodeDetails> &cousins_map)
    {
        if (!root)
        {
            return;
        }
        if (cousins_map.size() == 2)
        {
            return;
        }
        if (height >= 2 && (root->val == x || root->val == y))
        {
            NodeDetails node_detail;
            node_detail.height = height;
            node_detail.width = width;
            node_detail.parent = parent;
            cousins_map[root->val] = node_detail;
        }
        fillCousinsMap(root->left, x, y, height + 1, width - 1, root, cousins_map);
        fillCousinsMap(root->right, x, y, height + 1, width + 1, root, cousins_map);
    }
    bool isCousins(TreeNode *root, int x, int y)
    {
        std::map<int, NodeDetails> cousins_map;
        fillCousinsMap(root, x, y, 0, 0, nullptr, cousins_map);
        if (cousins_map.size() != 2)
        {
            return false;
        }
        auto iter1 = cousins_map.find(x);
        auto iter2 = cousins_map.find(y);
        if (iter1 == cousins_map.end() || iter2 == cousins_map.end())
        {
            return false;
        }
        if (iter1->second.height != iter2->second.height)
        {
            return false;
        }
        if (iter1->second.parent == iter2->second.parent)
        {
            return false;
        }
        return true;
    }
};