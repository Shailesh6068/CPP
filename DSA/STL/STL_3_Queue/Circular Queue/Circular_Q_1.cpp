#include<iostream>
#include<vector>
using namespace std;
class Circular_Queue
{
    public:
    vector<int> v;
    int tot_size;
    int curr_size;
    int back,front;

    Circular_Queue(int size)
    {
        v.resize(size);
        tot_size = size;
        curr_size = 0;
        back = size-1;
        front= 0;
    }

    void enqueue(int data)
    {
        if(is_full())
        {
            cout<<"Queue is Full.\n";
        }
        else
        {
            back = (back+1)% tot_size;
            v[back] = data;
            curr_size++;
        }
       
    }
    
    void dequeue()
    {
        if (is_empty())
        {
            cout<<"IS empty.\n";
        }
        else
        {
            front = (front+1)%tot_size;
            curr_size--;
        }
    }

    bool is_empty()
    {

    }
    bool is_full()
    {

    }

    int getfront()
    {

    }
};
int main()
{

}