//
// Created by Ahmed.Yehia on 9/22/2022.
//

#ifndef MAIN_CPP_BOOK_H
#define MAIN_CPP_BOOK_H

#include "User.h"

class Book {
private:
    string title;
    string isbn;
    int id;
    string category;
    double averageRating;
    User author;
    int numRate;
    double sumRate;
public:
    static int count;

    Book();
    Book(string, string, string);
    Book( const Book& );

    void setTitle(string);
    string getTitle() const;

    void setIsbn(string);
    string getIsbn() const;

    void setId(int);
    int getId() const;

    void setCategory(string);
    string getCategory() const;

    void setAuthor(const User&); // why const
    User getAuthor();

    void setAvgRating(double);
    double getAvgRating() const;

    bool operator==( const Book & );

    friend istream &operator>>( istream &, Book & );
    friend ostream &operator<<( ostream &, const Book & );
};


#endif //MAIN_CPP_BOOK_H
