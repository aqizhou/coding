#include<iostream>
#include<stack>

class MyStack {
protected:
	std::stack<int> my_stack_;
public:
	int ReverseStackFunc();
	void Reverse();
	int Top() { return my_stack_.top(); }
	void Pop() { my_stack_.pop(); }
	void Push(int value) { my_stack_.push(value); }
};

int MyStack::ReverseStackFunc() {
	int result = my_stack_.top();
	my_stack_.pop();
	if (my_stack_.empty()) {
		return result;
	}
	else {
		int last = ReverseStackFunc();
		my_stack_.push(result);
		return last;
	}
}

void MyStack::Reverse() {
	if (my_stack_.empty()) {
		return;
	}
	int i = ReverseStackFunc();
	Reverse();
	my_stack_.push(i);
}



int main() {
	int N;
	std::cin >> N;
	MyStack my_stack;
	int input;
	for (int i = 0; i < N; ++i) {
		std::cin >> input;
		my_stack.Push(input);
	}
	my_stack.Reverse();
	for (int i = 0; i < N; ++i) {
		std::cout << my_stack.Top()<<" ";
		my_stack.Pop();
	}
	return 0;
}