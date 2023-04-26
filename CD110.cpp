#include<iostream>
using namespace std;

struct Node {
	Node* next;
	int value;
};

class CircleList {
protected:
	Node* head_;
	Node* tail_;
public:
	CircleList() {
		head_ = new Node;
		tail_ = new Node;
	}
	void CreateNodeList(int n) {
		head_->value = 1;
		head_->next = nullptr;
		tail_ = head_;
		for (int i = 2; i <= n; ++i) {
			Node* new_node = new Node;
			new_node->value = i;
			new_node->next = nullptr;
			tail_->next = new_node;
			tail_ = new_node;
		}
		tail_->next = head_;
	}
	void PrintList() {
		Node* temp = head_;
		do {
			cout << temp->value << " ";
			temp = temp->next;
		} while (temp != head_);
	}
	Node* JosephusDelete(int m) {
		Node* cur = head_->next;
		int temp = 1;
		while (cur != head_) {
			++temp;
			cur = cur->next;
		}
		temp = _GetLive(temp, m);
		while (--temp != 0) {
			head_ = head_->next;
		}
		return head_;
	}
protected:
	int _GetLive(int i, int m) {
		if (i == 1) {
			return 0;
		}
 		return (_GetLive(i - 1, m) + m) % i;
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	CircleList circle_list;
	circle_list.CreateNodeList(n);
	//circle_list.PrintList();
	cout << circle_list.JosephusDelete(m)->value+1;
}