#include <iostream>
using namespace std;

class addressBook{
    public:
    void displayWelcome(){
        cout<<"Welcome to Address Book Program\n";
    }

};

int main(){
    addressBook obj1;
    obj1.displayWelcome();
}