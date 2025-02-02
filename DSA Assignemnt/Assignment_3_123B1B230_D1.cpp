/*** 
Name - Shailesh Pawar
Roll no - SYCOD230
PRN - 123B1B230
Div - D(1)

Assignment No. : 3

Tittle : Consider the playlist in a music player. Implement a playlist feature in music player application 
using singly linked list. Each song in the playlist is represented as a node in the linked list. Each 
node contains information about the song (such as title or artist or duration, etc.). 
The playlist should allow users to: 
a. Add songs
b. Remove songs
c. Display the entire playlist
d. Play specific songs
*/
#include <iostream>
using namespace std;
class song                                  // behave as a node
{
    string title;    
    string singer;

    public:

    song *next;                             // make the next of node
    song() 
    { next = NULL;                          //store the address of next
    }

    void read()                             // get input
    {
        cout << "Enter song title: ";      
        cin.ignore();
        getline(cin,title);
        cout << "Enter singer name: ";
        getline(cin,singer);
    }

    void display()                          //To display                         
    {
        cout << "Title :" << title <<"              Singer :" << singer << endl;
    }

    string getTitle()                       // give the tittle
    { 
        return title; 
    }
    
    string get_singer()                     // give singer
    {
        return singer;
    }

    void setSinger(string newSinger)         // Pass by value :-take extra memory for newSinger
    { 
        singer = newSinger;
    }
    
    void setTittle(const string& new_tittle) //Pass by Referrence:- Does not take extra space
    {                                        //const :- state that the value is constant.means there is no change in
        title = new_tittle;
    }
};
class playlist                               // Behave as Linked list
{
    song *head;                              // To store starting the address of first nnode                                           //
    public:                                  // and indicate first node
    playlist()                               // initialize head as NULL means empty
    { 
        head = NULL; 
    }
    
    void insert_end() {
        song *nn = new song;
        nn->read();

        if (head == NULL) {
            head = nn;
        } else {
            song *cn;
            for (cn = head; cn->next != NULL; cn = cn->next);
            cn->next = nn;
        }
        cout << "Song added to the playlist." << endl;
    }

    void insert_begin() 
    {
        song *temp = new song;
        temp->read();

        if(head == NULL) 
        {
            head = temp;
        }
        else 
        {
            temp->next = head;
            head = temp;
        }
        cout << "Song inserted at the beginning of the playlist." << endl;
    }

    void display_playlist() 
    {
        if (head == NULL) 
        {
            cout << "Playlist is empty." << endl;
        } 
        else 
        {
            cout << "Playlist:" << endl;
            for (song *cn = head; cn != NULL; cn = cn->next) {
                cn->display();
            }
        }
    }
    
    void delete_song() 
    {
        if (head == NULL) 
        {
            cout << "Playlist is empty, nothing to delete." << endl;
            return;
        }

        string delTitle;
        cout << "Enter the title of the song to delete: ";
        cin>>delTitle;

        song *prev = NULL;
        int flag = 0;
        for (song *cn = head; cn != NULL; prev = cn, cn = cn->next) {
            if (cn->getTitle() == delTitle) 
            {
                flag = 1;
                if (prev == NULL) {
                    head = cn->next;
                } else {
                    prev->next = cn->next;
                }
                delete cn;
                cout << "Song deleted from the playlist." << endl;
                break;
            }
        }

        if (flag == 0) 
        {
            cout << "Song not found in the playlist." << endl;
        }
    }

    void insert_at_kposition() 
    {
        string afterTitle;
        cout << "Enter the title of the song to insert after: ";
        cin>>afterTitle;

        bool found = false;

        for (song *cn = head; cn != NULL; cn = cn->next) 
        {
            if (cn->getTitle() == afterTitle) 
            {
                found = true;
                song *nn = new song;
                nn->read();
                nn->next = cn->next;
                cn->next = nn;
                cout << "Song inserted after " << afterTitle << "." << endl;
                break;
            }
        }

        if (!found) {
            cout << "Song with title '" << afterTitle << "' not found." << endl;
        }
    }

    void updatesong() 
    {
        string title, newSinger;
        cout << "Enter the title of the song to update: ";
        cin>>title;

        bool found = false;

        for (song *cn = head; cn != NULL; cn = cn->next) {
            if (cn->getTitle() == title) {
                found = true;
                cout << "Enter new singer name: ";
                cin.ignore();
                getline(cin, newSinger);
                cn->setSinger(newSinger);
                cout << "Song updated successfully." << endl;
                break;
            }
        }

        if (!found) {
            cout << "Song with title '" << title << "' not found." << endl;
        }
    }
    
    void changetittle()
    {
        song* temp = head;
        string old_tittle;
        string new_tittle;
        
        cout<<"Enter the old tittle:"<<endl;
        cin.ignore();
        getline(cin,old_tittle);
        
        cout<<"Enter the new tittle:";
        getline(cin,new_tittle);
        int flag = 0;
        while(temp != NULL)
        {
            if(temp->getTitle() == old_tittle)
            {
                flag = 1;
                temp->setTittle(new_tittle);
            }
            temp = temp->next;
        } 

        if(flag == 1)
        {
            cout<<"Tittle Changed Successfully....."<<endl;
        }
        else
        {
            cout<<"Missing Tittle,Please Write Correct!"<<endl;
        }
    }

    void changesinger()
    {
        string old_singer;
        string new_singer;
        cout<<"Enter the old singer :";
        cin.ignore();
        getline(cin,old_singer);
        cout<<"Enter the new singer :";
        getline(cin,new_singer);
        int flag = 0;
        song* temp = head;
        while (temp != NULL)
        {
            if(temp->get_singer() == old_singer)
            {
                flag = 1;
                temp->setSinger(new_singer);
            }
            temp = temp->next;
        }

        if(flag == 1)
        {
            cout<<"Singer Changed Successfully....."<<endl;
        }
        else
        {
            cout<<"Missing Singer,Please Write Correct!"<<endl;
        }
    }
    
    void update()
    {   
        int c;
        do
        {  
            cout<<"update :- Select the choice:"<<endl;
            cout<<"1.Tittle         2.Singer        3.Exit"<<endl;
            cin>>c;   
            switch(c)
            {
                case 1:
                    changetittle();
                    break;

                case 2:
                    changesinger();
                    break;
                
                default:
                cout<<"Enter correct choice."<<endl;
            }
        }
        while(c!=3);       
    }
};
int main() 
{
    playlist myPlaylist;
    int choice;

        cout << "\nPlaylist of Song:\n";
        cout << "1.Add song at End\n";
        cout << "2.Add song at beginning\n";
        cout << "3.Display playlist\n";
        cout << "4.Remove the song\n";
        cout << "5.Insert song after another\n";
        cout << "6.Update Information\n";
        cout << "7.Exit\n";
        
    do 
    {   
        cout <<"Profile :- Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                myPlaylist.insert_end();
                break;

            case 2:
                myPlaylist.insert_begin();
                break;

            case 3:
                myPlaylist.display_playlist();
                break;

            case 4:
                myPlaylist.delete_song();
                break;
                
            case 5:
                myPlaylist.insert_at_kposition();
                break;

            case 6:
                myPlaylist.update();
                break;
                
            case 7:
                cout << "Exit.." << endl;
                break;

            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}