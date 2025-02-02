#include<iostream>
#include <climits>
using namespace std;
class stack
{
    int capacity;    // size          
    int* arr;
    int top;

    public:
    stack(int c)
    {
        capacity = c;
        arr =new int[c];
        top = -1;
    }

    void push(int data)
    {
        if(top == capacity-1)
        {
            cout<<"Stack is full / Overflow \n";
            return;
        }
        top +=1;
        arr[top] = data;     
    }

    void pop()
    {
        if(top == -1)
        {
            cout<<"The stack is empty(underflow) \n";
            return;
        }
        top--;
    }

    int getTop()
    {
        if(top == -1)
        {
            cout<<"it is empty \n";
            return INT_MIN;
        }
        return arr[top];
    }

    bool isempty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == capacity-1;
    }

    void display()
    {
        if (isempty())
        {
            cout << "The stack is empty." << endl;
            return;
        }
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << endl;  // Print from top to bottom
        }
        //cout<<arr[3];
    }

    // void change()
    // {
    //     arr[3] = 77;
    // }

};
// class array
// {
//     public:
//     stack s;
    
//     void p()
//     {
//         s.push(5);
//     }
// };
int main()
{
    stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.display();
    cout<<"\n After pop \n";
    s.pop();
   // s.change();
    s.display();
   // cout<<s.getTop();
   //    cout<<s.isempty();
   //    cout<<s.isFull();


}