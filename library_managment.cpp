#include <iostream>
#include <string>
using namespace std;

// Book Node
struct Book {
    string title;
    string author;
    string isbn;
    bool isAvailable;
    Book* next;
};

// Linked List Head
Book* head = NULL;

// Function to Add a Book
void addBook(string title, string author, string isbn) {
    Book* newBook = new Book{title, author, isbn, true, NULL};
    if (!head) {
        head = newBook;
    } else {
        Book* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newBook;
    }
    cout << "Book added successfully!\n";
}

// Function to Remove a Book by ISBN
void removeBook(string isbn) {
    Book* temp = head;
    Book* prev = NULL;

    while (temp && temp->isbn != isbn) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        cout << "Book not found!\n";
        return;
    }

    if (!prev)
        head = head->next;
    else
        prev->next = temp->next;

    delete temp;
    cout << "Book removed successfully!\n";
}

// Function to Search Books by Title or Author
void searchBook(string keyword) {
    Book* temp = head;
    bool found = false;

    while (temp) {
        if (temp->title.find(keyword) != string::npos ||
            temp->author.find(keyword) != string::npos) {
            cout << "Title: " << temp->title << "\nAuthor: " << temp->author
                 << "\nISBN: " << temp->isbn
                 << "\nAvailable: " << (temp->isAvailable ? "Yes" : "No") << "\n\n";
            found = true;
        }
        temp = temp->next;
    }

    if (!found)
        cout << "No matching books found.\n";
}

// Function to Display All Books
void displayBooks() {
    if (head==NULL) {
        cout << "Library is empty.\n";
        return;
    }
    Book* temp = head;
    while (temp) {
        cout << "Title: " << temp->title
             << "\nAuthor: " << temp->author
             << "\nISBN: " << temp->isbn
             << "\nAvailable: " << (temp->isAvailable ? "Yes" : "No") << "\n\n";
        temp = temp->next;
    }
}

// Function to Toggle Availability by ISBN
void checkOutOrReturnBook(string isbn) {
    Book* temp = head;
    while (temp) {
        if (temp->isbn == isbn) {
            temp->isAvailable = !temp->isAvailable;
            cout << "Book status updated to: "
                 << (temp->isAvailable ? "Available" : "Borrowed") << "\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Book not found!\n";
}

// Menu
void menu() {
    int choice;
    string title, author, isbn, keyword;

    do {
        cout << "\n--- Library Management System ---\n";
        cout << "1. Add Book\n2. Remove Book\n3. Search Book\n4. Display All Books\n5. Check Out/Return Book\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); // Clear input buffer

        switch (choice) {
            case 1:
                cout << "Enter title: ";
                getline(cin, title);
                cout << "Enter author: ";
                getline(cin, author);
                cout << "Enter ISBN: ";
                getline(cin, isbn);
                addBook(title, author, isbn);
                break;
            case 2:
                cout << "Enter ISBN to remove: ";
                getline(cin, isbn);
                removeBook(isbn);
                break;
            case 3:
                cout << "Enter title or author to search: ";
                getline(cin, keyword);
                searchBook(keyword);
                break;
            case 4:
                displayBooks();
                break;
            case 5:
                cout << "Enter ISBN to check out/return: ";
                getline(cin, isbn);
                checkOutOrReturnBook(isbn);
                break;
            case 0:
                cout << "Exiting system.\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);
}

int main() {
    menu();
    return 0;
}
