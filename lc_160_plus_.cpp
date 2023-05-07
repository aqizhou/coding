#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* loopA, ListNode* headB, ListNode* loopB) {
        ListNode* pA = headA, * pB = headB;
        if (loopA == loopB) {
            while (pA != pB) {
                pA = pA != loopA ? pA->next : headB;
                pB = pB != loopB ? pB->next : headA;
                if (pA == pB) {
                    return pA;
                }
            }
        }
        else {
            pA = pA->next;
            while (pA != loopA) {
                if (pA == loopB) {
                    return pA;
                }
                pA = pA->next;
            }
            return nullptr;
        }
    }
};