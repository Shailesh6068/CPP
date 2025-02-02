#include <iostream>
#include <stack>
using namespace std;

class node {
public:
    node *next;
    string cato;
    string pay_method;
    int amount;

    node() {
        next = nullptr;
        amount = 0;
        cato = "NA";
    }

    void paymethod() {
        int n;
        cout << "1: Cash" << "                      2: Debit Card\n"
             << "3: Credit Card" << "               4: Online" << endl;
        cout << "Choice: ";
        cin >> n;

        switch (n) {
        case 1:
            pay_method = "Cash";
            break;
        case 2:
            pay_method = "Debit Card";
            break;
        case 3:
            pay_method = "Credit Card";
            break;
        case 4:
            pay_method = "Online";
            break;
        default:
            cout << "Incorrect Choice..." << endl;
            paymethod(); 
            break;
        }
    }

    void read() {
        cout << "\nSelect the payment method (e.g. Cash, Credit/Debit card, Online):\n";
        paymethod();
        cout << "Enter the type of transaction (e.g. Electricity, Grocery): ";
        cin.ignore();
        getline(cin, cato);
        cout << "Enter the amount (Rs.): ";
        cin >> amount;
    }

    void display() {
        cout << "Payment Method: " << pay_method << endl;
        cout << "Type of Transaction: " << cato << endl;
        cout << "Amount: Rs. " << amount << endl;
        cout << "\n--------------------------------------------------------------------\n";
    }
};

class Financial_data {
public:
    node *front;
    node *tail;
    static int size;

    Financial_data() {
        front = nullptr;
        tail = nullptr;
        size = 0; // Initialize size to 0
    }

    void is_empty() {
        if (front == nullptr) {
            cout << "Currently, there are no pending payments!\n" << endl;
        } else {
            cout << size << " transactions are currently awaiting processing!\n";
        }
    }

    void Addpayment_queue() {
        node *new_node = new node;
        new_node->read();
        if (front == nullptr) {
            front = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
        size++;
    }

    void delete_node() {
        if (front == nullptr) {
            cout << "Currently, there are no pending payments!\n" << endl;
            return;
        }
        node *temp = front;
        front = front->next;
        if (front == nullptr) {
            tail = nullptr; // If the list becomes empty, update tail
        }
        cout << "Payment of Rs. " << temp->amount << " for " << temp->cato << " has been successfully processed!\n";
        delete temp;
        size--;
    }

    void process_payment() {
        long long int card_number;
        int cvv, upi_pin;
        node *temp = front;

        if (temp == nullptr) {
            cout << "Currently, there are no pending payments!\n" << endl;
            return;
        }

        if (temp->pay_method == "Cash") {
            delete_node();
        } else if (temp->pay_method == "Debit Card") {
            cout << "Enter the Debit Card Number: ";
            cin >> card_number;
            cout << "Enter the CVV Number (Card Verification Value): ";
            cin >> cvv;
            delete_node();
        } else if (temp->pay_method == "Credit Card") {
            cout << "Enter the Credit Card Number: ";
            cin >> card_number;
            cout << "Enter the CVV Number (Card Verification Value): ";
            cin >> cvv;
            delete_node();
        } else if (temp->pay_method == "Online") {
            cout << "Enter UPI Pin: ";
            cin >> upi_pin;
            delete_node();
        }
    }

    void pending_payment() {
        node *temp = front;
        cout << "--------------------------------------------------------------------" << endl;
        cout << "               *****    Payment Queue Status    *****               " << endl;
        cout << "--------------------------------------------------------------------" << endl;

        if (size == 0) {
            cout << "                      || No pending payments ||                     " << endl;
            return;
        }
        
        while (temp != nullptr) {
            temp->display();
            temp = temp->next;
        }
    }
};
int Financial_data::size = 0;
int main() {
    int n;
    Financial_data fd;
    cout << "The Choices are:" << endl;
    cout << "1: Add Payment." << endl
         << "2: Check whether the payments are present or not." << endl
         << "3: View Pending Payments." << endl
         << "4: Process Payment." << endl
         << "5: Exit." << endl;

    while (true) {
        cout << "\nEnter the choice: ";
        cin >> n;
        switch (n) {
        case 1:
            fd.Addpayment_queue();
            break;
        case 2:
            fd.is_empty();
            break;
        case 3:
            fd.pending_payment();
            break;
        case 4:
            fd.process_payment();
            break; 
        case 5:
            exit(0);
        default:
            cout << "Incorrect Choice...!\n";
        }
    }
    return 0;
}
