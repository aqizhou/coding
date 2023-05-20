/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
#include<vector>
#include<queue>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) { return root; }
        queue<Node*> que;
        que.push(root);
        int size = 0;
        while(!que.empty()) {
            size = que.size();
            for (int i = 0; i < size; ++i) {
                Node* front = que.front();
                que.pop();
                if (i == size - 1) {
                    front->next = nullptr;
                }
                else {
                    front->next = que.front();
                }
                if (front->left) { que.push(front->left); }
                if (front->right) { que.push(front->right); }
            }
        }
        return root;
    }
};