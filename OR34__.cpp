//
// Created by aqizhou on 2023/4/13.
//
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

/*
 * 8
340 1387 2101 847 1660 733 36 528
 */

class MakeMaxTree{
protected:
    int N;
    stack<int> stack_;
    vector<int> left_array_;
    vector<int> right_array_;
public:
    MakeMaxTree(int n){N=n;}
    void BuildMaxTree(int arr[]){
        left_array_=vector<int>(N,-1);
        right_array_=vector<int>(N,-1);
        for(int i=0;i<N;++i){
            while(!stack_.empty()&&arr[stack_.top()]<arr[i]){
                stack_.pop();
            }
            if(!stack_.empty()){
                left_array_[i]=stack_.top();
            }
            stack_.push(i);
        }
        while(!stack_.empty()){
            stack_.pop();
        }
        for(int i=N-1;i>=0;--i){
            while(!stack_.empty()&&arr[stack_.top()]<arr[i]){
                stack_.pop();
            }
            if(!stack_.empty()){
                right_array_[i]=stack_.top();
            }
            stack_.push(i);
        }
        vector<int> res= vector<int>(N,-1);
        for(int i=0;i<N;++i){
            if(left_array_[i]!=-1&&right_array_[i]!=-1){
                res[i]=arr[left_array_[i]]<arr[right_array_[i]]?left_array_[i]:right_array_[i];
            }
            else if(left_array_[i]==-1){
                res[i]=right_array_[i];
            }
            else if(right_array_[i]==-1){
                res[i]=left_array_[i];
            }
            cout<<res[i]<<" ";
        }

    };
};

int main(){
    int N;
    cin>>N;
    int* arr = new int[N];
    for(int i=0;i<N;++i){
        cin>>arr[i];
    }
    MakeMaxTree max_tree(N);
    max_tree.BuildMaxTree(arr);
}