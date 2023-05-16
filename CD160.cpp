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
	ListNode* head() { return head_; }
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
	ListNode* TruncateList() {
		tail_ = head_;
		if (tail_==nullptr||tail_->next==nullptr) {
			return nullptr;
		}
		tail_ = tail_->next->next;
		int cnt = 0;
		ListNode* mid = head_;
		while (tail_) {
			++cnt;
			if (cnt % 2 == 0) {
				mid = mid->next;
			}
			tail_ = tail_->next;
		}
		ListNode* res = mid->next;
		mid->next = nullptr;
		return res;
	}
	ListNode* MergeLeftAndRightNode(ListNode* head1, ListNode* head2) {
		if (head1 == nullptr || head2 == nullptr) {
			return head1 == nullptr ? head2 : head1;
		}
		ListNode* head = head1,*tail=head;
		head1 = head1->next;
		enum Oder {
			kLeft,
			kRight
		};
		bool i = 1;
		while (head1 && head2) {			
			switch (i) {
				case kLeft:{
					tail->next = head1;
					tail = head1;
					head1 = head1->next;
					i = 1;
					break;
				}
				case kRight: {
					tail->next = head2;
					tail = head2;
					head2 = head2->next;
					i = 0;
					break;
				}
			}
		}
		tail->next = head1 == nullptr ? head2 : head1;
		return head;
	}

	void PrintList(ListNode* head) {
		while (head) {
			cout << head->val << " ";
			head = head->next;
		}
	}
};



int main() {
	int m;
	cin >> m;
	int val;
	Solution sol, sol2;
	for (int i = 0; i < m; ++i) {
		cin >> val;
		sol.PushBack(val);
	}
	ListNode* right = sol.TruncateList();
	ListNode* head = sol.MergeLeftAndRightNode(sol.head(),right);
	sol.PrintList(head);
}