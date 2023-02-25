//
// Created by zhouxin.aqizhou on 2023/2/24.
//
#include <vector>
#include<iostream>
#include <stack>
using namespace std;

//方法1
int MaxMatrix(const vector<vector<int>>& vec){
    vector<vector<int>> tongji(vec.size(),vector<int>(vec[0].size(),0));
    for(int i=0;i<vec.size();++i){
        for(int j=0;j<vec[0].size();++j){
            if(vec[i][j]==1){
                tongji[i][j]=(j==0?0:tongji[i][j-1])+1;
            }
        }
    }
    int res=0;
    for(int i=0;i<vec.size();++i){
        int area,width;
        for(int j=0;j<vec[0].size();++j) {
            if(vec[i][j]==0){
                continue;
            }
            int temp=tongji[i][j];
            area=temp,width=temp;
                for(int k=i-1;k>=0;k--){
                    width = min(width,tongji[k][j]);
                    area = max(area,width*(i-k+1));
                }
                res=max(res,area);
            }
        }
    return res;
}


//方法2 单调栈
int MaxOfLine(const vector<int>& vec){
    stack<int> stk;
//    vector<int> leftValue(vec.size(),0);
    int index,k,width=0,res=0;
    for(int i=0;i<vec.size();++i){
        while(!stk.empty()&&vec[stk.top()]>=vec[i]){
            index=stk.top();
            stk.pop();
            k=stk.empty()?-1:stk.top();
            res=max(res,vec[index]*(i-k-1));
        }
        stk.push(i);
    }
    while(!stk.empty()){
        index=stk.top();
        stk.pop();
        k=stk.empty()?-1:stk.top();
        int len=vec.size();
        res=max(res,vec[index]*(len-k-1));
    }
    return res;
}

int MaxMatrix2(const vector<vector<int>>& vec) {
    int res=0;
    vector<int> EveryColumnValue(vec[0].size(),0);
    for(int i=0;i<vec.size();++i){
        for(int j=0;j<vec[0].size();++j){
            EveryColumnValue[j]=vec[i][j]==0?0:EveryColumnValue[j]+1;
        }
        res = max(res,MaxOfLine(EveryColumnValue));
    }
    return res;
}



int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> vec;
    for(int i=0;i<n;++i){
        int input;
        vector<int> temp={};
        for(int j=0;j<m;++j){
            cin>>input;
            temp.push_back(input);
        }
        vec.push_back(temp);
    }
//    for(auto& v:vec){
//        for(auto& x:v){
//            cout<<x<<" ";
//        }
//        cout<<endl;
//    }
   cout<<MaxMatrix(vec);
    //cout<<MaxMatrix2(vec);
}


