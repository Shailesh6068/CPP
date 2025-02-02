#include<iostream>
using namespace std;
class node
{   public:
    int val;
    node* next;

    node(int data)
    {
        val = data;
        next = NULL; 
    }
};
class circular_list
{
    public:
    node* head;

    circular_list()
    {
        head = NULL;
    }
    
    void insert_at_start(int data)
    {
        node* new_node = new node(data);
        if (head == NULL)
        {
            head = new_node;       
            new_node->next = head;            
        }

        node* tail = head;
        while(tail->next != head)
        {
           // 
            tail = tail->next;          
        }                               
        tail->next = new_node;
        new_node->next = head;
        head = new_node;        // 5->4->3->2->1->5
        
    }
    void insert_at_k(int data,int pos)
    {
        node* new_node = new node(data);
        if(head == nullptr)
        {
            head = new_node;
            new_node->next = new_node; 
            return;
        } 

        if(pos==1)
        {
            insert_at_start(data);
            return;
        }
        //if( pos == )
             
        node* curr = head;
        int curr_pos = 1; 
        while(curr_pos < pos-1 && curr->next != head)
        {
            curr = curr->next;
            curr_pos++;
        }

        new_node->next = curr->next;
        curr->next = new_node;
    }
    void display()
    {
        cout<<"head :"<<head<<endl;
        node* temp = head;
        do
        {
          
            cout<<temp->val<<"->";
            temp = temp->next;
            cout<<"value at next address:"<<temp->val<<endl;
        }while(temp!=head);
        
        cout<<endl;
    }

    // void display_1()
    // {
    //     node* temp = head;
    //     int c = 1;
    //     while (c<10)
    //     {
    //         cout<<temp->val<<"  ";
    //         temp = temp->next;
    //         c++;
    //     }
        
    // }
};
int main()
{
    circular_list cl;
    cl.insert_at_start(5);
    cl.insert_at_start(4);
    cl.insert_at_start(3);
    cl.insert_at_start(2);
    cl.insert_at_start(1);
    cl.display();
    cout<<"After Insert :"<<endl;
    cl.insert_at_k(6,6);
    cl.display();
  //  cl.display_1();

    return 0;
}