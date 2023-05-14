#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {

protected:
	ListNode* head_=nullptr;
	ListNode* tail_=nullptr;
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
	ListNode* Sort() {
		ListNode* cur = nullptr;
		ListNode* pre = nullptr;
		ListNode* min_node = nullptr,*min_node_pre=nullptr;
		ListNode* new_head = nullptr,*new_tail=nullptr;
		while (head_) {
			pre = head_;
			cur = head_->next;
			min_node = head_;
			while (cur) {
				if (min_node->val > cur->val) {
					min_node = cur;
					min_node_pre = pre;
				}
				pre = cur;
				cur = cur->next;
			}
			if (min_node_pre != nullptr) {
				min_node_pre->next = min_node->next;
				min_node_pre = nullptr;
			}
			else {
				head_ = head_->next;
			}
			if (new_head == nullptr) {
				new_head = min_node;
				new_tail = new_head;
			}
			else {
				new_tail->next = min_node;
				new_tail = min_node;
			}
		}
		return new_head;
	}
	void PrintList(ListNode* head) {
		while (head) {
			cout << head->val << " ";
			head = head->next;
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
	ListNode* head = sol.Sort();
	sol.PrintList(head);
}