#include<iostream>
#include<unordered_map>
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
	//Ç°Ðò
	void _PreorderTraversal(ListNode* root) {
		if (root == nullptr) { return; }
		cout << root->value << " ";
		_PreorderTraversal(root->left);
		_PreorderTraversal(root->right);
	}
	//ÖÐÐò
	void _InorderTraversal(ListNode* root) {
		if (root == nullptr) { return; }
		_InorderTraversal(root->left);
		cout << root->value << " ";
		_InorderTraversal(root->right);
	}
	//ºóÐò
	void _PostorderTraversal(ListNode* root) {
		if (root == nullptr) { return; }
		_PostorderTraversal(root->left);
		_PostorderTraversal(root->right);
		cout << root->value << " ";
	}
};

int main() {
	Solution sol;
	auto root = sol.HandleInput();
	sol.PrintTree(root);
}