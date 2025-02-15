#include <iostream>
#include <vector>
#include <string>

using namespace std;

class contact
{
public:
    string firstName, lastName, address, city, state, email;
    int zip;
    long long phoneNumber;

    // constructor for initialize variables
    contact(string firstName, string lastName, string address, string city, string state, string email, int zip, long long phone)
    {
        this->firstName = firstName;
        this->lastName = lastName;
        this->address = address;
        this->city = city;
        this->state = state;
        this->email = email;
        this->zip = zip;
        this->phoneNumber = phone;
    }

    // function to display contact
    void displayContact()
    {
        cout << "\ncontact details : \n";
        cout << "name : " << firstName << " " << lastName << endl;
        cout << "address : " << address << ", " << city << ", " << state << "-" << zip << endl;
        cout << "phone : " << phoneNumber << endl;
        cout << "email : " << email << endl;
    }
};

// UC2
class addressBook
{
    vector<contact> contacts;

public:

// function to take input from user and add to address book
    void addContact()
    {
        // contact details variables
        string firstName, lastName, address, city, state, email;
        int zip;
        long long phoneNumber;

        // take inputs from user
        cout << "enter first name \n";
        cin >> firstName;

        cout << "enter last name \n";
        cin >> lastName;

        cout << "enter address \n";
        cin.ignore();
        getline(cin, address);

        cout << "enter city \n";
        cin >> city;

        cout << "enter state \n";
        cin >> state;

        cout << "enter email \n";
        cin >> email;

        cout << "enter zip code \n";
        cin >> zip;

        cout << "enter phone number \n";
        cin >> phoneNumber;

        contact newContact(firstName, lastName, address, city, state, email, zip, phoneNumber); // call contact class constructor to make new data
        contacts.push_back(newContact); // add contact to vector
    }

// function to display contacts
    void display(){
        if(contacts.empty()){
            cout<<"\naddress book is empty !\n";
        }
        else{
            for (auto i : contacts){

                cout<<"-------------------------------\n";
                i.displayContact();
                cout<<"-------------------------------\n";
            }
        }
    }
};

int main()
{
    // welcome message
    cout << "Welcome to Address Book Program\n";

    addressBook addressbook;
    addressbook.addContact();
    addressbook.display();

    return 0;
}
