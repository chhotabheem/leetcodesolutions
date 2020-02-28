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
    void maxDepth(TreeNode *root, int &max_depth, int current_depth)
    {
        if (!root)
        {
            return;
        }
        ++current_depth;
        if (current_depth > max_depth)
        {
            max_depth = current_depth;
        }
        maxDepth(root->left, max_depth, current_depth);
        maxDepth(root->right, max_depth, current_depth);
    }

    int maxDepth(TreeNode *root)
    {
        int max_depth = 0;
        int current_depth = 0;
        maxDepth(root, max_depth, current_depth);
        return max_depth;
    }
};