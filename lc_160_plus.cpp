#include<iostream>
#include<unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class NodeManager {
protected:
    ListNode* head_=nullptr;
    ListNode* tail_= nullptr;
public:
    ListNode* head() { return head_; }
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
    ListNode* PushEnd(int val,int pos) {
        if (!head_) {
            head_ = new ListNode(val);
            head_->next = head_;
            return head_;
        }
        else {
            ListNode* new_node = new ListNode(val);
            tail_->next = new_node;

            tail_ = head_;
            while (--pos) {
                tail_ = tail_->next;
            }
            new_node->next = tail_;
            return tail_;
        }
    }
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* loopA,ListNode* headB,ListNode* loopB) {
        if (headA == nullptr || headB == nullptr) { return nullptr; }
        std::unordered_set<ListNode*> A_set;
        bool pass = false;
        while (!pass || headA != loopA) {//只经过一次环的入口
            if (headA == loopA) {
                pass = true;
            }
            A_set.emplace(headA);
            headA = headA->next;
        }
        pass = false;
        while (!pass||headB!=loopB) {
            if (A_set.count(headB)) {
                return headB;
            }
            if (headB == loopB) {
                pass = true;
            }
            headB = headB->next;
        }
        return nullptr;
    }
};

int main() {
    int N;
    cin >> N;
    int val,pos;
    NodeManager mgr1;
    for (int i = 0; i < N; ++i) {
        cin >> val;
        mgr1.PushBack(val);
    }
    cin >> val>>pos;
    ListNode* loop1 = mgr1.PushEnd(val,pos);
    ListNode* head1 = mgr1.head();

    int M;
    cin >> M;
    NodeManager mgr2;
    for (int i = 0; i < M; ++i) {
        cin >> val;
        mgr2.PushBack(val);
    }
    cin >> val >> pos;
    ListNode* loop2 = mgr2.PushEnd(val, pos);
    ListNode* head2 = mgr2.head();

    Solution sol;
    sol.getIntersectionNode(head1, loop1, head2, loop2);
}

//不太好模拟，主要是不知道怎么让两条链表入一个环