#include<iostream>
#include<unordered_map>
using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
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
        RandomListNode* new_head = new RandomListNode(-1);
        RandomListNode* new_temp = new_head;
        unordered_map<RandomListNode*, RandomListNode*> reflect_map;
        while(temp) {
            RandomListNode* new_node = new RandomListNode(temp->label);
            new_node->next = nullptr;
            new_temp->next = new_node;
            new_temp = new_node;
            reflect_map[temp] = new_temp;
            temp = temp->next;
        }
        temp = pHead;
        for (auto& e : reflect_map) {
            if (e.first->random) {
                e.second->random = reflect_map[e.first->random];
            }
            else {
                e.second->random = nullptr;
            }
        }
        return new_head->next;
    }
};
