/*** 
Name - Shailesh Pawar
Roll no - SYCOD230
PRN - 123B1B230
Div - D(1)

Assignment No. :- 5
Title - Implement a navigation system for a delivery service using a circular linked list to represent routes.
The navigation system should support the following functionalities: 
a. Add route 
b. Remove route 
c. Display route.
***/
 #include <iostream>
using namespace std;
class Node
{
    public:
    Node *next; 
    string sou, des; 
    float time, distance, charges; 

    Node()
    {
        next = NULL; 
    }

    void read();
    void display_nav();
    string get_source();
    void newd(string a, string b, float c, float d, float e);
};
void Node::read()
{
    cout << "\nEnter the SOURCE Address: ";
    cin >> sou;
    cout << "\nEnter the DESTINATION Address: ";
    cin >> des;
    cout << "\nEnter the Distance Between source and destination in km: ";
    cin >> distance;
    cout << "\nTime required in minutes: ";
    cin >> time;
    cout << "\nCharges for Travelling: ";
    cin >> charges;
}
void Node::display_nav()
{
    cout << "\nSOURCE: " << sou;
    cout << "\nDESTINATION: " << des;
    cout << "\nDistance from " << sou << " to " << des << " is " << distance << " km.";
    cout << "\n" << time << " minutes are required to reach!!!";
    cout << "\nCharges: " << charges << " RS.";
    cout << "\n----------------------------------------------\n";
}
string Node::get_source()
{
    return sou;
}
void Node::newd(string a, string b, float c, float d, float e)
{
    sou = a;
    des = b;
    distance = c;
    time = d;
    charges = e;
}
class navigation
{
    Node *start;
    public:
    navigation()
    {
        start = NULL; 
    }
    void create();
    void display();
    void ins_beg();
    void ins_between();
    void ins_end();
    void del_beg();
    void del_between();
    void del_end();
    void modify();
};
void navigation::create()
{
    Node *nnode; 
    Node *temp; 
    char ch; 

    do {
        nnode = new Node; 
        cout << "\nEnter details:- : ";
        nnode->read(); 
        if (start == NULL) 
        {
            start = nnode;
            nnode->next = start; 
        }
        else
        {
            temp = start;
            while (temp->next != start) {
                temp = temp->next;
            }
            temp->next = nnode; 
            nnode->next = start;
        }

        cout << "\nDo you have more data?? (y/n): ";
        cin >> ch;  
    } while (ch == 'y'); 
}
void navigation::display()
{
    Node *temp = start; 
    cout << "\nThe stored Details are: ";
    do {
        temp->display_nav(); 
        temp = temp->next; 
    } while (temp != start); 
}
void navigation::ins_beg()
{
    Node *nnode, *temp;

    nnode = new Node;
    cout << "Enter a Source address to be ADD at begin:- ";
    nnode->read(); 

    if (start == NULL) 
    {
        start = nnode; 
        nnode->next = start; 
    }
    else
    {
        for (temp = start; temp->next != start; temp = temp->next);
        nnode->next = start; 
        start = nnode; 
        temp->next = start;
    }
    display();
}

void navigation::ins_between()
{
    Node *nnode, *temp;
    string n;

    nnode = new Node; 
    cout << "\nEnter a Source address to be ADD:- ";
    nnode->read(); 

    cout << "Enter the Source address after which you want to ADD:- ";
    cin >> n;

    for (temp = start; temp != start; temp = temp->next)
    {
        if (temp->get_source() == n) 
        {
            nnode->next = temp->next; 
            temp->next = nnode;
            break;
        }
    }

    display();
}

void navigation::ins_end()
{
    Node *nnode, *temp;

    nnode = new Node; 
    cout << "\nEnter a Source address to be ADDed at end:- ";
    nnode->read(); 

    if (start == NULL)
    {
        start = nnode;
        nnode->next = start; 
    }
    else
    {
        for (temp = start; temp->next != start; temp = temp->next);
        temp->next = nnode; 
        nnode->next = start; 
    }
    display();
}

void navigation::del_beg()
{
    Node *temp;
    Node *x = start;

    for (temp = start; temp->next != start; temp = temp->next); 

    if (temp == start) 
    {
        start = NULL; 
        cout << "\nThere is no data in linked list !!";
    }
    else
    {
        start = start->next;
        temp->next = start; 
        display();
    }
    delete x; 
}
void navigation::del_between()
{
    Node *x,*temp = start;
    string num;
    cout << "Enter the Source address which you want to remove:- ";
    cin >> num;
    for (temp = start; temp != start; temp = temp->next)
    {
        if (temp->next->get_source() == num) 
        {
            x = temp->next; 
            temp->next = x->next; 
            delete x; 
            break;
        }
    }
    display();
}

void navigation::del_end()
{
    Node *x, *temp;

    if (start == NULL)
    {
        cout << "\nList is empty. Cannot remove from an empty list !!!";
    }
    else
    {
        for (temp = start; temp->next->next != start; temp = temp->next); 
        x = temp->next; 
        temp->next = start; 
        delete x; 
        display();
    }
}

void navigation::modify()
{
    int found = 0;
    Node *temp;
    string nsou, ndes, n;
    float nt, ndist, ncha;

    cout << "\nEnter the Source address which you want to Modify:- ";
    cin >> n;

    cout << "Enter the new source address: ";
    cin >> nsou;
    cout << "Enter the new destination address: ";
    cin >> ndes;
    cout << "\nEnter the Distance Between source and destination in km: ";
    cin >> ndist;
    cout << "\nTime required in minutes: ";
    cin >> nt;
    cout << "\nCharges for Travelling: ";
    cin >> ncha;

    for (temp = start; temp != NULL; temp = temp->next)
    {
        if (temp->get_source() == n)
        {
            temp->newd(nsou, ndes, ndist, nt, ncha);
            found = 1;
            break;
        }
    }

    if (found == 1)
        cout << "The Route is MODIFIED !!!!";
    else
        cout << "Route not MODIFIED ";
}

int main()
{
    navigation l;
    int choice;

    while (1)
    {
        cout << "\nMENU: "
             << "\n1.Store data"
             << "\n2.Display data"
             << "\n3.ADD ROUTE data at beginning"
             << "\n4.ADD ROUTE data in between any position"
             << "\n5.ADD ROUTE data at end"
             << "\n6.REMOVE ROUTE data of beginning"
             << "\n7.REMOVE ROUTE data of an position in between"
             << "\n8.REMOVE ROUTE data of end"
             << "\n9.MODIFIY Details"
             << "\n10.Exit"
             << "\n------------------------------------------------";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            l.create();
            break;
        case 2:
            l.display();
            break;
        case 3:
            l.ins_beg();
            break;
        case 4:
            l.ins_between();
            break;
        case 5:
            l.ins_end();
            break;
        case 6:
            l.del_beg();
            break;
        case 7:
            l.del_between();
            break;
        case 8:
            l.del_end();
            break;
        case 9:
            l.modify();
            break;
        case 10:
            cout << "\n\n-------------THANK YOU-------------\n\n";
            exit(0);
        default:
            cout << "\nInvalid choice! Please enter a valid choice !!!!! ";
            break;
        }
        cout << "\n----------------------------------------------";
    }
    return 0;
}
