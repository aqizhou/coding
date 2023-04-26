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
		while (tail_->next != tail_) {
			for (int i = 0; i < m-1; ++i) {
				tail_ = head_;
				head_ = head_->next;
			}
			tail_->next = head_->next;
			head_ = tail_->next;
		}
		return head_;
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	CircleList circle_list;
	circle_list.CreateNodeList(n);
	//circle_list.PrintList();
	cout << circle_list.JosephusDelete(m)->value;
}