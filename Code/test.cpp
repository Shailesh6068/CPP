#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    fstream file("Test.txt", ios::in | ios::out | ios::trunc); // Open file for input and output, truncating existing content

    if (!file.is_open()) // Check if the file opened successfully
    {
        cout << "Error opening file." << endl;
        return 1;
    }

    file << "My name is Ram." << endl; // Write to the file

    file.seekg(0); // Move file pointer to the beginning for reading

    char ch;
    while (file.get(ch)) // Read characters until end of file
    {
        cout << ch;
    }

    file.close(); // Close the file stream

    return 0;
}
