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
	Node* PushLastNode(int val, int pos) {
		if (pos == -1) {
			PushBack(val);
		}
		else {
			Node* new_node = new Node;
			new_node->value = val;
			tail_->next = new_node;
			tail_ = new_node;
			Node* temp = head_->next;
			while (pos--) {
				temp = temp->next;
			}
			new_node->next = temp;
		}
		return head_->next;
	}
};


class Solution {
public:
	int hasCycle(Node* head) {
		Node* slow = head;
		Node* fast = head;
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) {
				break;
			}
		}
		if (slow != fast||slow==head) { return -1; }
		Node* temp = head;
		while (temp!=slow) {
			temp = temp->next;
			slow = slow->next;
		}
		return slow->value;
	}
};

int main() {
	int N;
	cin >> N;
	int input;
	NodeManager node_manager;
	for (int i = 0; i < N - 1; ++i) {
		cin >> input;
		node_manager.PushBack(input);
	}
	cin >> input;
	int pos;
	cin >> pos;
	Node* head = node_manager.PushLastNode(input, pos);
	Solution s;
	cout << s.hasCycle(head) << endl;
	return 0;
}