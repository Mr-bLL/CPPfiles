#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Login {
private:
    unordered_map<string, string> users; // Map to store email-password pairs
    float dollars = 0; // Balance for each user

public:
    string name;
    string lastName;
    int age;
    string email;
    string password;
    int phone;
    string greeting;

    void questions() {
        users.clear();
        dollars=0;
        while (true) {
            cout << "Hello and welcome to our AI-powered ATM" << endl;
            cout << "Create new Account? (yes/no/login): ";
            cin >> greeting;

            if (greeting == "yes" || greeting == "YES" || greeting == "Yes") {
                signup();
            } else if (greeting == "login" || greeting == "Login" || greeting == "LOGIN") {
                if (login()) {
                    transiction();
                }
            } else {
                break;  // Exit the loop if user chooses to exit
            }
        }
    }

    void signup() {
        cout << "Name: ";
        cin >> name;
        cout << "Last Name: ";
        cin >> lastName;
        cout << "Age: ";
        cin >> age;
        cout << "Email: ";
        cin >> email;
        cout << "Password: ";
        cin >> password;
        cout << "Phone: ";
        cin >> phone;

        if (password.length() > 8 && name != lastName && age >= 18) {
            users[email] = password; // Add user to the map
            accountcreated();
        }
    }

    void accountcreated() {
        cout << "Congratulations! Your account has been created successfully." << endl;
    }

    bool login() {
        string lemail;
        string lpassword;
        cout << "Email: ";
        cin >> lemail;
        cout << "Password: ";
        cin >> lpassword;

        if (users.find(lemail) != users.end() && users[lemail] == lpassword) {
            cout << "Login successful. Welcome, " << name << "!" << endl;
            return true;
        } else {
            cout << "Login failed. Please try again." << endl;
            return false;
        }
    }

    void transiction() {

        cout << "You Have " << dollars << "$ in your account" << endl;
        string choice;
        cout << "Add money or take money or View balance ? (add/take/exit/balance): ";
        cin >> choice;
        float value = 0; // Define value outside of the if block
        if (choice == "add" || choice == "Add" || choice == "ADD") {
            cout << "How Much: ";
            cin >> value; // Use the value variable here
            if (value > 500) {
                cout << "Sorry but you cannot deposit more than 500 $ in a day." << endl;
            } else if (value < 500 && value > 0) {
            dollars += value;
            cout << value << "$ have been added successfully to your account!" << endl;
        }
    } else if (choice == "take" || choice == "Take" || choice == "TAKE") {
        float much;
        cout << "How much You wanna take? ";
        cin >> much;
        float secondvalue = dollars - much; // Use the balance in the calculation
        cout << much << "$ have been taken from your account" << endl;
        cout << "Your balance right now is " << secondvalue << "$" << endl;
        dollars = secondvalue; // Update the balance
    } else if (choice == "exit" || choice == "Exit" || choice == "EXIT") {
        // Exit the function, effectively restarting the loop for a new user
        return;
    }
    // Call transiction() again to allow the user to perform more actions
    transiction();
}


};

int main() {
    while (true) {
        Login myObj;
        myObj.questions();
    }
    return 0;
}

