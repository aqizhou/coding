//
// Created by aqizhou on 2023/4/5.
//

#include<iostream>
#include<stack>
using namespace std;


class MyStack{
protected:
    stack<int> stack_;
    stack<int> util_stack_;
public:
    void Pop();
    void Push(int input);
    int GetMin();
};

void MyStack::Pop() {
    stack_.pop();
    util_stack_.pop();
}

void MyStack::Push(int input){
    stack_.push(input);
    if(util_stack_.empty()||input<util_stack_.top()){
        util_stack_.push(input);
    }
    else {
        util_stack_.push(util_stack_.top());
    }
}

int MyStack::GetMin() {
    return util_stack_.top();
}

/////////////////////////////////////////////////////
class MyStack2{
protected:
    stack<int> stack_;
    stack<int> util_stack_;
public:
    void Pop();
    void Push(int input);
    int GetMin();
};

void MyStack2::Pop(){
    if(stack_.top()==util_stack_.top()){
        util_stack_.pop();
    }
    stack_.pop();
}

void MyStack2::Push(int input) {
    stack_.push(input);
    if(util_stack_.empty()||util_stack_.top()>=input){
        util_stack_.push(input);
    }
}

int MyStack2::GetMin() {
    return util_stack_.top();
}

int main(){
    int N;
    cin>>N;
    string input;
    int value;
    //MyStack my_stack;
    MyStack2 my_stack;
    for(int i=0;i<N;++i){
        cin>>input;
        if(input=="push"){
            cin>>value;
            my_stack.Push(value);
        }
        else if(input=="pop"){
            my_stack.Pop();
        }
        else if(input=="getMin"){
            cout<<my_stack.GetMin()<<endl;
        }
    }

}