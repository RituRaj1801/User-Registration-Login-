#include <iostream>
#include <string>
#include <fstream>
#include "methods/form_method.cpp"

using namespace std;
int main()
{
    int choice;
    string id, pass;
    cout << "\t\t\tWELCOME TO LOGIN AND REGISTER PAGE\n";
    cout << "press 1 for register:\n ";
    cout << "press 2 for login :\n ";
    cout << "press 3 to exit :\n";
    cout << "\t\tenter your choice: ";
    cin >> choice;
    if (choice == 1)
    {
        cout << "enter your your username: ";
        cin >> id;
        cout << "enter your password: ";
        cin >> pass;
        reg(id, pass); // defined in folder method/ form_method.cpp
    }
    else if (choice == 2)
    {
        cout << "enter your username/id for login: ";
        cin >> id;
        cout << "now enter your password: ";
        cin >> pass;
        log(id, pass); // defined in folder method/ form_method.cpp
    }
    else
    {
        cout << "\nTHANKS FOR BEING HERE ,SEE YOU LATER\n";
        exit(0);
    }
    main();
    return 0;
}
