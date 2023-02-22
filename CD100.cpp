//
// Created by aqizhou on 2023/2/21.
//
#include<queue>
#include<vector>
#include <iostream>
using namespace std;

class Pet{
private:
    string type;
public:
    Pet(string t){
        type=t;
    }
    string GetPetType() {
        return type;
    }
};

class Dog:public Pet{
public:
    Dog():Pet("dog"){}
};

class Cat:public Pet{
public:
    Cat():Pet("cat"){}
};


class PetEnterQueue{
private:
    Pet* pet;
    int num;
    int cnt;
public:
    PetEnterQueue(Pet* p,int n,int c):pet(p){
        num=n;
        cnt=c;
    }
    Pet* GetPet()const{return pet;}
    int GetNum()const{return num;}
    int GetCnt()const{return cnt;}
};

class CatDogQueue{
private:
    queue<PetEnterQueue> DogQue;
    queue<PetEnterQueue> CatQue;
    int cnt;
public:
    CatDogQueue(){cnt=0;}
    void add(string pet,int time){
        if(pet=="cat"){
            CatQue.push(PetEnterQueue(new Cat,time,cnt++));
        }
        else{
            DogQue.push(PetEnterQueue(new Dog,time,cnt++));
        }
    }
    void pollAll(){
        if(DogQue.empty()&&CatQue.empty()){return;}
        else if(DogQue.empty()){
            pollCat();
        }
        else if(CatQue.empty()){
            pollDog();
        }
        else{
            while(CatQue.size()&&DogQue.size()) {
                if (CatQue.front().GetCnt() > DogQue.front().GetCnt()) {
                    PetEnterQueue temp = DogQue.front();
                    cout << temp.GetPet()->GetPetType() << " " << temp.GetNum() << endl;
                    DogQue.pop();
                }
                else{
                    PetEnterQueue temp = CatQue.front();
                    cout<<temp.GetPet()->GetPetType()<<" "<<temp.GetNum()<<endl;
                    CatQue.pop();
                }
            }
            if(CatQue.size()){pollCat();}
            if(DogQue.size()){pollDog();}
        }
    }

    void pollCat(){
        while(CatQue.size()){
            PetEnterQueue temp = CatQue.front();
            cout<<temp.GetPet()->GetPetType()<<" "<<temp.GetNum()<<endl;
            CatQue.pop();
        }
    }
    void pollDog(){
        while(DogQue.size()){
            PetEnterQueue temp = DogQue.front();
            cout<<temp.GetPet()->GetPetType()<<" "<<temp.GetNum()<<endl;
            DogQue.pop();
        }
    }
    bool isEmpty(){return DogQue.empty()&&CatQue.empty();}
    bool isDogEmpty(){return DogQue.empty();}
    bool isCatEmpty(){return CatQue.empty();}
    void printYN(bool b){
        if(b){
            cout<<"yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }
    }

};

int main(){
    CatDogQueue q;
    int N;
    cin>>N;
    for(int i=0;i<N;++i){
        string in;
        cin>>in;
        if(in=="add"){
            string pet;
            cin>>pet;
            int num;
            cin>>num;
            q.add(pet,num);
        }
        else if(in=="pollAll"){
            q.pollAll();
        }
        else if(in=="pollCat") {
            q.pollCat();
        }
        else if(in=="pollDog"){
            q.pollDog();
        }
        else if(in=="isEmpty"){
            q.printYN(q.isEmpty());
        }
        else if(in=="isDogEmpty"){
            q.printYN(q.isDogEmpty());
        }
        else if(in=="isCatEmpty"){
            q.printYN(q.isCatEmpty());
        }

    }
}
