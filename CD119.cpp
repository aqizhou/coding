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
    ListNode* ReversePartList(stack<ListNode*>& stk, ListNode* last_node, ListNode* next_node) {
        ListNode* cur = nullptr, * pre = nullptr;
        cur = stk.top();
        stk.pop();
        if (last_node) {
            last_node->next = cur;
        }
        while (!stk.empty()) {
            pre = cur;
            cur = stk.top();
            stk.pop();
            pre->next = cur;
        }
        cur->next = next_node;
        return cur;
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
        ListNode* temp = mgr.head();
        ListNode* res_head = nullptr;
        ListNode* part_head = nullptr;
        stack<ListNode*> stk;
        while (temp) {
            if (stk.size() < K) {
                stk.push(temp);
                temp = temp->next;
            }
            if (stk.size() == K) {
                res_head = res_head == nullptr ? stk.top() : res_head;
                part_head = mgr.ReversePartList(stk, part_head, temp);
            }
        }
        mgr.PrintList(res_head);
    }
    return 0;
}