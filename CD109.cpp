#include<iostream>
using namespace std;

struct Node {
	Node* next;
	int value;
};

class CircleList {
public:
	Node* CreateNodeList(int n) {
		Node* head = new Node;
		head->value = 1;
		head->next = nullptr;
		Node* temp = head;
		for (int i = 2; i <= n; ++i) {
			Node* new_node = new Node;
			new_node->value = i;
			new_node->next = nullptr;
			temp->next = new_node;
			temp = new_node;
		}
		temp->next = head;
		return head;
	}
	void PrintList(Node* head) {
		Node* temp = head;
		do{
			cout << temp->value << " ";
			temp = temp->next;
		} while (temp != head);
	}
	Node* JosephusDelete(Node* head,int m) {
		Node* last = head;
		while (last->next != head) {
			last = last->next;
		}
		int cnt = 0;
		while (head != last) {
			if (++cnt == m) {
				cnt = 0;
				last->next = head->next;
			}
			else {				
				last = last->next;
			}
			head = last->next;
		}
		return head;
	}

};

int main() {
	int n, m;
	cin >> n >> m;
	CircleList circle_list;
	Node* head = circle_list.CreateNodeList(n);
	//circle_list.PrintList(head);
	cout<<circle_list.JosephusDelete(head,m)->value;
}