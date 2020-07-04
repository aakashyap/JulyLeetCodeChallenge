/*

Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]

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
    vector<vector<int>> result;
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == nullptr) return result;
        vector<int> temp;
        queue<pair<TreeNode*,int>> cache;
        cache.push(make_pair(root,0));
        int prev = 0;
        while(!cache.empty()) {
            pair<TreeNode*,int> p = cache.front();
            cache.pop();
            if (prev != p.second) {
                prev = p.second;
                result.push_back(temp);
                temp.clear();
            }
            temp.push_back(p.first->val);
            if (p.first->left) cache.push(make_pair(p.first->left,p.second+1));
            if (p.first->right) cache.push(make_pair(p.first->right,p.second+1));
        }
        result.push_back(temp);
        reverse(result.begin(),result.end());
        return result;
    }
};
