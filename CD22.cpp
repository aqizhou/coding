//
// Created by zhouxin.aqizhou on 2023/2/22.
//
#include<iostream>
#include <cstdio>
#include<stack>
using namespace std;

//方法1 递归
class HanNoTa{
private:
    int cnt;
public:
    HanNoTa(){
        cnt=0;
    }
    ~HanNoTa(){
        printf("It will move %d steps.",cnt);
    }
    void Move(int n,string from,string to){
        printf("Move %d from %s to %s\n",n,from.c_str(),to.c_str());
        ++cnt;
    }
    void hanNoTa(int n,string left,string mid,string right){
        if(n==1){
            Move(1,left,mid);
            Move(1,mid,right);
            return;
        }
        else{
            hanNoTa(n-1,left,mid,right);
            Move(n,left,mid);
            hanNoTa(n-1,right,mid,left);
            Move(n,mid,right);
            hanNoTa(n-1,left,mid,right);
        }
    }
};

//方法2 3个栈
class HanNoTa2{
    enum state{none,l2m,m2l,m2r,r2m};
private:
    int cnt;
    stack<int> LeftStack,MidStack,RightStack;
public:
    HanNoTa2(){
        cnt=0;
        LeftStack.push(13);//题目最大输入为12
        MidStack.push(13);//题目最大输入为12
        RightStack.push(13);//题目最大输入为12
    }
    ~HanNoTa2(){
        printf("It will move %d steps.",cnt);
    }
    void hanNoTa(int N,string left,string mid,string right){
        for(int i=N;i>0;--i){
            LeftStack.push(i);
        }
        state record=state::none;
        while(RightStack.size()<N+1){
            cnt +=FTStack(record,state::l2m,state::m2l,MidStack,LeftStack,mid,left);
            cnt +=FTStack(record,state::m2l,state::l2m,LeftStack,MidStack,left,mid);
            cnt +=FTStack(record,state::m2r,state::r2m,RightStack,MidStack,right,mid);
            cnt +=FTStack(record,state::r2m,state::m2r,MidStack,RightStack,mid,right);
        }
    }
    int FTStack(state& s,state prev,state cur,stack<int>& FStack,stack<int>& TStack,string from,string to){
        if(s!=prev&&FStack.top()<TStack.top()){
            int temp = FStack.top();
            TStack.push(temp);
            FStack.pop();
            printf("Move %d from %s to %s\n",temp,from.c_str(),to.c_str());
            s=cur;
            return 1;
        }
        return 0;
    }



};

int main(){
//    HanNoTa h;
//    int N;
//    cin>>N;
//    h.hanNoTa(N,"left","mid","right");

    HanNoTa2 h;
    int N;
    cin>>N;
    h.hanNoTa(N,"left","mid","right");

}
