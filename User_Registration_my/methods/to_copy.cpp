#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void change_password(string id, string pass) // storing the username/id and new_password
{
    /*the approach used to change the existing password is

    1st)we'll feach all the recoed from the register.txt
    except the user which we have to change the password
    and kept it to a new txt file named duplicate.txt

    2nd) we're open the register.txt in IOS::IN mode so no data will
    remove and duplicat_register.txt in IOS:: OUT so every time we got the
    duplicate_register.txt as empty

    */
    ifstream to_read;
    to_read.open("register.txt", ios::in);
    ofstream to_write("duplicate_register.txt");
    if (!to_read.is_open())
        cout << "the input file is'nt open";
    if (!to_write.is_open())
        cout << "the outfile file is'nt open";

    string line; // this string will fetch the data from register to put it in duplicate
    while (getline(to_read, line))
    {
        if (line.find(id)) // if id==username it will skip the record the username which has to
        // change the password in that sense in duplicate we'll all the records except tht
        {
            to_write << line << "\n"; // writing the content in duplicate.txt
        }
    }
    to_write.close();
    to_read.close();

    /*from here we're doing reverse the process
    1st) opening the duplicate.txt in IOS::IN MODE so data dont loss and register in IOS::OUT so all the data will vanish and register.txt is empty
    2nd) fetch the data from duplicate.txt to put it back in register.txt but this time
    register.txt hasn't the record of the user which has to change password
    */

    ifstream to_read_new("duplicate_register.txt");
    ofstream to_write_new("register.txt");
    while (getline(to_read_new, line)) // fetch the data from duplicate.txt
    {
        to_write_new << line << "\n"; // putiing the data in register.txt
    }
    cout << "\n";

    to_read_new.close();
    to_write_new.close();

    // till the above we have a register.txt in which we have a missing record of the user
    // which has to change the password
    // below we're again opening the register.txt in IOS::APP mode to append the data
    ofstream obj1;
    obj1.open("register.txt", ios::app);
    obj1 << id << " " << pass << "\n";
    obj1.close();
}