//
// Created by zhouxin.aqizhou on 2023/2/22.
//

#include<iostream>
#include<stack>
using namespace std;

class ReverseStack{
private:
    stack<int> stk1;
    stack<int> stk2;
public:
    void Push(int num){
        stk1.push(num);
    }
    void Reverse(int total){
        while(stk2.size()<total){
            int out=stk1.top();
            stk1.pop();
            if(stk2.empty()||stk2.top()>=out){
                stk2.push(out);
            }
            else{
                while(!stk2.empty()&&stk2.top()<out){
                    int temp=stk2.top();
                    stk2.pop();
                    stk1.push(temp);
                }
                stk2.push(out);
            }
        }
        while(stk2.size()){
            int temp=stk2.top();
            stk1.push(temp);
            stk2.pop();
        }
        while(stk1.size()){
            cout<<stk1.top()<<" ";
            stk1.pop();
        }

    }

};

int main(){
    ReverseStack stk;
    int N;
    cin>>N;
    for(int i=0;i<N;++i){
        int in;
        cin>>in;
        stk.Push(in);
    }
    stk.Reverse(N);
}

