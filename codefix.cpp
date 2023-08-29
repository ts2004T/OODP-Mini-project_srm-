#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book {
public:
    Book(string title, string author) {
        this->title = title;
        this->author = author;
    }
    string getTitle() {
        return title;
    }
    string getAuthor() {
        return author;
    }
private:
    string title;
    string author;
};

class Library {
public:
    void addBook(string title, string author) {
        Book newBook(title, author);
        books.push_back(newBook);
    }
    void displayBooks() {
        cout << "List of Books:" << endl;
        for (int i = 0; i < books.size(); i++) {
            cout << i + 1 << ". " << books[i].getTitle() << " by " << books[i].getAuthor() << endl;
        }
    }
    bool issueBook(string title) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].getTitle() == title) {
                cout << "Book issued: " << books[i].getTitle() << " by " << books[i].getAuthor() << endl;
                books.erase(books.begin() + i);
                return true;
            }
        }
        return false;
    }
private:
    vector<Book> books;
};

class Admin {
public:
    static void admin_menu(Library& library) {
        int choice;
        string title, author;
        do {
            cout << "\nSelect an option:" << endl;
            cout << "1. Add a book" << endl;
            cout << "2. Display all books" << endl;
            cout << "3. Issue a book" << endl;
            cout << "4. Exit" << endl;
            cin >> choice;
            cin.ignore(); // Consume newline character
            switch (choice) {
                case 1:
                    cout << "Enter book title: ";
                    getline(cin, title);
                    cout << "Enter book author: ";
                    getline(cin, author);
                    library.addBook(title, author);
                    break;
                case 2:
                    library.displayBooks();
                    break;
                case 3:
                    cout << "Enter book title to issue: ";
                    getline(cin, title);
                    if (library.issueBook(title)) {
                        cout << "Book issued." << endl;
                    } else {
                        cout << "Book not available or not found." << endl;
                    }
                    break;
                case 4:
                    cout << "Exiting admin menu..." << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } while (choice != 4);
    }
};

int main() {
    Library library;
    int choice;
    string title, author, studentName;
    do {
        cout << "Select an option:" << endl;
        cout << "1. Add a book" << endl;
        cout << "2. Display all books" << endl;
        cout << "3. Issue a book" << endl;
        cout << "4. Admin menu" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;
        cin.ignore(); // Consume newline character
        switch (choice) {
            case 1:
                cout << "Enter book title: ";
                getline(cin, title);
                cout << "Enter book author: ";
                getline(cin, author);
                library.addBook(title, author);
                break;
            case 2:
                library.displayBooks();
                break;
            case 3:
                cout << "Enter book title: ";
                getline(cin, title);
                if (library.issueBook(title)) {
                    cout << "Book issued." << endl;
                } else {
                    cout << "Book not available or not found." << endl;
                }
                break;
            case 4:
                Admin::admin_menu(library);
                break;
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);
    return 0;
}
