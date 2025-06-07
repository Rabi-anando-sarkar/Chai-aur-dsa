#include <iostream>

using namespace std;

class Node {
    public:
        int val;
        Node *next;
    Node() {
        next = nullptr;
    }
};

class Solution {
    Node *head=nullptr;

    public:
        void insert_end(int value) {
            Node *tail=head;
            Node *temp = new Node();
            temp->val = value;
            if(head == nullptr) {
                head = temp;
            } else {
                while(tail->next != nullptr) {
                    tail = tail->next;
                }
                tail->next = temp;
            }
        }

        Node *getHead() {
            return head;
        }
        
        bool isPalindrome(Node *head) {
            if(head == nullptr || head->next == nullptr) return true;

            Node *slow = head;
            Node *fast = head;

            while(fast->next && fast->next->next) {
                slow = slow->next;
                fast = fast->next->next;
            }

            Node *dhead = slow->next;
            Node *dtail = nullptr;

            while(dhead != nullptr) {
                Node *next = dhead->next;
                dhead->next = dtail;
                dtail = dhead;
                dhead = next;
            }

            slow = head;
            fast = dtail;

            while(fast) {
                if(slow->val != fast->val) {
                    return false;
                }
                slow = slow -> next;
                fast = fast -> next;
            }

            return true;
        }
};

int main() {

    Solution sol;

    sol.insert_end(1);
    sol.insert_end(1);
    sol.insert_end(2);
    sol.insert_end(2);
    sol.insert_end(1);
    sol.insert_end(1);

    bool result = sol.isPalindrome(sol.getHead());

    cout << (result ? "Plaindrome" : "Not Palindrome") << endl;

    return 0;
}