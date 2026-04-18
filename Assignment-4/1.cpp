#include <iostream>
#include <cstring>
using namespace std;

class Book {
private:
    char *title;
    int pages;

public:
    //default constructor
    Book() {
        title = new char[1];
        title[0] = '\0';
        pages = 0;
    }

    //overloaded constructor
    Book(const char *t, int p) {
        title = new char[strlen(t) + 1];
        strcpy(title, t);
        pages = p;
    }

    //copy constructor
    Book(const Book &b) {
        title = new char[strlen(b.title) + 1];
        strcpy(title, b.title);
        pages = b.pages;
    }

    //assignment operator
    Book& operator=(const Book &b) {
        if (this != &b) {
            delete[] title;
            title = new char[strlen(b.title) + 1];
            strcpy(title, b.title);
            pages = b.pages;
        }
        return *this;
    }

    void read() {
        char temp[100];
        cout << "Enter Title: ";
        cin >> temp;
        delete[] title;
        title = new char[strlen(temp) + 1];
        strcpy(title, temp);

        cout << "Enter Pages: ";
        cin >> pages;
    }

    virtual void display() {
        cout << "Title: " << title << endl;
        cout << "Pages: " << pages << endl;
    }

    virtual ~Book() {
        delete[] title;
    }
};

class EBook : public Book {
private:
    double fileSizeMB;
    char *format;

public:
    //default constructor
    EBook() : Book() {
        fileSizeMB = 0;
        format = new char[1];
        format[0] = '\0';
    }

    //parameterized constructor
    EBook(const char *t, int p, double f, const char *fmt)
        : Book(t, p) {
        fileSizeMB = f;
        format = new char[strlen(fmt) + 1];
        strcpy(format, fmt);
    }

    //copy constructor
    EBook(const EBook &e) : Book(e) {
        fileSizeMB = e.fileSizeMB;
        format = new char[strlen(e.format) + 1];
        strcpy(format, e.format);
    }

    //assignment operator
    EBook& operator=(const EBook &e) {
        if (this != &e) {
            Book::operator=(e);
            fileSizeMB = e.fileSizeMB;

            delete[] format;
            format = new char[strlen(e.format) + 1];
            strcpy(format, e.format);
        }
        return *this;
    }

    void read() {
        Book::read();
        cout << "Enter File Size (MB): ";
        cin >> fileSizeMB;

        char temp[50];
        cout << "Enter Format: ";
        cin >> temp;

        delete[] format;
        format = new char[strlen(temp) + 1];
        strcpy(format, temp);
    }

    void display() {
        Book::display();
        cout << "File Size: " << fileSizeMB << " MB" << endl;
        cout << "Format: " << format << endl;
    }

    ~EBook() {
        delete[] format;
    }
};

int main() {
    EBook e1;
    e1.read();

    cout << "\nEBook Details:\n";
    e1.display();

    return 0;
}