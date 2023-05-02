#include<iostream>
using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode* next, * random;
    RandomListNode(int x) :
        label(x), next(nullptr), random(nullptr) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        if (!pHead) {
            return nullptr;
        }
        RandomListNode* temp = pHead;
        while (temp) {
            RandomListNode* new_node = new RandomListNode(temp->label);
            new_node->next = temp->next;
            temp->next = new_node;
            temp = new_node->next;
        }
        temp = pHead; //1 1' nullptr
        RandomListNode* res_temp = temp->next;//1'
        while (temp) {
            res_temp->random = temp->random == nullptr ? nullptr : temp->random->next;
            if(res_temp)temp = res_temp->next;
            if(temp)res_temp = temp->next;
        }
        temp = pHead;
        res_temp = temp->next;
        RandomListNode* temp_2=nullptr;
        RandomListNode* res = pHead->next;
        while (temp) {
            if (temp->next) { temp->next = temp->next->next; }
            if (res_temp->next) { res_temp->next = res_temp->next->next; }
            temp = temp->next;
            res_temp=res_temp->next;
        }
        return res;
    }
};

int main() {    
    RandomListNode* head = new RandomListNode(1);
    Solution solution;
    RandomListNode* res = solution.Clone(head);
    while (res) {
        cout << res->label << endl;
        res = res->next;
    }
}
