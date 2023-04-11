//
// Created by aqizhou on 2023/4/11.
//

#include<iostream>
#include<cstdio>
using namespace std;

class HanNuoTa{
protected:
    int cnt_=0;
public:
    ~HanNuoTa(){printf("It will move %d steps.",cnt_);}
    void Move(int i,string from,string to){
        printf("Move %d from %s to %s\n",i,from.c_str(),to.c_str());
        ++cnt_;
    }
    void HanNuoRecursion(int n,string from,string pass,string to){
        if(n==1){
            Move(n,from,pass);
            Move(n,pass,to);
            return;
        }
        HanNuoRecursion(n-1,from,pass,to);
        Move(n,from,pass);
        HanNuoRecursion(n-1,to,pass,from);
        Move(n,pass,to);
        HanNuoRecursion(n-1,from,pass,to);
    }
};

int main(){
    int N;
    cin>>N;
    HanNuoTa han_nuo_ta;
    han_nuo_ta.HanNuoRecursion(N,"left","mid","right");
}
