#include <stack>
#include<iostream>

using namespace std;

class MyQueue {
protected:
	stack<int> main_stack_;
	stack<int> util_stack_;
public:
	void Add(int value);
	int Peek();
	void Poll();
};

void MyQueue::Add(int value) {
	main_stack_.push(value);
}

int MyQueue::Peek() {
	if (util_stack_.empty()) {
		while (!main_stack_.empty()) {
			util_stack_.push(main_stack_.top());
			main_stack_.pop();
		}		
	}
	return util_stack_.top();
}

void MyQueue::Poll() {
	if (util_stack_.empty()) {
		while (!main_stack_.empty()) {
			util_stack_.push(main_stack_.top());
			main_stack_.pop();
		}
	}
	util_stack_.pop();
}



int main() {
	int N;
	cin >> N;
	string cmd;
	int value;
	MyQueue my_queue;
	for (int i = 0; i < N; ++i) {
		cin >> cmd;
		if (cmd == "add") {
			cin >> value;
			my_queue.Add(value);
		}
		else if (cmd == "peek") {
			cout << my_queue.Peek() << endl;
		}
		else if (cmd == "poll") {
			my_queue.Poll();
		}
	}
}

