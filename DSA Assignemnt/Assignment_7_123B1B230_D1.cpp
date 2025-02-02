/*** 
Name - Shailesh Pawar
Roll no - SYCOD230
PRN - 123B1B230
Div - D(1)

Assignment No : 7
Tittle : Implement a browser history management system using a stack data structure to track the user's 
browsing history. The system should support the following functionalities:
a. Add visited page
b. Navigate back
c. View current page
d. Check if history is empty or not
Assume no upper bound on number of pages visite
*/
#include<iostream>
using namespace std;
class node
{
    public:
    node* next;
    string page;
    node()
    {
        next = NULL;
        page = "No Any page is Open.";
    }
    void read()
    {
        cout<<"Enter the new page :";
        cin.ignore();
        getline(cin,page);
    }
};
class BrowserHistory
{
    public:
    node* top;
    BrowserHistory()
    {
        top = NULL;
    }

    void is_empty()
    {
        if(top == NULL)
        {
            cout<<"No history is present"<<endl;
        }
        else
        {
            cout<<"History is availabel...\n";
        }
    }
    
    void newpage()
    {
        node* new_node = new node;
        new_node->read();
        if (top == NULL)
        {
            top = new_node;
            return;
        }
        new_node->next = top;
        top = new_node;
    }

    void display()
    {
        node* temp = top;
        while(temp != NULL)
        {
            cout<<temp->page<<endl;
            temp = temp->next;
        }
    }

    void Curr_page()
    {
        if(top == NULL)
        {
            cout<<"No history present."<<endl;
            return;
        }
        cout<<top->page<<endl;
    }
    
    void navigate_back()
    {
        if(top == NULL)
        {
            cout<<"No history present."<<endl;
            return;
        }
        node* temp = top;
        top  = top->next;
        cout<<"Navigated Back....\n";
        delete temp;
    }
};
int main()
{
    int n;
    BrowserHistory br;
    cout<<"The Choices are:"<<endl;
    cout<<"1:Add New page."<<endl
        <<"2:check is History is Empty or Not."<<endl
        <<"3:Show Current Page."<<endl
        <<"4:Navigate back."<<endl
        <<"5:Show History."<<endl
        <<"6.Close all page and go to Desktop."<<endl;
    while(true)
    {
        cout<<"Enter the choice :";
        cin>>n;
        switch(n)
        {
            case 1:
                br.newpage();
                break;

            case 2:
                br.is_empty();
                break;

            case 3:
                br.Curr_page();
                break;

            case 4:
                br.navigate_back();
                break;

            case 5:
                br.display();
                break;

            case 6:
                return 0;
        }
        
    }
    return 0;
}