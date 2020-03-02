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
    void calculateRangeSum(TreeNode *root, int L, int R, int &sum)
    {
        if (!root)
        {
            return;
        }
        if (root->val >= L && root->val <= R)
        {
            sum += root->val;
        }
        if (root->val >= L)
        {
            calculateRangeSum(root->left, L, R, sum);
        }
        if (root->val <= R)
        {
            calculateRangeSum(root->right, L, R, sum);
        }
    }
    int rangeSumBST(TreeNode *root, int L, int R)
    {
        int sum = 0;
        calculateRangeSum(root, L, R, sum);
        return sum;
    }
};