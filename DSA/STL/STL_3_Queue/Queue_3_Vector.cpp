#include<iostream>
#include<vector>
using namespace std;
class Queue
{
    vector<int> v;
    int front;
    int back;

    public:
    
    Queue()
    {
        front = -1;
        back = -1;
    }

    void enqueue(int data)
    {
        v.push_back(data);
        back++;

        if(back == 0){
            front = 0;
        }
    }

    void dequeue()
    {
        if(front == back)
        {
            front = -1;
            back =  -1;
            v.clear();
        }
        else
        {
            front++;
        }
    }

    bool is_empty()
    {
        return front == -1;
    }

    int getfront()
    {
        if(front == -1)
        {
            return -1;
        }
        return v[front];
    }
};
int main()
{
     Queue Q;
    Q.enqueue(1);
    Q.enqueue(2);
    Q.enqueue(3);
    Q.enqueue(4);
    Q.enqueue(5);
    //Q.display();
    Q.dequeue();
    cout<<endl;
    //Q.display();

    while(!Q.is_empty())
    {
        cout<<Q.getfront()<<"  ";
        Q.dequeue();
    }
    Q.is_empty();
    Q.getfront();
    

}