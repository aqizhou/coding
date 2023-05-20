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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) { return res; }
        queue<TreeNode*> que;
        que.push(root);
        int max,size=0;
        while (!que.empty()) {
            max = INT_MIN;
            size = que.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* front = que.front();
                que.pop();
                max = max < front->val ? front->val : max;
                if (front->left) { que.push(front->left); }
                if (front->right) { que.push(front->right); }
            }
            res.push_back(max);
        }
        return res;
    }
};