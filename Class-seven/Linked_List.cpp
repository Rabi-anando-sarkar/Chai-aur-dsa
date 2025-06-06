#include <iostream>

using namespace std;

class node {
    public:
        int data;
        node *next;

    node () {
        next = nullptr;
    }
};

class LinkedList {
    node *head;

    public:
        LinkedList() {
            head = nullptr;
        }

    // Insert at beginning
        
        void insert_at_beg(int value) {
            node *temp = new node();    // node banaya
            temp -> data = value;       // data me value daal do
            temp -> next = head;        // temp ke next me head ka address daal denge
            head = temp;                // head me temp daal denge (head/temp dono same node ko point kar rahe hai)
        }

    // Insert at end

        void insert_at_end(int value) {
            node *tail = head;
            node *temp = new node();
            temp -> data = value;
            if(head == nullptr) {
                head = temp;
            } else {
                while(tail->next != nullptr) {
                    tail = tail -> next;
                }
                tail -> next = temp;
            }
        }

    // Insert in middle

        void insert_at_mid(int value, int position) {
            int count = 1;
            node *mid = head;
            node *temp = new node();
            temp -> data = value;
            while(count<(position-1)) {
                mid = mid -> next;
                count++;
            }
            temp -> next = mid -> next;
            mid -> next = temp;
        }

        void insert_at_mid_v2(int value, int position) {
            node *temp = new node();
            temp -> data = value;
            node *mid = head;
            if(position == 1) {
                temp -> next = head; 
                head = temp;
            } else {
                while(((position-2) != 0) && (mid -> next != nullptr)) {
                    mid = mid -> next;
                    position--;
                }
                temp -> next = mid -> next;
                mid -> next = temp;
            }
        }

    // Display 

        void display() {
            if(head == nullptr) {
                cout << "List is Empty" << endl;
            } else {
                node *temp = head;
                while(temp != nullptr) {
                    cout << temp -> data << " -> ";
                    temp = temp -> next;
                }
            }
        }

    // Delete at beginning

        void delete_at_beg() {
            if(head == nullptr) {
                cout << "Deletion is not possible";
            } else {
                node *to_delete = head;
                head = head -> next;
                delete(to_delete);
            }
            
        }

    // Delete at mid
        void delete_at_mid(int position) {
            int count = 1;
            node *temp = head;
            while(count<(position-1)) {
                temp = temp -> next;
                count++;
            }
            node *to_delete = temp->next;
            temp->next = to_delete->next;
            delete to_delete;
        }

        void delete_at_mid_v2(int position) {
            if(head == nullptr) {
                cout << "Not possible";
            } else if(position == 1) {
                node *mid = head;
                head = head ->next;
                delete mid;
            } else {
                node *temp = head;
                while(((position-2) != 0) && (temp -> next != nullptr)) {
                    temp = temp -> next;
                    position--;
                }
                node *to_delete = temp -> next;
                temp -> next = to_delete -> next;
                delete to_delete;
            }
        }

    // Delete_at_end
        void delete_at_end() {
            node *prev = head;
            node *tail = head;
            while(tail -> next != nullptr) {
                prev = tail;
                tail = tail -> next;
            }
            delete(tail);
            prev -> next = nullptr;
        }

        void delete_at_end_v2() {
            if(head == nullptr) {
                cout << "List is empty";
            } else if(head -> next == nullptr) {
                delete(head);
                head=nullptr;
            } else {
                node *tail = head;
                while(tail -> next -> next != nullptr) {
                    tail = tail -> next;
                }
                delete(tail->next);
                tail->next = nullptr;
            }
        }
};

int main() {
    LinkedList list;
    
    list.insert_at_beg(10);
    list.insert_at_beg(20);
    list.insert_at_beg(30);

    list.display();
    cout << '\n' ;

    list.insert_at_end(50);
    list.insert_at_end(60);
    list.insert_at_end(70);

    list.display();
    cout << '\n' ;

    list.insert_at_mid(100,3);
    list.insert_at_mid_v2(99,4);

    list.display();
    cout << '\n' ;
    
    list.delete_at_beg();
    
    list.display();
    cout << '\n' ;
    
    list.delete_at_end();
    list.delete_at_end_v2();
    
    list.display();
    cout << '\n' ;
    
    list.delete_at_mid(4);
    list.delete_at_mid_v2(2);
    
    list.display();
    cout << '\n' ;

    return 0;
}