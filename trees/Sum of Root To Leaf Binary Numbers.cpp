struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#include <vector>
using namespace std;
class Solution
{
public:
    int getDecimalNum(const vector<int> &bit_vec)
    {
        int num = 0;
        int j = 0;
        for (int i = bit_vec.size() - 1; i >= 0; --i)
        {
            num += (bit_vec[i] * pow(2, j));
            ++j;
        }
        return num;
    }
    void sumRootToLeaf(TreeNode *root, int &sum, vector<int> &bit_vec)
    {
        if (!root)
        {
            return;
        }
        bit_vec.emplace_back(root->val);
        if (!root->left && !root->right)
        {
            sum += getDecimalNum(bit_vec);
            bit_vec.pop_back();
            return;
        }
        sumRootToLeaf(root->left, sum, bit_vec);
        sumRootToLeaf(root->right, sum, bit_vec);
        bit_vec.pop_back();
    }

    int sumRootToLeaf(TreeNode *root)
    {
        int sum = 0;
        vector<int> bit_vec;
        sumRootToLeaf(root, sum, bit_vec);
        return sum;
    }
};