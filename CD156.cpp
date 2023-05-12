#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;

struct ListNode {
	int val;
	ListNode* last, * next;
	ListNode(int v) :val(v),last(nullptr),next(nullptr){}
};

struct BST {
	int val;
	BST* left, * right;
	BST(int v) :val(v), left(nullptr), right(nullptr) {}
};

class Solution {
protected:
	void _InOrderToQueue(BST* node, queue<int>& que) {
		if (node == nullptr) { return; }
		_InOrderToQueue(node->left, que);
		que.push(node->val);
		_InOrderToQueue(node->right, que);
	}
public:
	BST* HandleInput() {
		int num;
		cin >> num;
		int val, left_val, right_val;
		unordered_map<int,BST*> bst_map;
		BST* root=nullptr,*cur_node = nullptr;
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
		queue<int> que;
		_InOrderToQueue(root, que);
		ListNode* head = nullptr,*tail=nullptr;
		while (!que.empty()) {
			int front = que.front();
			ListNode* new_node = new ListNode(front);
			if (head == nullptr) { 
				head = new_node;
				tail = head; 
			}
			else {
				new_node->last = tail;
				tail->next = new_node;
				tail = new_node;
			}
			que.pop();
		}
		return head;
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