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
    void sumOfLeftLeaves(TreeNode *root, int &sum)
    {
        if (!root)
        {
            return;
        }
        if (root->left)
        {
            if (!root->left->left && !root->left->right)
            {
                sum += root->left->val;
            }
        }
        sumOfLeftLeaves(root->left, sum);
        sumOfLeftLeaves(root->right, sum);
    }

    int sumOfLeftLeaves(TreeNode *root)
    {
        int sum = 0;
        sumOfLeftLeaves(root, sum);
        return sum;
    }
};