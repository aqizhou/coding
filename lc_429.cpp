/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (root == nullptr) { return res; }
        queue<Node*> que;
        que.push(root);
        int size = 0;
        vector<int> level_res;
        while (!que.empty()) {
            size = que.size();
            for (int i = 0; i < size; ++i) {
                auto front = que.front();
                que.pop();
                level_res.push_back(front->val);
                for (auto child : front->children) {
                    if (child != nullptr) {
                        que.push(child);
                    }
                }
            }
            res.push_back(level_res);
            level_res.clear();
        }
        return res;
    }
};