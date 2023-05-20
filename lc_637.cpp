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
#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if (root == nullptr) { return res; }
        queue<TreeNode*> que;
        que.push(root);
        int size = 0;
        double sum = 0;
        while (!que.empty()) {
            size = que.size();
            sum = 0;
            for (int i = 0; i < size; ++i) {
                auto front = que.front();
                que.pop();
                sum += front->val;
                if (front->left) { que.push(front->left); }
                if (front->right) { que.push(front->right); }
            }
            double avg = sum / size;
            res.push_back(avg);
        }
        return res;
    }
};