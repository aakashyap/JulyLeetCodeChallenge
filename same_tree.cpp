/*

Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

Example 1:

Input:     1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

Output: true
Example 2:

Input:     1         1
          /           \
         2             2

        [1,2],     [1,null,2]

Output: false
Example 3:

Input:     1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

Output: false

*/

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
    void preorderWithNull(TreeNode* root,vector<int> &vec) {
        if (root) {
            vec.push_back(root->val);
            preorderWithNull(root->left,vec);
            preorderWithNull(root->right,vec);
        } else {
            vec.push_back(INT_MAX);
        }
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        /*vector<int> tree1;
        vector<int> tree2;
        preorderWithNull(p,tree1);
        preorderWithNull(q,tree2);
        if (tree1 == tree2) return true;
        return false;*/
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};