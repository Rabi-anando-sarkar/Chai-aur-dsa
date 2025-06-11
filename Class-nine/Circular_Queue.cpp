#include <iostream>

using namespace std;

class Circular_Queue
{
private:
    int arr[10];
    int front;
    int rear;

public:
    Circular_Queue()
    {
        front = rear = -1;
    }

    void enque(int x)
    {
        if (((rear + 1) % 10) == front)
        {
            cout << "Overflow!" << endl;
        }
        else
        {
            if (front = -1)
            {
                front = rear = 0;
            }
            else
            {
                rear = (rear + 1) % 10;
            }
            arr[rear] = x;
        }
    }

    void deque()
    {
        if (front == -1)
        {
            cout << "Underflow!" << endl;
        }
        else
        {
            if (front == rear)
            {
                front = rear = -1;
            }
            else
            {
                front = (front + 1) % 10;
            }
        }
    }

    void display()
    {
        if (front == -1)
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        int i = front;
        while (true)
        {
            cout << arr[i];
            if (i == rear)
                break;
            cout << " - ";
            i = (i + 1) % 10;
        }
        cout << endl;
    }
};

int main()
{
    Circular_Queue q;

    q.enque(10);
    q.enque(20);
    q.enque(30);
    q.enque(40);

    q.display();
    cout << "\n";

    q.deque();
    q.deque();
    q.deque();

    q.display();

    return 0;
}