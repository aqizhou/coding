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
protected:
	ListNode* _FindNode(int order) {
		tail_ = head_;
		while (--order) {
			tail_ = tail_->next;
		}
		return tail_;
	}
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
	void DeleteNode(int del_order) {
		ListNode* del_node = _FindNode(del_order);
		ListNode* next = del_node->next;
		del_node->val = next->val;
		del_node->next = next->next;
		delete next;
		next = nullptr;
	}
	
	void PrintList() {
		while (head_) {
			cout << head_->val << " ";
			head_ = head_->next;
		}
	}
};

int main() {
	int num;
	cin >> num;
	int val;
	Solution sol;
	for (int i = 0; i < num; ++i) {
		cin >> val;
		sol.PushBack(val);
	}
	int del_order;
	cin >> del_order;
	sol.DeleteNode(del_order);
	sol.PrintList();
}