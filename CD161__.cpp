#include<iostream>
#include<unordered_map>
#include<stack>
#include<vector>
using namespace std;

struct ListNode {
    int value;
    ListNode* left, * right;
    ListNode(int val) :value(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    ListNode* HandleInput() {
        int num, root_value;
        cin >> num >> root_value;
        if (num <= 0) { return nullptr; }
        ListNode* root = new ListNode(root_value);
        unordered_map<int,ListNode*> mp;
        mp[root_value] = root;
        ListNode* cur_node = root;
        int self_value = 0, left_value = 0, right_value = 0;
        for (int i = 0; i < num; ++i) {
            cin >> self_value >> left_value >> right_value;
            if (mp.find(self_value)==mp.end()) {
                ListNode* new_node = new ListNode(self_value);
                cur_node = new_node;
            }
            else {
                cur_node = mp[self_value];
            }
            if (left_value) {
                ListNode* new_node = new ListNode(left_value);
                mp[left_value] = new_node;
                cur_node->left = new_node;
            }
            if (right_value) {
                ListNode* new_node = new ListNode(right_value);
                mp[right_value] = new_node;
                cur_node->right = new_node;
            }
        }
        return root;
    }
    //前序
    vector<int> PreorderPrint(ListNode* root) {
        vector<int> res;
        if (root == nullptr) { return res; }
        stack<ListNode*> stk;
        stk.push(root);
        ListNode* cur_node = nullptr;
        while (!stk.empty()) {
            cur_node = stk.top();
            stk.pop();
            if (cur_node != nullptr) {
                if(cur_node->right) stk.push(cur_node->right);
                if (cur_node->left) stk.push(cur_node->left);
                stk.push(cur_node);
                stk.push(nullptr);
            }
            else {
                res.push_back(stk.top()->value);
                stk.pop();
            }
        }
        return res;
        
    }
    //中序
    vector<int> InorderPrint(ListNode* root) {
        vector<int> res;
        if (root == nullptr) { return res; }
        stack<ListNode*> stk;
        stk.push(root);
        ListNode* cur_node = nullptr;
        while (!stk.empty()) {
            cur_node = stk.top();
            stk.pop();
            if (cur_node != nullptr) {
                if (cur_node->right) stk.push(cur_node->right);
                stk.push(cur_node);
                stk.push(nullptr);
                if (cur_node->left) stk.push(cur_node->left);
            }
            else {
                res.push_back(stk.top()->value);
                stk.pop();
            }
        }
        return res;
    }
    //后序
    vector<int> PostorderPrint(ListNode* root) {
        vector<int> res;
        if (root == nullptr) { return res; }
        stack<ListNode*> stk;
        stk.push(root);
        ListNode* cur_node = nullptr;
        while (!stk.empty()) {
            cur_node = stk.top();
            stk.pop();
            if (cur_node != nullptr) {
                stk.push(cur_node);
                stk.push(nullptr);
                if (cur_node->right) stk.push(cur_node->right);
                if (cur_node->left) stk.push(cur_node->left);
            }
            else {
                res.push_back(stk.top()->value);
                stk.pop();
            }
        }
        return res;
    }
    void PrintTree(ListNode* root) {
        auto preorder_res = PreorderPrint(root);
        for (auto r : preorder_res) {
            cout << r << " ";
        }
        cout << endl;

        auto inorder_res = InorderPrint(root);
        for (auto r : inorder_res) {
            cout << r << " ";
        }
        cout << endl;

        auto postorder_res = PostorderPrint(root);
        for (auto r : postorder_res) {
            cout << r << " ";
        }
    }
};

int main() {
    Solution sol;
    auto root = sol.HandleInput();
    sol.PrintTree(root);
}