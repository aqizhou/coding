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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return dfs(root, subRoot);
    }
    bool dfs(TreeNode* root, TreeNode* subRoot) {
        if (!root) { return false; }
        return LeftEqualRight(root, subRoot) || dfs(root->left, subRoot) || dfs(root->right, subRoot);
    }
    bool LeftEqualRight(TreeNode* Left, TreeNode* Right) {
        if (Left == nullptr && Right != nullptr) { return false; }
        if (Left != nullptr && Right == nullptr) { return false; }
        if (Left == nullptr && Right == nullptr) { return true; }
        if (Left != nullptr && Right != nullptr && Left->val != Right->val) { return false; }
        bool out = LeftEqualRight(Left->left, Right->left);
        bool in = LeftEqualRight(Left->right, Right->right);
        return in && out;
    }
};