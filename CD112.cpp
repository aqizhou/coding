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
	bool IsPalindrome() {
		Node* slow = head_->next;
		Node* fast = head_->next;
		while (fast != nullptr && fast->next != nullptr) {//快慢指针找到链表的中点 分奇偶数，奇数找到的刚好是中点，偶数是中间节点后面一个节点，所以反转后右边节点大于等于左边节点的个数，所以下面while循环中是fast做判空操作，而不是slow。即左边做判空操作，而不是右边。
			slow = slow->next;
			fast = fast->next->next;
		}
		slow = Reverse(slow);
		fast = head_->next;
		while (fast) {
			if (fast->value != slow->value) {
				return false;
			}
			slow = slow->next;
			fast = fast->next;
		}
		return true;
	}
	Node* Reverse(Node* slow) {
		Node* pre = nullptr;
		Node* cur = head_->next;
		while (cur) {
			Node* temp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = temp;
		}
		return pre;
	}
};



int main() {
	int n;
	cin >> n;
	NodeManager node_manager;
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