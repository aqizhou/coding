#include<iostream>
using namespace std;

struct Node {
	Node* next;
	int value;
	Node() :value(-1), next(nullptr) {}
	Node(int val) {
		value = val;
		next = nullptr;
	}
};

class NodeManager {
protected:
	Node* head_;
	Node* tail_;
public:
	NodeManager() {
		head_ = new Node(-1);
		tail_ = new Node(-1);
		tail_ = head_;
	}
	void PushBack(int val) {
		Node* new_node = new Node(val);
		tail_->next = new_node;
		tail_ = new_node;
	}
	Node* ReverseList() {
		Node* cur = head_->next;
		Node* pre = nullptr;
		Node* nex = nullptr;
		while (cur) {
			nex = cur->next;
			cur->next = pre;
			pre = cur;
			cur = nex;
		}
		return pre;
	}
	void PrintNode(Node* node) {
		Node* temp = node;
		while (temp) {
			cout << temp->value << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	NodeManager node_mgr1;
	NodeManager node_mgr2;
	int val;
	for (int i = 0; i < n; ++i) {
		cin >> val;
		node_mgr1.PushBack(val);
	}
	for (int j = 0; j < m; ++j) {
		cin >> val;
		node_mgr2.PushBack(val);
	}
	Node* node1 = node_mgr1.ReverseList();
	Node* node2 = node_mgr2.ReverseList();
	int sum;
	bool add = false;
	NodeManager node_mgr;
	while (node1 && node2) {
		sum = node1->value + node2->value+add;
		if (sum >= 10) {
			add = true;
			sum = sum % 10;
		}
		else {
			add = false;
		}
		node_mgr.PushBack(sum);
		node1 = node1->next;
		node2 = node2->next;
	}
	while (node1) {
		sum = node1->value  + add;
		if (sum >= 10) {
			add = true;
			sum = sum % 10;
		}
		else {
			add = false;
		}
		node_mgr.PushBack(sum);
		node1 = node1->next;
	}
	while (node2) {
		sum = node2->value + add;
		if (sum >= 10) {
			add = true;
			sum = sum % 10;
		}
		else {
			add = false;
		}
		node_mgr.PushBack(sum);
		node2 = node2->next;
	}
	if (add) {
		node_mgr.PushBack(add);
	}
	Node* res = node_mgr.ReverseList();
	node_mgr.PrintNode(res);
}