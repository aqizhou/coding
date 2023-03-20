#include<iostream>
#include<stack>

template<class T>
class MyStack {
protected:
	std::stack<T> my_stack_;
	std::stack<T> util_stack_;
public:
	void Pop();
	void Push(const T& value);
	const T& GetMin();
};

template<class T>
void MyStack<T>::Pop() {
	util_stack_.pop();
	my_stack_.pop();
}

template<class T>
void MyStack<T>::Push(const T& value) {
	my_stack_.push(value);
	if (util_stack_.empty()|| value <= GetMin()) {
		util_stack_.push(value);
	}
	else {
		util_stack_.push(GetMin());
	}	
}

template<class T>
const T& MyStack<T>::GetMin() {
	return util_stack_.top();
}

int main() {
	MyStack<int> my_stack;
	int N;
	std::cin >> N;
	std::string input;
	int num;
	for (int i = 0; i < N; ++i) {
		std::cin >> input;
		if (input == "push") {
			std::cin >> num;
			my_stack.Push(num);
		}
		else if (input == "getMin") {
			std::cout << my_stack.GetMin()<<std::endl;
		}
		else if (input == "pop") {
			my_stack.Pop();
		}
	}
	return 0;
}