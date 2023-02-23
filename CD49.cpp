//
// Created by aqizhou on 2023/2/23.
//

#include <iostream>
using namespace std;

struct node{
    struct node* next;
    int value;
};


int main(){
    int n,k;
    node* l=new node;
    node* temp=l;
    l->value=-1;
    l->next=nullptr;
    int v;
    cin>>n>>k;
    if(k>n)return -1;
    int num1=n;
    while(num1--){
        cin>>v;
        node*newNode = new node;
        newNode->value=v;
        temp->next=newNode;
        temp=newNode;
        temp->next=nullptr;
    }
    temp=l->next;
//    while(temp){
//        cout<<temp->value<<" ";
//        temp=temp->next;
//    }
    int num2=n-k;
    while(num2-1>0){
        temp=temp->next;
        --num2;
    }
    node* temp2=temp->next;
    if(temp2){
        temp->next=temp2->next;
        delete temp2;
    }
    else{
        delete temp;
        return 0;
    }
    temp=l->next;
    while(temp){
        cout<<temp->value<<" ";
        temp=temp->next;
    }


}