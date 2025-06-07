#include <iostream>

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
    public:
        Node* findIntersection(Node *headA, Node *headB) {
            Node *ptr1 = headA;
            Node *ptr2 = headB;

            if(headA == headB) return ptr1;

            while(ptr1 != ptr2) {
                
                if(ptr1 == nullptr) {
                    ptr1 = headB;
                } else {
                    ptr1 = ptr1->next;
                }

                ptr2 = (ptr2 == nullptr) ? headA : ptr2->next;
            }

            return ptr1;
        }
};

int main() {
    Node *a1 = new Node(4);
    Node *a2 = new Node(1);
    Node *a3 = new Node(1);
    
    Node *b1 = new Node(5);
    Node *b2 = new Node(6);

    Node *c1 = new Node(19);
    Node *c2 = new Node(8);
    Node *c3 = new Node(4);
    Node *c4 = new Node(5);

    // head A
    a1->next = a2;
    a2->next = a3;
    a3->next = c1;

    // head B
    b1->next = b2;
    b2->next = c1;

    // common list
    c1->next = c2;
    c2->next = c3;
    c3->next = c4;

    Solutions sol;

    Node *result = sol.findIntersection(a1, b1);

    cout << "Value : " << result->val << " is where they intersect!" << endl;

    return 0;
}