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
#include<iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    bool LeftEqualRight(TreeNode* Left, TreeNode* Right) {
        if (Left == nullptr && Right != nullptr) { return false; }
        if (Left != nullptr && Right == nullptr) { return false; }
        if (Left == nullptr && Right == nullptr) { return true; }
        if (Left!= nullptr && Right != nullptr&&Left->val!=Right->val) { return false; }
        bool out = LeftEqualRight(Left->left, Right->right);
        bool in = LeftEqualRight(Left->right, Right->left);
        return in && out;
    }
    bool isSymmetric(TreeNode* root) {
        if (nullptr == root) { return true; }
        return LeftEqualRight(root->left, root->right);
    }
};