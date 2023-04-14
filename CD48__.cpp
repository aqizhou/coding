//
// Created by aqizhou on 2023/4/15.
//

#include<iostream>
using namespace std;

struct node{
    int value;
    node* next;
};

void GetPublicPart(node* head1,int m,node* head2,int n){
    int size = m>n?n:m;
    int* public_part = new int[size];
    node* temp1 = head1->next;
    node* temp2 = head2->next;
    int i=0;
    while(temp1&&temp2){
        if(temp1->value<temp2->value){
            temp1=temp1->next;
        }
        else if(temp1->value>temp2->value){
            temp2=temp2->next;
        }
        else{
            public_part[i++]=temp1->value;
            temp1=temp1->next;
            temp2=temp2->next;
        }
    }
    for(int j=0;j<i;++j){
        cout<<public_part[j]<<" ";
    }
};

int main(){
    int m;
    cin>>m;
    node* head1 = new node;
    node* temp=head1;
    for(int i=0;i<m;++i){
        node* new_node = new node;
        cin>>new_node->value;
        new_node->next= nullptr;
        temp->next=new_node;
        temp=new_node;
    }
    int n;
    cin>>n;
    node* head2 = new node;
    temp=head2;
    for(int i=0;i<n;++i){
        node* new_node = new node;
        cin>>new_node->value;
        new_node->next= nullptr;
        temp->next=new_node;
        temp=new_node;
    }
    GetPublicPart(head1,m,head2,n);
}