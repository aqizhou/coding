//
// Created by zhouxin.aqizhou on 2023/2/23.
//
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class MaxTree {
public:
    vector<int> buildMaxTree(vector<int> A, int n) {
        vector<int> LArr(n,-1),RArr(n,-1),res(n,-1);
        stack<int> stk;

        for(int i=0;i<n;++i){
            while(!stk.empty()&&A[stk.top()]<A[i]){
                stk.pop();
            }
            if(!stk.empty()){
                LArr[i]=stk.top();
            }
            stk.push(i);
        }
        while(!stk.empty()){stk.pop();}
        for(int i=n-1;i>=0;--i){
            while(!stk.empty()&&A[stk.top()]<A[i]){
                stk.pop();
            }
            if(!stk.empty()){
                RArr[i]=stk.top();
            }
            stk.push(i);
        }
        for(int i=0;i<n;++i){
            if(LArr[i]!=-1&&RArr[i]!=-1){
                res[i]=A[LArr[i]]>A[RArr[i]]?RArr[i]:LArr[i];
            }
            else if(LArr[i]==-1){
                res[i]=RArr[i];
            }
            else {
                res[i]=LArr[i];
            }
        }
        return res;
    }
};



int main(){
    vector<int> vec{3,1,4,2};
    auto res = MaxTree().buildMaxTree(vec,vec.size());
    for(auto& r:res){
        cout<<r<<" ";
    }
}