//
// Created by zhouxin.aqizhou on 2023/2/22.
//
#include<iostream>
#include <cstdio>
using namespace std;

class HanNoTa{
private:int cnt;
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

int main(){
    HanNoTa h;
    int N;
    cin>>N;
    h.hanNoTa(N,"left","mid","right");

}