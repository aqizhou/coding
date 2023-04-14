#include<iostream>
using namespace std;

struct node {
	node* next;
	int value;
};

int main() {
	int length, del_index;
	cin >> length >> del_index;
	node* head = new node;
	node* temp = head;
	for (int i = 0; i < length; ++i) {
		node* new_node = new node;
		cin>>new_node->value;
		temp->next = new_node;
		new_node->next = nullptr;
		temp = new_node;
	}
	int real_index = length - del_index;
	temp = head->next;
	int i = 0;
	while (i<real_index-1) {
		temp = temp->next;
		++i;
	}
	node* del_node = temp->next;
	temp->next = del_node->next;
	delete del_node;
	head = head->next;
	while (head) {
		cout << head->value << " ";
		head = head->next;
	}
}