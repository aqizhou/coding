#include<iostream>
#include<stack>
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
    ListNode* DeleteSpecifiedNode(int specified_val) {
        tail_ = head_;
        stack<ListNode*> stk;
        while (tail_) {
            if (tail_->val != specified_val) {
                stk.push(tail_);
            }
            tail_ = tail_->next;
        }
        while (!stk.empty()) {
            ListNode* top = stk.top();
            top->next = tail_;
            tail_ = top;
            stk.pop();
        }
        return tail_;
    }
    void PrintList(ListNode* head) {
        while (head) {
            cout << head->val << " ";
            head = head->next;
        }
    }
};

int main() {
    int num, val;
    cin >> num;
    Mgr mgr;
    for (int i = 0; i < num; ++i) {
        cin >> val;
        mgr.PushBack(val);
    }
    int delete_val;
    cin >> delete_val;
    ListNode* res = mgr.DeleteSpecifiedNode(delete_val);
    mgr.PrintList(res);
}