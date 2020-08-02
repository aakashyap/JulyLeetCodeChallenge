/*

Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7

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
    unordered_map<int,int> cache;
    TreeNode* util(const vector<int>& inorder,const vector<int>& postorder,int l,int r,int &pIndex) {
        if (l > r) return nullptr;
        TreeNode *t = new TreeNode();
        t->left=t->right=nullptr;
        int val = postorder[pIndex];
        int pos = cache[val];
        t->val = val;
        --pIndex;
        if (l == r) {
            return t;
        }
        t->right = util(inorder,postorder,pos+1,r,pIndex);
        t->left = util(inorder,postorder,l,pos-1,pIndex);
        return t;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size()-1;
        for(int i=0;i<=size;++i) {
            cache[inorder[i]] = i;
        }
        return util(inorder,postorder,0,size,size);
    }
};

