//
// Created by aqizhou on 2023/2/20.
//

#include<iostream>
#include<stack>
#include <cassert>

//设计getMin功能的栈
//1.0
class MyStack{
private:
    std::stack<int> stk1;
    std::stack<int> stk2;
    int min;
    bool flag;
public:
    MyStack(){
        flag=true;
    }
    int getMin(){
        return min;
    }
    void Push(int num){
        stk1.push(num);
        if(flag){
            min=num;
            flag=false;
        }
        else{
            min=min<num?min:num;
        }
        if(stk2.empty()||stk2.top()>=min&&min==num){
            stk2.push(min);
        }
    }
    void Pop(){
        assert(!(stk2.empty()&&stk1.empty()));
        if(stk2.top()==stk1.top()){
            stk2.pop();
            if(!stk2.empty()){
                min=stk2.top();
            }
            else{
                flag=true; //此时stk2栈为空，flag标志重新置为true
            }
        }
        stk1.pop();
    }
};

//2.0
class MyStack2{
private:
    std::stack<int> stk1;
    std::stack<int> stk2;
public:
    int getMin(){
        return stk2.top();
    }
    void Push(int num){
        stk1.push(num);
        if(stk2.empty()||stk2.top()>=num){
            stk2.push(num);
        }
    }
    void Pop(){
        assert(!(stk2.empty()&&stk1.empty()));
        if(stk2.top()==stk1.top()){
            stk2.pop();
        }
        stk1.pop();
    }
};

//方法2
class MyStack3{
private:
    std::stack<int> stk1;
    std::stack<int> stk2;
public:
    int getMin(){
        return stk2.top();
    }
    void Push(int num){
        stk1.push(num);
        if(stk2.empty()||stk2.top()>=num){
            stk2.push(num);
        }else{//stk2.top()<num
            int top = stk2.top();
            stk2.push(top);
        }
    }
    void Pop(){
        assert(!(stk2.empty()&&stk1.empty()));
        stk1.pop();
        stk2.pop();
    }
};


int main(){
    //MyStack mstk;
    //MyStack2 mstk;
    MyStack3 mstk;
    int N;
    std::cin>>N;
    while(N){
        std::string S;
        std::cin>>S;
        if(S=="push"){
            int num;
            std::cin>>num;
            mstk.Push(num);
        }
        else if(S=="pop"){
            mstk.Pop();
        }
        else if(S=="getMin"){
            int res;
            res = mstk.getMin();
            std::cout<<res<<std::endl;
        }

        --N;
    }
    return 0;
}
