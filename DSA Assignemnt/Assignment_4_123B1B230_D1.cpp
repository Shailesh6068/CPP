/***       
Name - Shailesh Pawar
Roll no - SYCOD230
PRN - 123B1B230
Div - D(1)

Assignment No. : 4                        

Tittle : Implement a simple text editor application using a doubly linked list to manage the text buffer.
Text editor should support the following functionalities:
a. Insert text
b. Delete text
c. Display text
d. Search text
e. Print text in reverse
 ***/
#include <iostream>
using namespace std;
class node
{
public:
    node *next;
    node *prev;
    string s;

    node()
    {
        next = nullptr;
        prev = nullptr;
    }

    void read()
    {
        cout << "Enter the text :";
        cin >> s;
    }
};
class text_Editor
{
    public:
    node *head;
    node *tail;
    string search_wo;
    int n = 0;

    text_Editor()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insert_text()
    {
        node *new_text = new node;
        new_text->read();
        if (head == nullptr)
        {
            head = new_text;
            tail = new_text;
            return;
        }

        tail->next = new_text;
        new_text->prev = tail;
        tail = new_text;
        return;
    }

    void del_at_end()
    {
        node *temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        if (tail == nullptr)
        {
            head == nullptr;
            tail == nullptr;
            return;
        }
        free(temp);
        cout<<"The word is deleted..."<<endl;
    }

    node *search()
    {
        cout << "Write the word :";
        cin >> search_wo;

        node* curr = head;
        while (curr != nullptr) {
            if (curr->s == search_wo) {
                
                return curr; // Word found
            }
            n++;
            curr = curr->next;
        }
        return nullptr; // Word not found
    }

    void delete_at_start()
    {
        if (head == NULL)
        {
            return;
        }
        node *temp = head;
        head = head->next;
        if (head == NULL)
        {
            tail = NULL;
        }
        else
        {
            head->prev = NULL;
        }
        delete temp;
    }

    void del_the_spec_word()
    {
        node *temp = search();
        if (n == 0)
        {
            delete_at_start();
            cout<<"The word is deleted..."<<endl;
            return;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }

    void delete_text()
    {
        int n;
        cout<< "1.Delete End." <<"    "<<"2.Delete the specific Word."<<"    "<< "3.exit." << endl;
        while(true)
        {
            cout << "Delete : Enter the Choice :";
            cin >> n;
            switch (n)
            {
            case 1:
                del_at_end();
                break;

            case 2:
                del_the_spec_word();
                break;

            case 3:
                return;

            default:
                break;
            }
        }
    }

    void reverse()
    {
        node *rev = tail;
        while (rev != nullptr)
        {
            cout << rev->s << " ";
            rev = rev->prev;
        }
        cout<<endl;
    }

    void display()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout<<temp->s<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};
int main()
{
    cout << "1:Insert text " << endl
         << "2:Delete text" << endl
         << "3:Display text" << endl
         << "4:Search text" << endl
         << "5:Print text in reverse" << endl
         << "6:Exit" << endl;

    text_Editor te;
    while (true)
    {
        int ch;
        cout << "Enter the Choice :";
        cin >> ch;
        switch (ch)
        {

        case 1:
            te.insert_text();
            break;

        case 2:
            te.delete_text();
            break;

        case 3:
            te.display();
            break;

        case 4:
            if (te.search())
            {
                cout << "This word present."<<endl;
            }
            else
            {
                cout << "The word is not present"<<endl;
            }
            break;

        case 5:
            te.reverse();
            break;

        case 6:
            return 0; 

        default:
            cout << "Incorrect Choice." << endl;
            break;
        }
    }
    return 0;
}