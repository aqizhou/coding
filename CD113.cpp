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
		Node* temp = head_->next;
		int len = 0;
		while (temp) {
			++len;
			temp = temp->next;
		}
		arr_ = new Node[len]{Node(0)};
		temp = head_->next;
		for (int i = 0; i < len; ++i) {
			arr_[i] = temp->value;
			temp = temp->next;
		}
		temp = head_->next;
		int small = 0;
		int large = len;
		int index = 0;
		while(index!=large){
			if (arr_[index].value < pivot) {
				_SwapNodeValue(index++, small++);
			}
			else if (arr_[index].value == pivot) {
				++index;
			}
			else {
				_SwapNodeValue(index, --large);
			}
		}
		int i = 0;
		for (i = 0; i < len-1; ++i) {
			arr_[i].next = &arr_[i + 1];
		}
		arr_[i].next = nullptr;
		return arr_;
	}
protected:
	void _SwapNodeValue(int a, int b) {
		Node temp = arr_[a];
		arr_[a].value = arr_[b].value;
		arr_[b] = temp.value;
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