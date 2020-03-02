struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#include <queue>
class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        std::queue<TreeNode *> que;
        que.push(root);
        int level = 0;
        while (!que.empty())
        {
            ++level;
            int n = que.size();
            while (n--)
            {
                TreeNode *node = que.front();
                que.pop();
                if (!node->left && !node->right)
                {
                    return level;
                }
                if (node->left)
                {
                    que.push(node->left);
                }
                if (node->right)
                {
                    que.push(node->right);
                }
            }
        }
        return level;
    }
};