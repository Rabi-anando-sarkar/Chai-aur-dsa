#include <iostream>

using namespace std;

class stack {
    private:
        int arr[100];
        int top;
    public:
        stack() {
            top = -1;
        }

        void push(int value) {
            if(top==99) {
                cout << "Stack Overflow!" << endl;
            } else {
                top++;
                arr[top] = value;
            }
        }

        void pop() {
            if(top==-1) {
                cout << "Stack UnderFlow!" << endl;
            } else {
                cout << "Popped : " << arr[top] << endl;
                top--;
            }
        }

        void tops() {
            if(top==-1) {
                cout << "Stack Empty!" << endl;
            } else {
                cout << "Top : " << arr[top] << endl;
            }
        }

        bool empty() {
            if(top==-1) {
                return true;
            }
            return false;
        }
};

int main() {
    stack S;

    S.push(10);
    S.push(20);
    S.push(30);
    S.push(40);

    if(S.empty()) {
        cout << "It is Empty" << endl;
    } else {
        cout << "It is not Empty" << endl;
    }

    S.tops();
    S.pop();
    cout << "\n";

    S.tops();
    S.pop();
    cout << "\n";

    S.tops();
    S.pop();
    cout << "\n";

    S.tops();
    S.pop();
    cout << "\n";

    if(S.empty()) {
        cout << "It is Empty" << endl;
    } else {
        cout << "It is not Empty" << endl;
    }

    return 0;
}