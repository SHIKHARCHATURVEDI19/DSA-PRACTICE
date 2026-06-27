LeetCode 104 – Maximum Depth of Binary Tree

Problem:
Given the root of a binary tree, return its maximum depth.

Approach:
Use Depth First Search (DFS). Recursively calculate the depth of the left and right subtrees, then return 1 + max(leftDepth, rightDepth).

C++ Solution:

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

Time Complexity: O(n)
Space Complexity: O(h) where h is the height of the tree.