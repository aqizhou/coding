//
// Created by aqizhou on 2023/2/23.
//
#include <iostream>
#include<list>
using namespace std;

void ListPublicPart(const list<int>& a,const list<int>&b){
    list<int>::const_iterator iter1=a.begin();
    list<int>::const_iterator iter2=b.begin();
    while(iter1!=a.end()&&iter2!=b.end()){
        if(*iter1<*iter2){
            ++iter1;
        }
        else if(*iter1>*iter2){
            ++iter2;
        }
        else{
            cout<<*iter1<<" ";
            ++iter1;
            ++iter2;
        }

    }
};

int main(){
    int n1,n2;
    list<int> l1,l2;
    cin>>n1;
    int temp;
    while(n1--){
        cin>>temp;
        l1.push_back(temp);
    }
    cin>>n2;
    while(n2--){
        cin>>temp;
        l2.push_back(temp);
    }
    ListPublicPart(l1,l2);

}