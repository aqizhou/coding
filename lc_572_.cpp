#include<iostream>
#include<queue>
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
    bool LeftEqualRight(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> que;
        que.push(p);
        que.push(q);
        while (!que.empty()) {
            TreeNode* left = que.front(); que.pop();
            TreeNode* right = que.front(); que.pop();
            if (left == nullptr && right == nullptr) { continue; }
            if (left == nullptr || right == nullptr || left->val != right->val) {
                return false;
            }
            que.push(left->left);
            que.push(right->left);
            que.push(left->right);
            que.push(right->right);
        }
        return true;
    }
};