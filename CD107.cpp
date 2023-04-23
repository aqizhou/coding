#include<iostream>
using namespace std;

struct Node {
	Node* next;
	int value;
};

struct DoubleNode {
	DoubleNode* last;
	DoubleNode* next;
	int value;
};

class NodeManager {
protected:
	Node* head_;
	Node* tail_;
public:
	NodeManager() {
		head_ = new Node;
		tail_ = new Node;
		head_->next = nullptr;
		tail_ = head_;
	}
	void PushBack(int val) {
		Node* new_node = new Node;
		new_node->value = val;
		new_node->next = nullptr;
		tail_->next = new_node;
		tail_ = new_node;
	}
	Node* ReverseList() {
		Node* pre = nullptr;
		Node* cur = head_->next;
		Node* temp;
		while (cur) {
			temp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = temp;
		}
		return pre;
	}
	void PrintList(Node* head) {
		while (head) {
			cout << head->value << " ";
			head = head->next;
		}
		cout << endl;
	}
};

class DoubleNodeManager {
protected:
	DoubleNode* head_;
	DoubleNode* tail_;
public:
	DoubleNodeManager() { 
		head_ = new DoubleNode; 
		tail_ = new DoubleNode; 
		tail_ = head_; 
	}
	void PushBack(int val){
		DoubleNode* new_node = new DoubleNode;
		new_node->value = val;
		new_node->next = nullptr;
		tail_->next = new_node;
		tail_ = new_node;
	}
	DoubleNode* ReverseList() {
		DoubleNode* pre = nullptr;
		DoubleNode* cur = head_->next;
		DoubleNode* temp;
		while (cur) {
			temp = cur->next;
			cur->next = pre;
			cur->last = temp;
			pre = cur;
			cur = temp;
		}
		return pre;
	}
	void PrintList(DoubleNode* head) {
		while (head) {
			cout << head->value << " ";
			head = head->next;
		}
		cout << endl;
	}
};

int main() {
	int n, m, val;
	cin >> n;
	NodeManager node_manager;
	for (int i = 0; i < n; ++i) {
		cin >> val;
		node_manager.PushBack(val);
	}
	Node* head = node_manager.ReverseList();
	node_manager.PrintList(head);

	cin >> m;
	DoubleNodeManager double_node_manager;
	for (int j = 0; j < m; ++j) {
		cin >> val;
		double_node_manager.PushBack(val);
	}
	DoubleNode* head_2 = double_node_manager.ReverseList();
	double_node_manager.PrintList(head_2);
}