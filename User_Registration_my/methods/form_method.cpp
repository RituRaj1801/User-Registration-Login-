#include <iostream>
#include <fstream>
#include <string>
#include "to_copy.cpp"
using namespace std;
void reg(string, string);
void log(string, string);
void forget();

// this function will take the username and password and save in file called register
void reg(string id, string pass)
{
    ofstream obj;
    obj.open("register.txt", ios::app);
    obj << id << " " << pass << "\n";
    obj.close();
    cout << "REGISTRATION IS SUCCESSFULLY DONE\n";
}

// this fucntion will take the username and password for authentication
void log(string id, string pass)
{
    int count = 0, key = 0;
    string userid, password; // taking user name
    ifstream in;             // object for reading the register.txt
    in.open("register.txt");
    while (in >> userid >> password) // loading each line as userid and password
    {
        if (userid == id && password == pass) // checking the authentication
        {
            count++; // userfound
            break;
        }
    }
    in.close();

    if (count == 1)
        cout << "LOGIN SUCCESSFULLY DONE\n"; // printing the message

    else // if password is wrong
    {
        cout << "ENTERED USERNAME/ID OR PASSWORD IS WRONG\n";
        cout << "\nwant to reset your username/id  OR password\nIF YES PRESS: 1 ELSE 0: ";
        cin >> key;
        if (key == 1)
            forget(); // calling the forget method to change the password
    }
}

void forget()
{
    ifstream to_read; // reading from register,txt
    to_read.open("register.txt");
    string id, username, password, new_password;
    int count = 0;
    cout << "enter your username/id: "; // enter the username
    cin >> id;

    // this while loop will check either the entered username is exist in
    // our register.txt file or not
    while (to_read >> username >> password)
    {
        if (id == username)
        {
            cout << "USER FOUND\n ENTER YOUR NEW PASSWORD: "; // if username found in record
            cin >> new_password;                              // enter newpassword
            count++;
            change_password(username, new_password); // calling the change_password to update the password of the user having aruguments as new_password and her/his id/username
            cout << "PASSWORD RESET SUCCESSFULLY\n\n";
            break;
        }
    }
    to_read.close();

    if (count != 1) // if count is still 0 it mean there is no id/username in our record
        cout << "USERNAME/ID not found";
}