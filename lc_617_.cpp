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
#include<queue>
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) { return nullptr; }
        if (!root1) { return root2; }
        if (!root2) { return root1; }
        queue<TreeNode*> que;
        que.push(root1);
        que.push(root2);
        while (!que.empty()) {
            TreeNode* node1 = que.front(); que.pop();
            TreeNode* node2 = que.front(); que.pop();
            node1->val += node2->val;
            if (node1->left && node2->left) {
                que.push(node1->left);
                que.push(node2->left);
            }
            if (node1->right && node2->right) {
                que.push(node1->right);
                que.push(node2->right);
            }
            if (!node1->left || !node2->left) {
                node1->left = node1->left ? node1->left :node2->left;
            }
            if (!node1->right || !node2->right) {
                node1->right = node1->right ? node1->right : node2->right;
            }
        }
        return root1;
    }
};