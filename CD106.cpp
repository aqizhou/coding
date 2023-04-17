//
// Created by aqizhou on 2023/4/17.
//

#include<iostream>
using namespace std;

struct Node{
    int value;
    Node* next;
};

class NodeManager{
protected:
    Node* head_;
    Node* tail_;
    int size_;
public:
    NodeManager(){
        head_  = new Node;
        head_->next= nullptr;
        tail_ = new Node;
        tail_->next=nullptr;
        size_=0;
    }
    void PushBack(int v){
        ++size_;
        Node* new_node = new Node;
        new_node->next= nullptr;
        new_node->value=v;
        Node* temp=head_;
//        while(temp->next){
//            temp=temp->next;
//        }
//        temp->next=new_node;
        if(!head_->next){
            head_->next=new_node;
            tail_=new_node;
        }
        else{
            tail_->next=new_node;
            tail_=new_node;
        }

    }
    void DeleteNode(int pos){
        if(pos<size_){
            Node* temp=head_;
            while(--pos){
                temp=temp->next;
                cout<<temp->value<<" ";
            }
            Node* t_temp = temp->next;
            temp->next=t_temp->next;
            delete t_temp;
            temp=temp->next;
            while(temp){
                cout<<temp->value<<" ";
                temp=temp->next;
            }
        }
    }
    void Print(){
        Node* temp=head_->next;
        while(temp){
            cout<<temp->value<<" ";
            temp=temp->next;
        }
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    NodeManager node_manager;
    int value;
    for(int i=0;i<n;++i){
        cin>>value;
        node_manager.PushBack(value);
    }
    node_manager.DeleteNode(m);
    //node_manager.Print();
}
