//
// Created by aqizhou on 2023/4/8.
//
#include<iostream>
#include<queue>
using namespace std;
enum type{
    cat,
    dog
};

class Animal{
protected:
    int time_;
    int id_;
    char type_;
};

class Cat:public Animal{

};
class Dog:public Animal{};

class AnimalManage{
    struct AnimalInfo{
        int time;
        int id;
    };
protected:
    queue<AnimalInfo> cat_queue_;
    queue<AnimalInfo> dog_queue_;
public:
    void Add(int time,char type,int id);
    bool IsEmpty(){return dog_queue_.empty()&&cat_queue_.empty();}
    bool IsDogEmpty(){return dog_queue_.empty();}
    bool IsCatEmpty(){return cat_queue_.empty();}
    void PollAll();
    void PollDog();
    void PollCat();

};

void AnimalManage::Add(int time,char type,int id){
    AnimalInfo animal_info = {time,id};
    if(type==cat) {
        cat_queue_.push(animal_info);
    }
    else if(type==dog){
        dog_queue_.push(animal_info);
    }
}

void AnimalManage::PollAll() {
    if(cat_queue_.empty()){
        PollDog();
    }
    else if(dog_queue_.empty()){
        PollCat();
    }
    else{
        while(!cat_queue_.empty()&&!dog_queue_.empty()){
            bool res = cat_queue_.front().time<dog_queue_.front().time;
            if(res) {
                cout<<"cat "<<cat_queue_.front().id<<endl;
                cat_queue_.pop();
            }
            else{
                cout<<"dog "<<dog_queue_.front().id<<endl;
                dog_queue_.pop();
            }
        }
        PollCat();
        PollDog();
    }
}

void AnimalManage::PollCat() {
    while(!cat_queue_.empty()){
        cout<<"cat "<<cat_queue_.front().id<<endl;
        cat_queue_.pop();
    }
}

void AnimalManage::PollDog() {
    while(!dog_queue_.empty()){
        cout<<"dog "<<dog_queue_.front().id<<endl;
        dog_queue_.pop();
    }
}

int main(){
    int N;
    cin>>N;
    string cmd;
    string animal;
    int id;
    int time=0;
    AnimalManage animal_manager;
    for(int i=0;i<N;++i){
        cin>>cmd;
        if(cmd=="add"){
            cin>>animal>>id;
            if(animal=="cat"){
                animal_manager.Add(time++,cat,id);
            }
            else if(animal=="dog"){
                animal_manager.Add(time++,dog,id);
            }
        }
        else if(cmd=="pollAll"){
            animal_manager.PollAll();
        }
        else if(cmd=="pollDog"){
            animal_manager.PollDog();
        }
        else if(cmd=="pollCat"){
            animal_manager.PollCat();
        }
        else if(cmd=="isEmpty"){
            if(animal_manager.IsEmpty()){
                cout<<"yes"<<endl;
            }
            else{
                cout<<"no"<<endl;
            }
        }
        else if(cmd=="isDogEmpty"){
            if(animal_manager.IsDogEmpty()){
                cout<<"yes"<<endl;
            }
            else{
                cout<<"no"<<endl;
            }
        }
        else if(cmd=="isCatEmpty"){
            if(animal_manager.IsCatEmpty()){
                cout<<"yes"<<endl;
            }
            else{
                cout<<"no"<<endl;
            }
        }
    }
}
