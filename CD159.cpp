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
	ListNode* MergeNode(ListNode* head1, ListNode* head2) {
		if (head1 == nullptr || head2 == nullptr) {
			return head1 == nullptr ? head2 : head1;
		}
		ListNode* head = nullptr,*tail=nullptr;
		while (head1 && head2) {
			if (head == nullptr) {
				if (head1->val <= head2->val) {
					head = head1;
					head1 = head1->next;
				}
				else {
					head = head2;
					head2 = head2->next;
				}
				tail = head;
			}
			else {
				tail->next = head1->val <= head2->val ? head1 : head2;
				if (tail->next == head1) {
					tail = head1;
					head1 = head1->next;
				}
				else {
					tail = head2;
					head2 = head2->next;
				}
			}
		}
		/*while (head1) {
			tail->next = head1;
			tail = head1;
			head1 = head1->next;
		}
		while (head2) {
			tail->next = head2;
			tail = head2;
			head2 = head2->next;
		}*/
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
	Solution sol,sol2;
	for (int i = 0; i < m; ++i) {
		cin >> val;
		sol.PushBack(val);
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> val;
		sol2.PushBack(val);
	}
	ListNode* head = sol.MergeNode(sol.head(), sol2.head());
	sol.PrintList(head);
}