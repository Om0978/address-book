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

    // function to edit contact
    void editContact(string newFirstName, string newLastName, string newAddress, string newCity, string newState, string newEmail, int newZip, long long newPhoneNumber)
    {
        this->firstName = newFirstName;
        this->lastName = newLastName;
        this->address = newAddress;
        this->city = newCity;
        this->state = newState;
        this->email = newEmail;
        this->zip = newZip;
        this->phoneNumber = newPhoneNumber;
        cout << "\ncontact updat successfully!\n";
    }
};

class addressBook
{
    vector<contact> contacts;

public:
    // uc2
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
        contacts.push_back(newContact);                                                         // add contact to vector
    }

    void display()
    {
        if (contacts.empty())
        {
            cout << "\naddress book is empty !\n";
        }
        else
        {
            for (auto i : contacts)
            {

                cout << "-------------------------------\n";
                i.displayContact();
                cout << "-------------------------------\n";
            }
        }
    }

    // UC3
    void editContactByName(string firstName, string lastName)
    {
        for (int i = 0; i < contacts.size(); i++)
        {
            if (contacts[i].firstName == firstName && contacts[i].lastName == lastName)
            {
                cout << "\n edit contact of " << firstName << " " << lastName << endl;

                string newFirstName, newLastName, newAddress, newCity, newState, newEmail;
                int newZip;
                long long newPhoneNumber;

                cout << "enter new first name\n";
                cin >> newFirstName;

                cout << "enter new last name\n";
                cin >> newLastName;

                cout << "enter new address\n";
                cin.ignore();
                getline(cin, newAddress);

                cout << "enter new city\n";
                cin >> newCity;

                cout << "enter new state\n";
                cin >> newState;

                cout << "enter new email\n";
                cin >> newEmail;

                cout << "enter new zip code\n";
                cin >> newZip;

                cout << "enter new phone number\n";
                cin >> newPhoneNumber;

                contacts[i].editContact(newFirstName, newLastName, newAddress, newCity, newState, newEmail, newZip, newPhoneNumber);
                return;
            }
        }
        cout << "contact not found !";
    }

    // UC4
    void deleteContactByName()
    {
        string fName, lName;
        cout << "\nenter the first name of contact to delete\n";
        cin >> fName;
        cout << "\nenter the last name of contact to delete\n";
        cin >> lName;
        for (int i = 0; i < contacts.size(); i++)
        {
            if (contacts[i].firstName == fName && contacts[i].lastName == lName)
            {
                contacts.erase(contacts.begin() + i);
                cout << "\ncontact of " << fName << " " << lName << " delete successfully!\n";
                return;
            }
        }
        cout << "contact not found !";
    }
};

int main()
{
    // welcome message
    cout << "Welcome to Address Book Program\n";

    addressBook addressbook;

    int choice = -1; // choice take from user to perform multiple operations

    while (choice != 0)
    {
        cout << "0. Exit\n";
        cout << "1. add a new contact\n";
        cout << "2. display all contacts\n";
        cout << "3. edit an existing contact\n";
        cout << "4. delete an existing contact\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0)
        {
            cout << "exit the program";
        }

        else if (choice == 1)
        {
            addressbook.addContact();
        }
        else if (choice == 2)
        {
            addressbook.display();
        }
        else if (choice == 3)
        {
            string fName, lName;
            cout << "\nenter the first name of contact to edit\n";
            cin >> fName;
            cout << "\nenter the last name of contact to edit\n";
            cin >> lName;
            addressbook.editContactByName(fName, lName);
        }
        else if (choice == 4)
        {
            addressbook.deleteContactByName();
        }
    }

    return 0;
}