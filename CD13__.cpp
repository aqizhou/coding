//
// Created by aqizhou on 2023/4/9.
//
#include<iostream>
#include<stack>
using namespace std;

class SortStack{
protected:
    stack<int> stack_;
    stack<int> util_stack_;
public:
    void Push(int value){
        stack_.push(value);
    }
    void SortElement(){
        while(!stack_.empty()){
            int top = stack_.top();
            stack_.pop();
            if(util_stack_.empty()||util_stack_.top()>=top){
                util_stack_.push(top);
            }
            else{
                while(!util_stack_.empty()&&util_stack_.top()<top){
                    int util_stack_top = util_stack_.top();
                    util_stack_.pop();
                    stack_.push(util_stack_top);
                }
                util_stack_.push(top);
            }
        }
        while(!util_stack_.empty()){
            stack_.push(util_stack_.top());
            util_stack_.pop();
        }
    }
    void PrintStack(){
        while(!stack_.empty()) {
            cout << stack_.top() << " ";
            stack_.pop();
        }
    }
};

int main(){
    int N;
    cin>>N;
    int num;
    SortStack sort_stack;
    for(int i=0;i<N;++i){
        cin>>num;
        sort_stack.Push(num);
    }
    sort_stack.SortElement();
    sort_stack.PrintStack();
}
