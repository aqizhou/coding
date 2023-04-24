#include<iostream>
using namespace std;

struct Node {
	Node* next;
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
	Node* ReverseNode(int l,int r) {
		Node* dummy = head_;
		Node* pre = head_;
		for (int i = 0; i < l-1; ++i) {
			pre = pre->next;
		}
		Node* cur=pre->next;
		Node* temp = nullptr;
		for (int i = 0; i < r - l; ++i) {//抽书法 抽书次数=r-l
			temp = cur->next;
			cur->next = temp->next;
			temp->next = pre->next;
			pre->next = temp;
		}
		return dummy->next;
	}
	void PrintList(Node* head) {
		while (head) {
			cout << head->value << " ";
			head = head->next;
		}
	}
};

int main() {
	int n;
	cin >> n;
	int val;
	NodeManager node_manager;
	for (int i = 0; i < n; ++i) {
		cin >> val;
		node_manager.PushBack(val);
	}
	int L, R;
	cin >> L >> R;
	Node* head = node_manager.ReverseNode(L,R);
	node_manager.PrintList(head);
	return 0;
}