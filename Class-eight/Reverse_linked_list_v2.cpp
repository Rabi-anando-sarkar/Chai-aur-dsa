#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) {
        val = x,
        next = nullptr;
    }
};

class Solution {
    public:
        void display(ListNode *head) {
            ListNode *temp;
            temp = head;
            while(temp!=nullptr) {
                cout << temp -> val << " -> ";
                temp = temp->next;
            }
        }

        ListNode* reverseLinkedList(ListNode *head) {
            ListNode *temp = head;
            stack <int> S;

            if(head == nullptr) return head;
            if(head->next == nullptr) return head;

            ListNode *next = nullptr;

            while(temp != nullptr) {
                S.push(temp->val);
                temp = temp->next;
            }

            temp=head;

            while(!S.empty()) {
                temp->val = S.top();
                S.pop();
                temp = temp->next;
            }

            return head;
        }
};

int main() {
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
    ListNode *n5 = new ListNode(5);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    Solution sol;

    sol.display(n1);
    
    ListNode *result = sol.reverseLinkedList(n1);
    cout << '\n';
    sol.display(result);

    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;

    return 0;
}