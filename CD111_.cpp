#include<iostream>
#include<stack>
using namespace std;

struct Node {
	Node* next;
	int value;
};

class NodeManager {
protected:
	Node* head_;
	Node* tail_;
	stack<int> util_stack_;
	int elem_size_;
public:
	NodeManager(int n) {
		elem_size_ = n;
		if (elem_size_ % 2 != 0) { ++elem_size_; }//弄成偶数 一半元素进栈好处理
		head_ = new Node;
		tail_ = new Node;
		head_->next = nullptr;	
		tail_ = head_;
	}
	void PushBack(int val) {
		static int i = 0;
		if (i++ >= elem_size_ / 2) {
			util_stack_.push(val);
		}
		Node* new_node = new Node;
		new_node->value = val;
		new_node->next = nullptr;
		tail_->next = new_node;
		tail_ = new_node;
	}
	bool IsPalindrome() {
		Node* temp = head_->next;
		while (!util_stack_.empty()) {
			int top = util_stack_.top();
			util_stack_.pop();
			if (temp->value != top) {
				return false;
			}
			else {
				temp = temp->next;
			}
		}
		return true;
	}
};



int main() {
	int n;
	cin >> n;
	NodeManager node_manager(n);
	int val;
	for (int i = 0; i < n; ++i) {
		cin >> val;
		node_manager.PushBack(val);
	}
	if (node_manager.IsPalindrome()) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
	return 0;
}