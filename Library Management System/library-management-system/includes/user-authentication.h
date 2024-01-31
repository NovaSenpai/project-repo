#include <fstream>
#include <string>

using namespace std;

const string DATABASE_FILE = "user_database.txt";

struct User {
    string username;
    string password;
};

void saveUser(const User& user) {
    ofstream database(DATABASE_FILE, ios::app);
    if (database.is_open()) {
        database << user.username << " " << user.password << endl;
        cout << "User successfully registered!" << endl;
        database.close();
    } else {
        cerr << "Error opening the database file." << endl;
    }
}

bool authenticateUser(const string& username, const string& password) {
    ifstream database(DATABASE_FILE);
    if (database.is_open()) {
        string storedUsername, storedPassword;
        while (database >> storedUsername >> storedPassword) {
            if (storedUsername == username && storedPassword == password) {
                database.close();
                return true; // Authentication successful
            }
        }
        database.close();
    }
    return false; // Authentication failed
}
