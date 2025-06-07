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
    stack <int> S;
    ListNode *temp;

    public:
        bool isPalindrome(ListNode *head) {
            temp = head;
            while(temp != nullptr) {
                S.push(temp->val);
                temp = temp->next;
            }

            temp = head;
            while(temp != nullptr) {
                if(S.top() != temp->val) {
                    return false;
                }
                S.pop();
                temp = temp->next;
            }
            return true;
        }
};

int main() {
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(3);
    ListNode *n3 = new ListNode(2);
    ListNode *n4 = new ListNode(1);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    Solution sol;
    bool result = sol.isPalindrome(n1);

    cout << (result ? "Plaindrome" : "Not Palindrome") << endl;

    delete n1;
    delete n2;
    delete n3;
    delete n4;

    return 0;
}