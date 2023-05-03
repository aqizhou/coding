#include<iostream>
#include<stack>
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
	stack<int> stk;
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
	stack<int>& Node2Stack() {
		Node* temp = head_->next;
		while (temp) {
			stk.push(temp->value);
			temp = temp->next;
		}
		return stk;
	}
	void PrintNode() {
		Node* temp = head_->next;
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
	int sum;
	bool add = false;
	stack<int> stk;
	auto& stk1 = node_mgr1.Node2Stack();
	auto& stk2 = node_mgr2.Node2Stack();
	while (!stk1.empty() && !stk2.empty()) {
		int top1 = stk1.top();
		stk1.pop();
		int top2 = stk2.top();
		stk2.pop();
		sum = top1 + top2+add;
		if (sum >= 10) {
			sum = sum % 10;
			add = true;
		}
		else {
			add = false;
		}
		stk.push(sum);
	}
	while(!stk1.empty()) {
		int top1 = stk1.top();
		stk1.pop();
		sum = top1 +add;
		if (sum >= 10) {
			sum = sum % 10;
			add = true;
		}
		else {
			add = false;
		}
		stk.push(sum);
	}
	while (!stk2.empty()) {
		int top2 = stk2.top();
		stk2.pop();
		sum = top2 + add;
		if (sum >= 10) {
			sum = sum % 10;
			add = true;
		}
		else {
			add = false;
		}
		stk.push(sum);
	}
	if (add) {
		stk.push(add);
	}
	NodeManager node_mgr;
	while (!stk.empty()) {
		int top = stk.top();
		stk.pop();
		node_mgr.PushBack(top);
	}
	node_mgr.PrintNode();
}