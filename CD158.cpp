#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
protected:
	ListNode* head_ = nullptr;
	ListNode* tail_ = nullptr;
public:
	void PushBack(int val) {
		if (head_ == nullptr) {
			head_ = new ListNode(val);
			tail_ = head_;
		}
		else {
			ListNode* new_node = new ListNode(val);
			tail_->next = new_node;
			tail_ = new_node;
		}
	}
	void PushEnd(int val) {
		if (head_ == nullptr) {
			head_ = new ListNode(val);
			head_->next = head_;
		}
		else {
			ListNode* new_node = new ListNode(val);
			tail_->next = new_node;
			tail_ = new_node;
			tail_->next = head_;
		}
	}
	void InsertNode(int insert_val) {
		ListNode* pre = head_;
		ListNode* cur = head_->next;
		while (1) {
			if (pre->val <= insert_val && cur->val >= insert_val) {
				ListNode* new_node = new ListNode(insert_val);
				pre->next = new_node;
				new_node->next = cur;
				break;
			}
			pre = cur;
			cur = cur->next;
			if (cur == head_->next) { break; }
		}
		if (cur == head_->next) {
			ListNode* new_node = new ListNode(insert_val);
			tail_->next = new_node;
			new_node->next = pre;
			head_ = head_->val < new_node->val ? head_ : new_node;
		}
	}
	void PrintList() {
		ListNode* temp = head_;
		while (1) {
			cout << head_->val << " ";
			head_ = head_->next;
			if (temp == head_) {
				break;
			}
		}
	}
};

int main() {
	int num;
	cin >> num;
	int val;
	Solution sol;
	for (int i = 0; i < num-1; ++i) {
		cin >> val;
		sol.PushBack(val);
	}
	cin >> val;
	sol.PushEnd(val);
	int insert_val;
	cin >> insert_val;
	sol.InsertNode(insert_val);
	sol.PrintList();
}