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
    bool isUnivalTree(TreeNode *root, const int &val)
    {
        if (!root)
        {
            return true;
        }
        if (root->val != val)
        {
            return false;
        }
        return (isUnivalTree(root->left, val) && isUnivalTree(root->right, val));
    }
    bool isUnivalTree(TreeNode *root)
    {
        if (!root)
        {
            return false;
        }
        int val = root->val;
        return isUnivalTree(root, val);
    }
};