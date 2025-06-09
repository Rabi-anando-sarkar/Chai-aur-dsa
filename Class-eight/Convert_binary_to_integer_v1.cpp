#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) {
        val = x,
        next = nullptr;
    }
};

class Solutions {
    public:
        int convertBinToInt(ListNode *head) {
            int num=0;
            while(head!=nullptr) {
                num = num*2 + head->val;
                head = head->next;
            }

            return num;
        }
};

int main() {
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(1);
    ListNode *n3 = new ListNode(1);
    
    n1->next = n2;
    n2->next = n3;

    Solutions sol;

    int result = sol.convertBinToInt(n1);

    cout << "Answer : " << result << endl;

    return 0;
}