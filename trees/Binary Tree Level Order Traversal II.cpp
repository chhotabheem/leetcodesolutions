struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#include <queue>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> result;
        if (!root)
        {
            return result;
        }
        queue<TreeNode *> que;
        stack<vector<int>> stk;
        que.push(root);
        while (!que.empty())
        {
            int n = que.size();
            vector<int> level;
            while (n--)
            {
                TreeNode *node = que.front();
                level.push_back(node->val);
                que.pop();

                if (node->left)
                {
                    que.push(node->left);
                }
                if (node->right)
                {
                    que.push(node->right);
                }
            }
            stk.push(level);
            level.clear();
        }

        while (!stk.empty())
        {
            result.emplace_back(stk.top());
            stk.pop();
        }
        return result;
    }
};