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
    bool hasPathSum(TreeNode *root, int &curr_sum, int sum)
    {
        curr_sum += root->val;
        if (!root->left && !root->right)
        {
            if (curr_sum == sum)
            {
                return true;
            }
            curr_sum -= root->val;
            return false;
        }
        bool found = false;
        if (root->left)
        {
            found = hasPathSum(root->left, curr_sum, sum);
            if (found)
            {
                return true;
            }
        }
        if (root->right)
        {
            found = hasPathSum(root->right, curr_sum, sum);
            if (found)
            {
                return true;
            }
        }
        curr_sum -= root->val;
        return false;
    }

    bool hasPathSum(TreeNode *root, int sum)
    {
        if (!root)
        {
            return false;
        }
        int curr_sum = 0;
        return hasPathSum(root, curr_sum, sum);
    }
};