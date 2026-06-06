// C++
class Solution {
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }

    int dfs(TreeNode* node, int maxSoFar) {
        if (!node) return 0;

        int good = (node->val >= maxSoFar) ? 1 : 0;
        int newMax = max(maxSoFar, node->val);

        return good + dfs(node->left, newMax) + dfs(node->right, newMax);
    }
};