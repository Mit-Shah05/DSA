#include <iostream>

using namespace std;

#define MAX_SIZE 25

class Stack
{
private:
    int arr[MAX_SIZE];
    int top = -1;

public:
    void push(int data);
    void pop();
    void peek();
    void sortStack();
    void sortInserted(int element);
    void display();
    bool isFull();
    bool isEmpty();
};

bool Stack::isFull()
{
    return (top == MAX_SIZE - 1);
}

bool Stack::isEmpty()
{
    return (top < 0);
}

void Stack::push(int data)
{
    if(isFull())
    {
        cout << "Stack is full!" << endl;
    }
    else
    {
        top++;
        arr[top] = data;
    }
}

void Stack::pop()
{
    if(isEmpty())
    {
        cout << "Stack is empty!!" << endl;
    }
    else
    {
        cout << "Element popped: " << arr[top] << endl;
        top--;
    }
}

void Stack::peek()
{
    cout << "Element at the top: " << arr[top] << endl;
}

void Stack::sortStack()
{
    int element;
    if(!isEmpty())
    {
        element = arr[top];
        pop();
        sortStack();
        sortInserted(element);
    }
}

void Stack::sortInserted(int element)
{
    if(isEmpty() || element > arr[top])
    {
        push(element);
        return;
    }

    int temp = arr[top];
    pop();
    sortInserted(element);
    push(temp);
}

void Stack::display()
{
    cout << "The array is: ";
    for(int i = top; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    Stack s;
    int ch = 0;

    while(ch != 5)
    {
        cout << "1. Push Element" << endl;
        cout << "2. Pop Element" << endl;
        cout << "3. Peek Element" << endl;
        cout << "4. Sort" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter Choice: ";
        cin >> ch;

        switch(ch)
        {
        case 1:
            int data;

            cout << endl << "Enter the element to push: ";
            cin >> data;
            s.push(data);

            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.peek();
            break;

        case 4:
            s.sortStack();
            s.display();
            break;

        case 5:
            cout << endl << "Exiting";
            break;

        default:
            cout << "Invalid, try again" << endl;
        }
    }
}
