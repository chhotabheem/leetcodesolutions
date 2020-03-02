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
    int findTiltValues(TreeNode *root, std::vector<int> &tilt_values)
    {
        if (!root)
        {
            return 0;
        }
        int left_sum = findTiltValues(root->left, tilt_values);
        int right_sum = findTiltValues(root->right, tilt_values);
        int tilt = abs(left_sum - right_sum);
        tilt_values.emplace_back(tilt);
        return (left_sum + root->val + right_sum);
    }
    int findTilt(TreeNode *root)
    {
        std::vector<int> tilt_values;
        findTiltValues(root, tilt_values);
        int sum = 0;
        for (const auto &tilt : tilt_values)
        {
            sum += tilt;
        }
        return sum;
    }
};