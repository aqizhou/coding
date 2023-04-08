//
// Created by aqizhou on 2023/4/7.
//

#include<iostream>
#include<stack>
using namespace std;

class ReverseStack{
protected:
    stack<int> value_stack_;
public:
    int Top(){return value_stack_.top();}
    void Pop(){value_stack_.pop();}
    bool IsEmpty(){return value_stack_.empty();}
    int Reverse();
    void ManageReverse();
    void Push(int value){value_stack_.push(value);}

};

int ReverseStack::Reverse() {
    int value = value_stack_.top();
    value_stack_.pop();
    if(value_stack_.empty()){
        return value;
    }
    else{
        int last = Reverse();
        value_stack_.push(value);
        return last;
    }
}

void ReverseStack::ManageReverse(){
    if(value_stack_.empty()){
        return;
    }
    int i = Reverse();
    ManageReverse();
    value_stack_.push(i);
}

int main(){
        int N;
        cin>>N;
        int value;
        ReverseStack reverse_stack;
        for(int i=0;i<N;++i){
            cin>>value;
            reverse_stack.Push(value);
        }
        reverse_stack.ManageReverse();
        while(!reverse_stack.IsEmpty()){
            cout<<reverse_stack.Top()<<endl;
            reverse_stack.Pop();
        }
}