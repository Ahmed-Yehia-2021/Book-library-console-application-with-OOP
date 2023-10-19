//
// Created by Ahmed.Yehia on 9/22/2022.
//

#include "Book.h"
#include "User.h"

int Book :: count = 0;

Book :: Book(){
    title = "Unknown";
    isbn = "Unknown";
    count++;
    id = count;
    category = "Unknown";
    averageRating = 0.0;
    User author; // Why I can't write (author) without (User)
    numRate = 0;
    sumRate = 0;
}

Book :: Book(string title, string isbn, string category){
    this->title = title;
    this->isbn = isbn;
    this->category = category;
    count++;
    id = count;
    averageRating = 0.0;
    User author; // Why I can't write (author) without (User)
    numRate = 0;
    sumRate = 0;
}

Book :: Book( const Book &b ){
    title = b.title;
    category = b.category;
    isbn = b.isbn;
    id = b.id;
    averageRating = b.averageRating;
    numRate = b.numRate;
    sumRate = b.sumRate;
    author = b.author;
}

void Book :: setTitle(string title){ this->title = title; }
string Book :: getTitle() const { return title; }

void Book :: setIsbn(string isbn){ this->isbn = isbn; }
string Book :: getIsbn() const { return isbn; }

void Book :: setId(int id){ this->id = id; }
int Book :: getId() const { return id; }

void Book :: setCategory(string category){ this->category = category; }
string Book :: getCategory() const { return category; }

void Book :: setAuthor( const User &us ){ author = us; }
User Book :: getAuthor() { return author; }

void Book :: setAvgRating(double rate){
    sumRate += rate;
    numRate++;
    averageRating = sumRate / numRate;
}
double Book :: getAvgRating() const { return averageRating; }

bool Book :: operator==(const Book &b){
    if( title==b.title && isbn==b.isbn && id==b.id && category==b.category
    && averageRating==b.averageRating && author==b.author ){
        return true;
    }
    return false;
}

istream &operator>>( istream &input, Book &b ){
    cout<<"\nEnter the data of book_"<<b.id<<" :\n";
    cout<<" Title : ";      input>>b.title;
    cout<<"Isbn : ";       input>>b.isbn;
    cout<<"Category : ";   input>>b.category;
    return input;
}
ostream &operator<<( ostream &output, const Book &b ){
    output<<"\n========================================================\n";
    output<<"The data of book_"<<b.id<<" :\n";
    output<<"Title : "<<b.title<<endl;
    output<<"Category : "<<b.category<<endl;
    output<<"Isbn : "<<b.isbn<<endl;
    output<<"ID : "<<b.id<<endl;
    output<<"Average Rating : "<<b.averageRating<<endl;
    if( b.author.getName()!="Unknown" ){ output<<b.author; }
    output<<"\n========================================================\n";
    return output;
}









