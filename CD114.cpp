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
	int Res() {
		Node* temp = head_->next;
		int res=0;
		while (temp) {
			res = res*10+temp->value;
			temp = temp->next;
		}
		return res;
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
	int res1 = node_mgr1.Res();
	int res2 = node_mgr2.Res();
	int res = res1 + res2;
	int temp = res;
	int num = 0;
	
	stack<int> stk;
	while (res) {
		int left = res % 10;
		stk.push(left);
		res /= 10;
	}
	NodeManager node_mgr;
	while (!stk.empty()) {
		int top = stk.top();
		stk.pop();
		node_mgr.PushBack(top);
	}
	node_mgr.PrintNode();
}