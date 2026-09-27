#include <iostream.h>
#include <string.h>
#include <conio.h>
#include <stdio.h>

class Book {
private:
    char bookID[20];
    char title[100];
    char author[100];
    char publisher[100];
    char isbn[20];

public:
    void setBookID(char id[]) { strcpy(bookID, id); }
    void setTitle(char t[]) { strcpy(title, t); }
    void setAuthor(char a[]) { strcpy(author, a); }
    void setPublisher(char p[]) { strcpy(publisher, p); }
    void setIsbn(char i[]) { strcpy(isbn, i); }

    char* getBookID() { return bookID; }
    char* getTitle() { return title; }
    char* getAuthor() { return author; }
    char* getPublisher() { return publisher; }
    char* getIsbn() { return isbn; }
};

int main() {
    clrscr();

    int numBooks = 2;
    Book books[2]; 
    char tempID[20], tempTitle[100], tempAuthor[100], tempPublisher[100], tempIsbn[20];

    for (int i = 0; i < numBooks; i++) {
        cout << "Enter details of Book " << (i + 1) << "\n\n";
        
        cout << "Enter Book ID: ";
        gets(tempID);
        books[i].setBookID(tempID);

        cout << "Enter Book Title: ";
        gets(tempTitle);
        books[i].setTitle(tempTitle);

        cout << "Enter Author Name: ";
        gets(tempAuthor);
        books[i].setAuthor(tempAuthor);

        cout << "Enter Publisher: ";
        gets(tempPublisher);
        books[i].setPublisher(tempPublisher);

        cout << "Enter ISBN: ";
        gets(tempIsbn);
        books[i].setIsbn(tempIsbn);
        
        cout << "\n";
    }

    char searchQuery[100];
    cout << "Enter Title, Author, Book ID or ISBN to search: ";
    gets(searchQuery);
    cout << "\n";

    int found = 0;

    for (int j = 0; j < numBooks; j++) {
        if (strcmp(books[j].getTitle(), searchQuery) == 0 || 
            strcmp(books[j].getAuthor(), searchQuery) == 0 || 
            strcmp(books[j].getBookID(), searchQuery) == 0 || 
            strcmp(books[j].getIsbn(), searchQuery) == 0) {
            
            cout << "Book ID    : " << books[j].getBookID() << "\n";
            cout << "Title      : " << books[j].getTitle() << "\n";
            cout << "Author     : " << books[j].getAuthor() << "\n";
            cout << "Publisher  : " << books[j].getPublisher() << "\n";
            cout << "ISBN       : " << books[j].getIsbn() << "\n";
            
            found = 1;
            break;
        }
    }

    if (found == 0) {
        cout << "No book found matching that information.\n";
    }

    getch();
    return 0;
}