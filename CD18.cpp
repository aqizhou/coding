//
// Created by aqizhou on 2023/4/16.
//

#include<iostream>
#include<vector>
#include<deque>
using namespace std;

int SonArray(const vector<int>& vec,int num){
    int res=0;
    int i=0,j=0;
    deque<int> min_deque;
    deque<int> max_deque;
    while(i<vec.size()){
        while(j<vec.size()){
            while(!min_deque.empty()&&vec[min_deque.back()]>=vec[j]){
                min_deque.pop_back();
            }
            min_deque.push_back(j);
            while(!max_deque.empty()&&vec[max_deque.back()]<=vec[j]){
                max_deque.pop_back();
            }
            max_deque.push_back(j);
            if(vec[max_deque.front()]-vec[min_deque.front()]>num){
                break;
            }
            ++j;
        }
        res+=j-i;
        if(max_deque.front()==i){
            max_deque.pop_front();
        }
        if(min_deque.front()==i){
            min_deque.pop_front();
        }
        ++i;
    }
    return res;
};
//3+3+3+2+1
int main(){
    int n,num;
    cin>>n>>num;
    vector<int> vec;
    int input;
    for(int i=0;i<n;++i){
        cin>>input;
        vec.push_back(input);
    }
    cout<<SonArray(vec,num);
}
