//
// Created by Ahmed.Yehia on 9/28/2022.
//

#ifndef MAIN_CPP_BOOKLIST_H
#define MAIN_CPP_BOOKLIST_H

#include "Book.h"
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class BookList {
private:
    Book*books;
    int capacity;
    int booksCount;
public:
    BookList();
    BookList(int );

    User addBook(); // at the end of the array.

    Book* searchBook(string);
    Book* searchBook(int );

    void deleteBook(int ); //delete a book

    Book getTheHighestRatedBook();

    void getBooksForUser(const User &); // get all books of this author

    Book& operator[] (int );

    friend ostream&operator<<(ostream &,const BookList & ); //to display all books

    ~BookList();
};


#endif //MAIN_CPP_BOOKLIST_H
