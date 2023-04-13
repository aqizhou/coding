////
//// Created by aqizhou on 2023/4/12.
////
//
//#include <iostream>
//#include<queue>
//#include <array>
//using namespace std;
//
//class MaxOfRectangle{
//public:
//    MaxOfRectangle(int width){
//        width_=width;
//        cnt_=0;
//
//    }
//protected:
//    queue<int> queue_;
//    array<int,1000000> array_max_;
//    int width_;
//    int cnt_;
//    int max_;
//public:
//    void Push(int value){
//        queue_.push(value);
//        ++cnt_;
//        if(queue_max_.empty()||cnt_%width_==0){
//            max_=value;
//            queue_max_.push(value);
//        }
//        else{
//            max_=max_<value?value:max_;
//            queue_max_.push(max_);
//        }
//    }
//    int MaxValue(int i) {
//
//    }
//};
//
//int main(){
//    int n,w;
//    cin>>n>>w;
//    int value;
//    MaxOfRectangle max_of_rectangle(w);
//    for(int i=0;i<n;++i){
//        cin>>value;
//        max_of_rectangle.Push(value);
//        if(i>=w-1){
//            cout<<max_of_rectangle.MaxValue(i)<<" ";
//        }
//    }
//}

#include<iostream>
#include<deque>
using namespace std;

class MaxOfRectangle{
protected:
    deque<int> max_queue_;
    int width_;
public:
    MaxOfRectangle(int width){width_=width;}
    void CalculateMax(int arr[],int size){
        for(int i=0;i<size;++i){
            if(max_queue_.empty()||arr[max_queue_.back()]>=arr[i]){
                max_queue_.push_back(i);
            }
            else{
                while(!max_queue_.empty()&&arr[max_queue_.back()]<arr[i]){
                    max_queue_.pop_back();
                }
                max_queue_.push_back(i);
            }
            if(max_queue_.front()==i-width_){
                max_queue_.pop_front();
            }
            if(i>=width_-1){
                cout<<arr[max_queue_.front()]<<" ";
            }
        }

    }
};

int main(){
    int n,w;
    cin>>n>>w;
    int* arr = new int[n];
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    MaxOfRectangle max_of_rectangle(w);
    max_of_rectangle.CalculateMax(arr,n);
    return 0;
}

