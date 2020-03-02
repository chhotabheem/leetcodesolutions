struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    void binaryTreePaths(TreeNode *root, string &path, vector<string> &result)
    {
        if (!root)
        {
            return;
        }
        string num_str = to_string(root->val);
        path.append(num_str);
        if (!root->left && !root->right)
        {
            result.emplace_back(path);
            int i = 1;
            while (i <= num_str.size())
            {
                path.pop_back();
                ++i;
            }
            return;
        }
        path += "->";
        binaryTreePaths(root->left, path, result);
        binaryTreePaths(root->right, path, result);
        int i = 1;
        while (i <= num_str.size())
        {
            path.pop_back();
            ++i;
        }
        path.pop_back();
        path.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> result;
        string path;
        binaryTreePaths(root, path, result);
        return result;
    }
};