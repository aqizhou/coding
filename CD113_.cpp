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
	Node* arr_;
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
	Node* SortNode(int pivot) {
		Node* small_head = nullptr;
		Node* small_tail = nullptr;
		Node* equal_head = nullptr;
		Node* equal_tail = nullptr;
		Node* large_head = nullptr;
		Node* large_tail = nullptr;

		Node* temp = head_->next;
		while (temp) {
			if (temp->value < pivot) {
				if (!small_head) {
					small_head = temp;
					small_tail = small_head;
				}
				else {
					small_tail->next = temp;
					small_tail = temp;
				}
			}
			else if (temp->value == pivot) {
				if (!equal_head) {
					equal_head = temp;
					equal_tail = equal_head;
				}
				else {
					equal_tail->next = temp;
					equal_tail = temp;
				}
			}
			else {
				if (!large_head) {
					large_head = temp;
					large_tail = large_head;
				}
				else {
					large_tail->next = temp;
					large_tail = temp;
				}
			}
			temp = temp->next;
		}
		Node* res=nullptr;
		if (small_head) {
				res = small_head;
		}
		if (equal_head) {
			small_tail->next = equal_head;
			equal_tail->next = large_head;
			if (!res) {
				res = equal_head;
			}
		}
		else {
			small_tail->next = large_head;
		}
		if (large_head) {
			if (!res) {
				res = large_head;
			}
		}
		return res;
	}
};

int main() {
	int n, pivot;
	cin >> n >> pivot;
	int val;
	NodeManager node_manager;
	for (int i = 0; i < n; ++i) {
		cin >> val;
		node_manager.PushBack(val);
	}
	Node* head = node_manager.SortNode(pivot);
	for (int i = 0; i < n; ++i) {
		cout << head->value << " ";
		head = head->next;
	}
	return 0;
}