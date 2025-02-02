#include<iostream>
#include<climits>
using namespace std;
class node
{   
    public:
    int val;     // are accessible in only their class.
    node* next;
    node(int data)
    {
        val = data;
        next = NULL;
    }
};
class stack
{
    int currsize;
    node* Top;
    int capacity;

    public:

    stack(int c)
    {
        capacity = c;
        Top = NULL;
        currsize = 0;
    }
    
    void push(int data)
    {
        node* new_node = new node(data);
        if(Top == NULL)
        {
            Top = new_node;
            return;
        }
        new_node->next = Top;
        Top = new_node;
        currsize++;
    }

    void pop()
    {
        if(Top == NULL)
        {
            cout<<"it is empty.\n";
            return;
        }
        node* temp = Top;
        Top = Top->next;
        if (Top == nullptr)
        {
            return;
        }
        free(temp);
    }

    int get_Top()
    {
        if(Top == nullptr)
        {
           cout<<"Stack is empty \n";
           return INT_MIN;
        }
        
        return Top->val;
    }

    bool isempty()
    {
        return Top == NULL;
    }

    bool isfull()
    {
        return currsize == capacity;
    }

    void display()
    {
        node* curr = Top;
        while (curr != NULL)
        {
            cout<<curr->val<<endl;
            curr = curr->next;
        }    
    }

};
int main()
{
    stack s(4);
   // cout<<s.get_Top();
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.display();
    s.pop();
    cout<<"After pop :"<<endl;
    s.display();
    
}