#include <iostream>
using namespace std;
class Stack
{
private:
    int top;
    int size;
    int *arr;

public:
    Stack()
    {
        this->size = 5;
        this->arr = new int[this->size];
        this->top = -1;
        for (int index = 0; index < this->size; index++)
        {
            this->arr[index] = -1;
        }
    }
    Stack(int size)
    {
        this->size = size;
        this->arr = new int[this->size];
        this->top = -1;
        for (int index = 0; index < this->size; index++)
        {
            this->arr[index] = -1;
        }
    }
    void push(int value)
    {
        this->top++;
        this->arr[top] = value;
    }
    void pop()
    {
        this->arr[top] = -1;
        this->top--;
    }
    int peek()
    {
        int value;
        value = this->arr[this->top];
        return value;
    }
    bool is_empty()
    {
        return (this->top == -1);
    }
    bool is_full()
    {
        return (this->top == this->size - 1);
    }
    void operator=(const Stack &other)
    {
        if (arr != NULL)
        {
            delete[] this->arr;
            this->arr = NULL;
        }
        this->size = other.size;
        this->top = other.top;
        this->arr = new int[this->size];
        for (int index = 0; index < this->size; index++)
        {
            this->arr[index] = other.arr[index];
        }
        cout << "STACK copied succefully" << endl;
    }

    void print()
    {
        int index;
        cout << "\n-----------------------------------" << endl;
        cout << "\n data index are :" << endl;
        for (index = this->size - 1; index >= 0; index--)
        {
            cout << "Data :" << this->arr[index] << " is present at index " << index << endl;
        }
        cout << "\n-----------------------------------" << endl;
    }
    ~Stack()
    {
        if (arr != NULL)
        {
            delete[] this->arr;
            this->arr = NULL;
        }
    }
};

int menu()
{
    int choice;
    cout << "0 Exit\n1. Create Stack\n2. Push \n3. Pop \n4. Peek \n5. Print Stack " << endl;
    cout << "Enter Your choice: " << endl;
    cin >> choice;
    return choice;
}
int main()
{
    int choice, data, size;
    Stack *stack = NULL;
    bool status;
    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
        {
            if (stack == NULL)
            {
                cout << "Enter the size of stack: " << endl;
                cin >> size;
                stack = new Stack(size);
            }
            else
            {
                cout << "Stack is already created!" << endl;
            }
            break;
        }
        case 2:
        {
            if (!(stack->is_full()))
            {
                cout << "Enter data =" << endl;
                cin >> data;
                stack->push(data);
            }
            else
            {
                cout << " stack is full " << endl;
            }
        }
        break;
        case 3:
        {
            if (!(stack->is_empty()))
            {
                data = stack->peek();
                stack->pop();
                cout << " pop value = " << data << endl;
            }
            else
                cout << "stack is empty" << endl;
        }
        break;
        case 4:
        {
            if (!(stack->is_empty()))
            {
                data = stack->peek();
                cout << "peek value = " << data << endl;
            }
            else
                cout << "stack is empty " << endl;
        }
        break;
        case 5:
        {
            stack->print();
            break;
        }
        default:
        {
            cout << "invalide choice " << endl;
            break;
        }
        }
    }
    Stack *stack1 = new Stack(size);
    *stack1 = *stack;
    cout << "stack1 :" << endl;
    stack1->print();
    if (stack != NULL)
    {
        delete stack;
        stack = NULL;
    }
    if (stack1 != NULL)
    {
        delete stack1;
        stack1 = NULL;
    }
    return 0;
}