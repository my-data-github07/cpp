#include <iostream>
using namespace std;

using namespace std;

// Creating Stack class :
class Stack
// push(), pop(), peek(), isEmpty(), isFull(), and print().
{
    // Declaring the array pointer to point arrray containing elements of stack;
private:
    int top = -1;
    int length;
    int *array;

    // Some Member Functions;
public:
    // Parameterless Constructer;
    Stack()
    {
        this->length = 5;
        this->array = new int[this->length];
    }
    // Parameterised Constructer;
    Stack(int length)
    {
        this->length = length;
        this->array = new int[this->length];
    }

    // Copy constructor ;
    Stack(Stack &s)
    {
        this->length = 5;
        this->array = new int[this->length];
    }

    // Push function ;

    void push(int value)
    {
        if (top < this->length)
        {
            top++;
            this->array[top] = value;
            cout << this->array[top] << " Succesfully Pushed" << endl;
        }
        else
        {
            cout << "STACK IS FULL , Dont push more or make a bigger one " << endl;
        }
    }

    // Pop function ;
    void pop()
    {
        if (top >= 0)
        {

            cout << this->array[top] << " Succesfully Poped" << endl;
            this->array[top] = -999;
            top--;
        }
        else
        {
            cout << "Stack is empty. push something" << endl;
        }
    }

    // peek function ;

    void peek()
    {

        cout << "peekaboo : " << this->array[top] << endl;
    }

    // isEmpty function;

    bool isEmpty()
    {
        if (top == -1)
        {
            cout << "Yes EMPTY" << endl;
            return true;
        }
        else
        {
            cout << "Not Empty , elements present : " << top + 1 << endl;
            return false;
        }
    }

    // print function

    void print()
    {
        if (this->top < 0)
        {
            cout << "empty" << endl;
        }
        else
        {
            cout << "The stack is having  -: " << endl;
            for (int i = 0; i <= top; i++)
            {
                cout << this->array[i] << endl;
            }
            cout << "--------------" << endl;
        }
    }

    // deallocations of memory
    ~Stack()
    {
        delete[] array;
    }

    // operator overloading;
    void operator=(Stack &s)
    {
        s.print();
        cout << s.top << endl;
        for (int i = 0; i <= s.top; i++)
            this->array[i] = s.array[i];
        this->top = s.top;
    }
};

int main()
{
    Stack stack1(15);

    stack1.push(1);
    stack1.push(2);
    stack1.push(6);
    stack1.push(7);
    stack1.peek();
    stack1.push(3);
    stack1.push(4);
    stack1.push(5);
    stack1.pop();

    Stack stack2;
    stack2 = stack1;

    cout << "______" << endl;
    stack2.print();
    cout << "______" << endl;
    stack1.print();

    return 0;
}