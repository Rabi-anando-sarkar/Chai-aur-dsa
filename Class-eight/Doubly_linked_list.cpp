#include <iostream>

using namespace std;

class ListNode {
    public:
        int val;
        ListNode *prev;
        ListNode *next;

    ListNode() {
        prev = nullptr;
        next = nullptr;
    }
};

class Solutions {
    ListNode *head;

    public:
        Solutions() {
            head = nullptr;
        }

        void insert_at_end(int value) {
            ListNode *temp = new ListNode();
            ListNode *tail = head;
            temp->val = value;

            if(head == nullptr) {
                head = temp;
                tail = head;
            } else {
                while(tail->next!=nullptr) {
                    tail = tail->next;
                }
                tail->next = temp;
                temp->prev = tail;
            }
        }

        void insert_at_beg(int value) {
            ListNode *temp = new ListNode();
            temp->val = value;

            if(head==nullptr) {
                head = temp;
            } else {
                temp->next = head;
                head->prev = temp;
                head = temp;
            }
        }

        void insert_at_mid(int value, int position) {
            int count = 1;
            ListNode *mid = head;
            ListNode *temp = new ListNode();
            temp->val = value;

            while(count<(position-1)) {
                mid = mid->next;
                count++;
            }

            temp->next = mid->next;
            temp->prev = mid;
            mid->next = temp;
        }

        void delete_at_beg() {
            if(head==nullptr) {
                cout << "Not possible!" << endl;
            } else {
                ListNode *to_delete = head;
                head=head->next;
            
                delete to_delete;
            }
        }

        void delete_at_end() {
            if(head==nullptr) {
                cout << "Not possible!" << endl;
            } else if(head -> next == nullptr) {
                delete head;
                head = nullptr;
            } else {
                ListNode *to_delete = head;
                while(to_delete->next!=nullptr) {
                    to_delete = to_delete->next;
                }
                to_delete->prev->next = nullptr;

                delete to_delete;
            }
        }

        void delete_at_mid(int position) {
            int count = 1;
            ListNode *temp = head;

            while(count<position) {
                temp = temp->next;
                count++;
            }

            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            delete temp;
        }

        void display() {
            if(head==nullptr) {
                cout << "List is empty!" << endl;
            } else {
                ListNode *temp = head;
                while(temp!=nullptr) {
                    cout << temp->val << " -> ";
                    temp = temp->next;
                }
            }
        }
};

int main() {

    Solutions sol;
    
    // sol.insert_at_beg(10);
    // sol.insert_at_beg(20);
    // sol.insert_at_beg(30);

    // sol.display();
    // cout << "\n";

    // sol.insert_at_end(100);
    // sol.insert_at_end(200);
    // sol.insert_at_end(300);

    // sol.display();
    // cout << "\n";

    // sol.insert_at_mid(9999,4);

    // sol.display();
    // cout << "\n";

    sol.insert_at_beg(10);
    sol.insert_at_end(20);
    sol.insert_at_end(30);
    sol.insert_at_beg(5);
    sol.insert_at_mid(25, 3);

    sol.display();
    cout << "\n";

    sol.delete_at_beg();

    sol.display();
    cout << "\n";

    sol.delete_at_end();

    sol.display();
    cout << "\n";
    
    sol.delete_at_mid(2);

    sol.display();
    cout << "\n";

    return 0;
}