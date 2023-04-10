//
// Created by aqizhou on 2023/4/10.
//
#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;

class HanNuoTa{
    enum State{
        kNone,
        kL2M,
        kM2L,
        kM2R,
        kR2M
    };
protected:
    int cnt_;
    stack<int> left_stack_;
    stack<int> mid_stack_;
    stack<int> right_stack_;
public:
    HanNuoTa(){
        left_stack_.push(13);
        mid_stack_.push(13);
        right_stack_.push(13);
        cnt_=0;
    }
    ~HanNuoTa(){printf("It will move %d steps.",cnt_);}
    void Move(int N){
        for(int i=N;i>0;--i){
            left_stack_.push(i);
        }
        State s=kNone;
        while(right_stack_.size()<N+1){
            cnt_+= _FTMove(s,kL2M,kM2L,mid_stack_,left_stack_);
            cnt_+= _FTMove(s,kM2L,kL2M,left_stack_,mid_stack_);
            cnt_+= _FTMove(s,kM2R,kR2M,right_stack_,mid_stack_);
            cnt_+= _FTMove(s,kR2M,kM2R,mid_stack_,right_stack_);
        }

    }
protected:
    int _FTMove(State& s,State pre,State current,stack<int>& from,stack<int>& to){
        if(s!=pre&&from.top()<to.top()){
            string f,t;
            int top = from.top();
            from.pop();
            to.push(top);
            s=current;
            switch(current){
                case kL2M:{f="left";t="mid";}break;
                case kM2L:{f="mid";t="left";}break;
                case kM2R:{f="mid";t="right";}break;
                case kR2M:{f="right";t="mid";}break;
            }
            printf("Move %d from %s to %s\n",top,f.c_str(),t.c_str());
            return 1;
        }
        return 0;
    }
};

int main(){
    int N;
    cin>>N;
    HanNuoTa hanno_ta;
    hanno_ta.Move(N);
}