//
// Created by Ahmed.Yehia on 9/28/2022.
//

#include "BookList.h"

BookList :: BookList() : capacity(0), booksCount(0) {}

BookList :: BookList(int capacity){
    this->capacity = capacity;
    books = new Book[capacity];
    booksCount = 0;
}

User BookList :: addBook(){
    if (booksCount < capacity) {
        cin>>books[booksCount];
        books[booksCount].setId(booksCount + 1);
        booksCount++;
        return books[booksCount].getAuthor();
    } else { cout << "The file is full.\n"; }
}

Book* BookList :: searchBook(string tl){
    for( int i=0 ; i<booksCount ; i++ ){
        if( books[i].getTitle() == tl ){ return &books[i]; }
    }
    return nullptr;
}

Book* BookList :: searchBook(int id){
    for( int i=0 ; i<booksCount ; i++ ){
        if( books[i].getId() == id ){ return &books[i]; }
    }
    return nullptr;
}

void BookList :: deleteBook(int id){
    for( int i=0 ; i<booksCount ; i++ )
        if( books[i].getId() == id ){
            while( i < booksCount-1 ){
                books[i] = books[i+1];
                books[i].setId(i+1);
                i++;
            }
            capacity--;
            booksCount--;
            return;
        }

    cout<<"This ID is not exist.\n";
}

Book BookList :: getTheHighestRatedBook(){
    int idx = 0;
    for( int i=1 ; i<booksCount ; i++ ){
        if( books[idx].getAvgRating() < books[i].getAvgRating() ){ idx = i; }
    }
    return books[idx];
}

void BookList :: getBooksForUser(const User &us){
    bool found = false;
    for( int i=0 ; i<booksCount ; i++ ){
        if( us == books[i].getAuthor() ){
            cout<<books[i];
            found = true;
        }// end if
    }// end for loop
    if( !found ){ cout<<"This author didn't have any book in our system.\n"; }
}

Book& BookList :: operator[] (int pos){
    if( pos < 0 || pos >= booksCount ){
        cout<<"The position is not valid.\n";
        exit(1);
    }
    return books[pos];
}

ostream &operator<<( ostream &output, const BookList &bl ){
    for( int i=0 ; i<bl.booksCount ; i++ ){
        output<<bl.books[i];
    }
    return output;
}

BookList :: ~BookList(){
    delete [] books;
}
