#include<iostream>
#include<unordered_map>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

struct ListNode {
    int value;
    ListNode* left, *right;
    ListNode(int val) :value(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    ListNode* HandleInput() {
        int n,root_value;
        cin >> n>> root_value;
        unordered_map<int,ListNode*> mp;
        ListNode* root = new ListNode(root_value);
        mp[root_value] = root;
        int self_value, left_value, right_value;
        ListNode* cur_node=nullptr;
        for (int i = 0; i < n; ++i) {
            cin>> self_value>>left_value>>right_value;
            if (mp.find(root_value) == mp.end()) {
                ListNode* new_node = new ListNode(self_value);
                mp[self_value] = new_node;
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
    void PrintTree(ListNode* root) {
        _PreorderTraversal(root);
        cout << endl;
        _InorderTraversal(root);
        cout << endl;
        _PostorderTraversal(root);
    }
protected:
    //前序
    void _PreorderTraversal(ListNode* root) {
        if (root == nullptr) { return; }
        stack<ListNode*> stk;
        vector<int> res;
        stk.push(root);
        while(!stk.empty()){
            ListNode* top = stk.top();
            stk.pop();
            res.push_back(top->value);
            if(top->right){stk.push(top->right);}
            if(top->left){stk.push(top->left);}
        }
        for(auto r:res){
            cout<<r<<" ";
        }
    }
    //中序
    void _InorderTraversal(ListNode* root) {
        if (root == nullptr) { return; }
        stack<ListNode*> stk;
        auto cur_node = root;
        vector<int> res;
        while(!stk.empty()||cur_node!=nullptr){
            if(cur_node==nullptr){
                cur_node = stk.top();
                stk.pop();
                res.push_back(cur_node->value);
                cur_node=cur_node->right;
            }
            else{
                stk.push(cur_node);
                cur_node=cur_node->left;
            }
        }
        for(auto r:res){
            cout<<r<<" ";
        }
    }
    //后序
    void _PostorderTraversal(ListNode* root) { //中左右->中右左->左右中
        if (root == nullptr) { return; }
        stack<ListNode*> stk;
        vector<int> res;
        stk.push(root);
        while(!stk.empty()){
            ListNode* top = stk.top();
            stk.pop();
            res.push_back(top->value);
            if(top->left){stk.push(top->left);}
            if(top->right){stk.push(top->right);}
        }
        reverse(res.begin(), res.end());
        for(auto r:res){
            cout<<r<<" ";
        }
    }
};

int main() {
    Solution sol;
    auto root = sol.HandleInput();
    sol.PrintTree(root);
}