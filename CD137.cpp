#include<iostream>
#include<unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Mgr {
protected:
    ListNode* head_ = nullptr;
    ListNode* tail_ = nullptr;
public:
    ListNode* head() { return head_; }
public:
    void PushBack(int val) {
        if (!head_) {
            head_ = new ListNode(val);
            tail_ = head_;
        }
        else {
            ListNode* new_node = new ListNode(val);
            tail_->next = new_node;
            tail_ = new_node;
        }
    }
    void DeleteRepeatNode() {
        tail_ = head_;
        unordered_set<int> set;
        ListNode *pre=nullptr,*next = nullptr;
        while (tail_) {
            next = tail_->next;
            if (set.empty()||set.count(tail_->val)==0) {
                set.emplace(tail_->val); 
                pre = tail_;
            }
            else {
                pre->next = next;
            }
            tail_ = next;
        }
    }
    void PrintList() {
        while (head_) {
            cout << head_->val << " ";
            head_ = head_->next;
        }
    }
};

int main() {
    int num,val;
    cin >> num;
    Mgr mgr;
    for (int i = 0; i < num; ++i) {
        cin >> val;
        mgr.PushBack(val);
    }
    mgr.DeleteRepeatNode();
    mgr.PrintList();
}