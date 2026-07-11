#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class UserSystem
{
private:
    string username, password;

public:
    bool usernameExists(string user)
    {
        ifstream file("users.txt");

        string u, p;

        while (file >> u >> p)
        {
            if (u == user)
            {
                file.close();
                return true;
            }
        }

        file.close();
        return false;
    }

    void registerUser()
    {
        cout << "\n========== USER REGISTRATION ==========\n";

        cout << "Enter Username: ";
        cin >> username;

        if (usernameExists(username))
        {
            cout << "\nUsername already exists! Try another username.\n";
            return;
        }

        cout << "Enter Password: ";
        cin >> password;

        ofstream file("users.txt", ios::app);

        file << username << " " << password << endl;

        file.close();

        cout << "\nRegistration Successful!\n";
    }

    void loginUser()
    {
        cout << "\n========== USER LOGIN ==========\n";

        cout << "Enter Username: ";
        cin >> username;

        cout << "Enter Password: ";
        cin >> password;

        ifstream file("users.txt");

        string u, p;
        bool found = false;

        while (file >> u >> p)
        {
            if (u == username && p == password)
            {
                found = true;
                break;
            }
        }

        file.close();

        if (found)
        {
            cout << "\nLogin Successful! Welcome " << username << "!\n";
        }
        else
        {
            cout << "\nInvalid Username or Password!\n";
        }
    }

    void showUsers()
    {
        ifstream file("users.txt");

        string u, p;

        cout << "\n========== REGISTERED USERS ==========\n";

        if (!file)
        {
            cout << "No users registered yet.\n";
            return;
        }

        while (file >> u >> p)
        {
            cout << "Username : " << u << endl;
        }

        file.close();
    }
};

int main()
{
    UserSystem user;

    int choice;

    do
    {
        cout << "\n====================================";
        cout << "\n LOGIN & REGISTRATION SYSTEM";
        cout << "\n====================================";
        cout << "\n1. Register";
        cout << "\n2. Login";
        cout << "\n3. View Registered Users";
        cout << "\n4. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            user.registerUser();
            break;

        case 2:
            user.loginUser();
            break;

        case 3:
            user.showUsers();
            break;

        case 4:
            cout << "\nThank You!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 4);

    return 0;
}