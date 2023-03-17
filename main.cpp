#include <iostream>
#include <fstream>
#include <vector>

class Book {
    
private:
    std::string title;
    
    std::string author;
    
    int year;
    
    static int totalBooks; // Static variable to keep track of total number of books
    
    
public:
    Book(std::string t, std::string a, int y) {
        title = t;
        author = a;
        year = y;
        totalBooks++;
    }

    ~Book() {
        totalBooks--;
    }

    static void printTotalBooks() {
        std::cout << "Total books in library: " << totalBooks << std::endl;
    }

    void printDetails() {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "Year: " << year << std::endl;
    }

    std::string getTitle() {
        return title;
    }

    std::string getAuthor() {
        return author;
    }

    int getYear() {
        return year;
    }
};

int Book::totalBooks = 0;

void saveBooksToFile(std::vector<Book> books) {
    std::ofstream outfile;
    outfile.open("library_books.txt");
    for (Book book : books) {
        outfile << book.getTitle() << "," << book.getAuthor() << "," << book.getYear() << std::endl;
    }
    outfile.close();
}

int main() {
    std::vector<Book> books;

    Book book1("The Great Gatsby", "F. Scott Fitzgerald", 1925);
    Book book2("To Kill a Mockingbird", "Harper Lee", 1960);
    Book book3("1984", "George Orwell", 1949);

    books.push_back(book1);
    books.push_back(book2);
    books.push_back(book3);

    std::cout << "Initial library books:" << std::endl;
    for (Book book : books) {
        book.printDetails();
        std::cout << std::endl;
    }

    Book::printTotalBooks();
    std::cout << std::endl;

    // Add new book
    Book book4("The Catcher in the Rye", "J.D. Salinger", 1951);
    books.push_back(book4);

    std::cout << "Library books after adding a new book:" << std::endl;
    for (Book book : books) {
        book.printDetails();
        std::cout << std::endl;
    }

    Book::printTotalBooks();
    std::cout << std::endl;

    // Modify existing book
    books[2] = Book("Animal Farm", "George Orwell", 1945);

    std::cout << "Library books after modifying a book:" << std::endl;
    for (Book book : books) {
        book.printDetails();
        std::cout << std::endl;
    }

    Book::printTotalBooks();
    std::cout << std::endl;

    // Delete existing book
    books.erase(books.begin() + 1);

    std::cout << "Library books after deleting a book:" << std::endl;
    for (Book book : books) {
        book.printDetails();
        std::cout << std::endl;
    }

    Book::printTotalBooks();

    // Save books to file
    saveBooksToFile(books);

    return 0;
}
