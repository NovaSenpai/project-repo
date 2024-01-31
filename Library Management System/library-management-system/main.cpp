#include<iostream>
#include<iomanip> // for setw (set width)
#include<limits> // to ignore a full line in a stream
#include<algorithm> // to find max bw two numbers
#include<cctype> //for toupper and tolower
#include<fstream> // for input and outfile stream in a file
#include<chrono> // for animation
#include<thread> // for time delay
#include<Windows.h> // for sleep function

// included header files
#include "includes/user-authentication.h"
#include "includes/insert-books.h"
#include "includes/books-database.h"

int isbnToCheck=0; //global variable for isbn input

using namespace std;

void loadingScreen(int durationTime =25) {
    cout << "\n\t\t\t\t\t LOADING SCREEN, PLEASE WAIT\n";
    cout << "\t\t\t\t\t";

    for(int i=0; i<=28; i++) {
        cout<<"-";
        Sleep(150);
    }
    cout<< endl << "\t\t\t\t\t";
    system("pause");
    system("cls");
}

void menu() {
    cout << "\n\t1. Add Book\n";
    cout << "\n\t2. Search for Book Availability\n";
    cout << "\n\t3. Show All Books\n";
    cout << "\n\t4. Borrow a Book\n";
    cout << "\n\t5. Return a Book\n";
    cout << "\n\t6. Delete a Book\n";
    cout << "\n\t7. Exit\n";
}

void animateText(const string& text) { // for intro animation
    for (char c : text) {
        cout << c;
        this_thread::sleep_for(chrono::milliseconds(50));  // Adjust the delay as needed // uses thread and chrono library
    }
    cout << endl;
}

void animation() { // for animation
        cout<<"\n\n\t\t\t\t\t";
        
        string menuText = "Library Management System!"; // text to animate

        transform(menuText.begin(),menuText.end(),menuText.begin(), :: toupper); // to convert to upper case
        animateText(menuText);
}

int main() {
    int duration;

    loadingScreen(duration);

    bool isAuthenticated = false;
    LibraryCatalog library;
    fetchDataBase(library); // getting data from books-database.h

    int main_choice, authentication_choice, isbn;
    string bookName, authorName, bookType;


    do {
        animation();

        cout << "\n\n\t\t\t\t\tEnter Your username and password:\n";
        string username, password;

        cout << "\n\tEnter username: ";
        cin >> username;
        transform(username.begin(), username.end(), username.begin(), :: tolower); //if username is in upper case, it converts in to lower case
        cout << "\n\tEnter password: ";
        cin >> password;

        system("cls");

        isAuthenticated = authenticateUser(username, password);

        if (isAuthenticated) {
            cout << "Authentication successful!\n";
            int choice;

            do {
                menu();
                
                cout << "\n\tEnter your choice: ";
                cin >> choice;

                switch (choice) {
                    case 1: {
                    cout << "\n\tEnter ISBN Number: ";
                    cin >> isbn;
                    cin.ignore();
                    cout << "\n\tEnter Book Name :";
                    getline(cin, bookName);
                    transform(bookName.begin(),bookName.end(),bookName.begin(), :: toupper);
                    cout<<bookName;

                    cout << "\n\tEnter Author's Name :";
                    getline(cin, authorName);
                    transform(authorName.begin(),authorName.end(),authorName.begin(), :: tolower);
                    cout << "\n\tEnter Book Type :";
                    getline(cin, bookType);
                    transform(bookType.begin(), bookType.end(), bookType.begin(), :: tolower);

                    library.insert(isbn, bookName, authorName, bookType);
                    library.saveToFile("libraryData.txt"); //saving data to file
                    break;
                }
                    case 2: {
                        system("cls");
                        cout << "Enter ISBN Number to Check for Availablity Status\n";
                        cin>>isbnToCheck;
                        library.availability(isbnToCheck);
                        break;
                    }
                    case 3: {
                        system("cls");
                        library.printTree();
                        break;
                    }
                    case 4: {
                        system("cls");
                        cout<<"Enter ISBN Number of the Book: ";
                        cin>>isbnToCheck;
                        library.bookBorrow("libraryData.txt", isbnToCheck);
                        break;
                    }
                    case 5: {
                        system("cls");
                        cout<<"Enter ISBN Number of the Book: ";
                        cin>>isbnToCheck;
                        library.bookReturn("libraryData.txt", isbnToCheck);
                        break;
                    }
                    case 6: {
                        system("cls");
                        cout<<"Enter ISBN of Book yoou want to delete\n";
                        int isbn_To_Check;
                        cin>>isbn_To_Check;
                        library.deleteNode(isbn_To_Check);
                        break;
                    }
                    case 7: {
                        system("cls");
                        cout<<"Exited\n";
                        break;
                    }
                    default: // if choice is not valid
                        system("cls");
                        cout << "Invalid choice. Please try again.\n";
                }
            } while (choice != 7);
        } else {
            cout << "Authentication failed. Incorrect username or password.\n";
        }
    } while (!isAuthenticated);

    system("pause");
    return 0;
}