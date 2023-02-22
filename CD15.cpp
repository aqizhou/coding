//
// Created by aqizhou on 2023/2/22.
//
#include<iostream>
#include<deque>
using namespace std;

class CreateMaxArray{
private:
    deque<int> dq;
public:
    int* createMaxArray(int n,int w,int* arr){
        int* res = new int[n-w+1];
        int index=0;
        for(int i=0;i<n;++i){
            if(dq.empty()||arr[dq.back()]>=arr[i]){
                dq.push_back(i);
            }
            else{
                while(!dq.empty()&&arr[dq.back()]<arr[i]){
                    dq.pop_back();
                }
                dq.push_back(i);
            }

            if(dq.front()==i-w){dq.pop_front();}
            if(i+1-w>=0){
                res[index++]=arr[dq.front()];
            }
        }
        return res;
    }


};

int main(){
    CreateMaxArray MaxArray;
    int n,w;
    cin>>n>>w;
    int* arr = new int[n];
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    int* res = MaxArray.createMaxArray(n,w,arr);
    for(int i=0;i<n-w+1;++i){
        cout<<res[i]<<" ";
    }



}
