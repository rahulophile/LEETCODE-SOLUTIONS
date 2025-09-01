/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *buildTree(int startIndex, int endIndex, vector<int> &nums, int &n) {
        if (startIndex > endIndex) {  // base case
            return nullptr;
        }

        int midIndex = (startIndex + endIndex) / 2;
        TreeNode *root = new TreeNode(nums[midIndex]);

        root->left = buildTree(startIndex, midIndex - 1, nums, n);
        root->right = buildTree(midIndex + 1, endIndex, nums, n);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return buildTree(0, n - 1, nums, n);
    }
};