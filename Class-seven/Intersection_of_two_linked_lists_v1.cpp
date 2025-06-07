#include <iostream>
#include <stack>

using namespace std;

struct Node {
    int val;
    Node *next;
    Node(int x) {
        val = x,
        next = nullptr;
    }
};

class Solutions {
        stack <Node*> s1;
        stack <Node*> s2;

        Node *intersection = nullptr;

    public:
        Node* findIntersection(Node *headA, Node *headB) {

            if(headA == headB) return headA;

            while(headA->next != nullptr) {
                s1.push(headA);
                headA = headA->next;
            }

            while(headB->next != nullptr) {
                s2.push(headB);
                headB = headB->next;
            }

            

            while(!s1.empty() && !s2.empty() && s1.top() == s2.top()) {
                intersection = s1.top();
                s1.pop();
                s2.pop();
            }

            return intersection;
        }
};

int main() {
    Node *a1 = new Node(4);
    Node *a2 = new Node(1);
    
    Node *b1 = new Node(5);
    Node *b2 = new Node(6);
    Node *b3 = new Node(1);

    Node *c1 = new Node(8);
    Node *c2 = new Node(4);
    Node *c3 = new Node(5);

    // head A
    a1->next = a2;
    a2->next = c1;

    // head B
    b1->next = b2;
    b2->next = b3;
    b3->next = c1;

    // common list
    c1->next = c2;
    c2->next = c3;

    Solutions sol;

    Node *result = sol.findIntersection(a1, b1);

    cout << "Value : " << result->val << " is where they intersect!" << endl;

    return 0;
}