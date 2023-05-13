#include<iostream>
#include<unordered_map>
using namespace std;

struct ListNode {
	int val;
	ListNode* last, * next;
	ListNode(int v) :val(v), last(nullptr), next(nullptr) {}
	ListNode(ListNode* node) :val(node->val), last(node->last), next(node->next) {}
};

struct BST {
	int val;
	BST* left, * right;
	BST(int v) :val(v), left(nullptr), right(nullptr) {}
};

class Solution {
protected:
	ListNode* head_=nullptr;
	ListNode* pre_ = nullptr, * cur_ = nullptr;
protected:
	void _InOrderToQueue(BST* node) {
		if (node == nullptr) { return; }
		_InOrderToQueue(node->left);
		cur_ = new ListNode(node->val);
		if (pre_ == nullptr) {
			head_ = cur_;
		}
		else {
			pre_->next = cur_;
		}
		cur_->last = pre_;
		pre_ = cur_;
		_InOrderToQueue(node->right);
	}
public:
	BST* HandleInput() {
		int num;
		cin >> num;
		int val, left_val, right_val;
		unordered_map<int, BST*> bst_map;
		BST* root = nullptr, * cur_node = nullptr;
		for (int i = 0; i < num; ++i) {
			cin >> val >> left_val >> right_val;
			if (bst_map.find(val) == bst_map.end()) {
				BST* new_tree_node = new BST(val);
				cur_node = new_tree_node;
				bst_map[val] = new_tree_node;
				if (i == 0) {
					root = new_tree_node;
				}
			}
			else {
				cur_node = bst_map[val];
			}
			if (left_val) {
				BST* new_tree_node = new BST(left_val);
				bst_map[left_val] = new_tree_node;
				cur_node->left = new_tree_node;
			}
			if (right_val) {
				BST* new_tree_node = new BST(right_val);
				bst_map[right_val] = new_tree_node;
				cur_node->right = new_tree_node;
			}
		}
		return root;
	}
	ListNode* ConvertToList(BST* root) {
		if (root == nullptr) { return nullptr; }
		_InOrderToQueue(root);
		return head_;
	}
	void PrintList(ListNode* head) {
		while (head) {
			cout << head->val << " ";
			head = head->next;
		}
	}
};

int main() {
	Solution slt;
	BST* root = slt.HandleInput();
	ListNode* head = slt.ConvertToList(root);
	slt.PrintList(head);
	return 0;
}