#include <vector>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    bool areTreesSame(TreeNode *s, TreeNode *t)
    {
        if (!s && !t)
        {
            return true;
        }
        if (!s || !t)
        {
            return false;
        }
        if (s->val != t->val)
        {
            return false;
        }
        return (areTreesSame(s->left, t->left) && areTreesSame(s->right, t->right));
    }

    void get_matching_roots(TreeNode *s, TreeNode *t, std::vector<TreeNode *> &matching_roots)
    {
        if (!s || !t)
        {
            return;
        }
        if (s->val == t->val)
        {
            matching_roots.emplace_back(s);
        }
        get_matching_roots(s->left, t, matching_roots);
        get_matching_roots(s->right, t, matching_roots);
    }
    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        if (!s && !t)
        {
            return true;
        }
        if (!s || !t)
        {
            return false;
        }
        std::vector<TreeNode *> matching_roots;
        get_matching_roots(s, t, matching_roots);
        if (matching_roots.empty())
        {
            return false;
        }
        for (auto node : matching_roots)
        {
            if (areTreesSame(node, t))
            {
                return true;
            }
        }
        return false;
    }
};