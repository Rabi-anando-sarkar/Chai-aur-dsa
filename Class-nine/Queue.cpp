#include <iostream>

using namespace std;

class Queue {
    private:
        int arr[10];
        int front;
        int rear;
    
    public:
        Queue() {
            front = rear = -1;
        }

        void enque(int x) {
            if(rear==9) {
                cout << "Overflow!" << endl;
            } else {
                if(front==-1 && rear==-1) {
                    front = 0;
                    rear = 0;
                    arr[front] = x;
                } else {
                    rear++;
                    arr[rear] = x;
                }
            }
        }

        void deque() {
            if(rear==-1) {
                cout << "Underflow!" << endl;
            } else {
                if(front == rear) {
                    front = -1;
                    rear = -1;
                } else {
                    front++;
                }
            }
        }

        void display() {
            if (front == -1) {
            cout << "Queue is empty!" << endl;
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << arr[i];
            if (i < rear) cout << " - ";
        }
        cout << endl;
        }
};

int main() {
    Queue q;

    q.enque(10);
    q.enque(20);
    q.enque(30);
    q.enque(40);

    q.display();
    cout << "\n" ;

    q.deque();
    q.deque();
    q.deque();

    q.display();

    return 0;
}