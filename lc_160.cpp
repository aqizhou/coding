#include<unordered_set>

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
 };
 
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (headA == nullptr || headB == nullptr) { return nullptr; }
        std::unordered_set<ListNode*> A_set;
        while (headA) {
            A_set.emplace(headA);
            headA = headA->next;
        }
        while (headB) {
            if (A_set.count(headB)) {
                return headB;
            }
            headB = headB->next;
        }
        return nullptr;
    }
};