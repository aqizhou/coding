#include<iostream>
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
    ListNode* ReversePartList(ListNode* last_node,ListNode* start,ListNode* end,ListNode* next_node) {
        ListNode* cur = start, * pre = last_node,*next=nullptr;
        if (!last_node) {
            pre = new ListNode(-1);
            pre->next = cur;
        }
        else {
            pre = last_node;
        }
        while (1) {
            next = cur->next;
            if (next == next_node) { break; }
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }
        start->next = next_node;
        return start;
    }
    void PrintList(ListNode* temp) {
        while (temp) {
            cout << temp->val << " ";
            temp = temp->next;
        }
    }
};

int main() {
    int num, K, val;
    cin >> num;
    Mgr mgr;
    for (int i = 0; i < num; ++i) {
        cin >> val;
        mgr.PushBack(val);
    }
    cin >> K;
    if (K < 2) {
        auto res_head = mgr.head();
        mgr.PrintList(res_head);
        return 0;
    }
    else {
        ListNode* cur = mgr.head();
        ListNode* res_head = nullptr;
        ListNode* part_head = nullptr;
        ListNode* start = nullptr;
        int cnt = 0;
        while (cur) {
            start = start == nullptr ? cur : start;
            while (++cnt == K) {
                res_head = res_head==nullptr ? cur :res_head;
                part_head = mgr.ReversePartList(part_head, start, cur, cur->next);
                cur = start;
                start = nullptr;
                cnt = 0;
                break;
            }
            cur = cur->next;
        }
        mgr.PrintList(res_head);
    }
    return 0;
}