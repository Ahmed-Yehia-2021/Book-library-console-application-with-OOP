#include "User.h"
#include "Book.h"
#include "UserList.h"
#include "BookList.h"
#define oo 1000000

void main_menu(){
    cout<<"Select one of the following choices : \n";
    cout<<"1- Users menu.\n";
    cout<<"2- Books menu.\n";
    cout<<"3- Exit.\n";
}

void user_menu(){
    cout<<"\n#USERS MENU :\n";
    cout<<"1- Create a user and add it to the list.\n";
    cout<<"2- Display all users.\n";
    cout<<"3- Search for a user.\n";
    cout<<"4- Back to main menu.\n";
}

void search_user_menu(){
    cout<<"\n#SEARCH FOR A USER :\n";
    cout<<"1- Search by name.\n";
    cout<<"2- Search by ID.\n";
    cout<<"3- Back to users menu.\n";
}

void delete_user(){
    cout<<"\n#DELETE USER :\n";
    cout<<"1- Delete user.\n";
    cout<<"2- Back to users menu.\n";
}

void update_user(){
    cout<<"\n#UPDATE USER :\n";
    cout<<"1- Name.\n";
    cout<<"2- Age.\n";
    cout<<"3- Email.\n";
    cout<<"4- Password.\n";
    cout<<"5- Delete.\n";
    cout<<"6- Back to users menu.\n";
}

void book_menu(){
    cout<<"\n#BOOKS MENU :\n";
    cout<<"1- Create a book and add it to the list.\n";
    cout<<"2- Display all books.\n";
    cout<<"3- Search for book.\n";
    cout<<"4- Get the highest rated book.\n";
//    cout<<"5- Get books of the same author.\n";
    cout<<"5- Back to main menu.\n";
}

void search_book_menu(){
    cout<<"\n#SEARCH FOR A BOOK :\n";
    cout<<"1- Search by title.\n";
    cout<<"2- Search by ID.\n";
    cout<<"3- Back to books menu.\n";
}

void reach_book(){
    cout<<"1- Update title :\n";
    cout<<"2- Update category.\n";
    cout<<"3- Update author.\n";
    cout<<"4- Delete.\n";
    cout<<"5- Giving rate book.\n";
    cout<<"6- Getting average rating.\n";
    cout<<"7- Getting other books of this author.\n";
    cout<<"8- Back to books menu.\n";
}

UserList ul(oo);
BookList bl(oo);
void choosing_user_menu(int ch_user){
    while( ch_user != 4 ) {
        user_menu();
        cin>>ch_user;

        if (ch_user == 1) {
            int userNums;
            cout << "Enter the number of users : ";
            cin >> userNums;
            ul.addUSer(userNums);
            cout << "\nData was added successfully.\n";
        }// end small if

        else if(ch_user == 2){ ( ul.isEmpty() ) ? cout<<"The user list is empty.\n" : cout<<ul; }

        else if(ch_user == 3){
            search_user_menu();
            int sh_user_menu;
            cin>>sh_user_menu;

            if(sh_user_menu == 1 || sh_user_menu==2){
                User *rt_user;
                if(sh_user_menu == 1) {
                    string nm;
                    cout << "Enter the name : ";
                    cin >> nm;
                    rt_user = ul.searchByName(nm);
                }else{
                    int ID;
                    cout<<"Enter the ID : ";
                    cin>>ID;
                    rt_user = ul.searchById(ID);
                }// end if & else of choosing search way

                if( rt_user != nullptr ) {
                    cout << *rt_user;

                    int up_user;
                    cout << "If you want to update user enter 1 : ";
                    cin >> up_user;
                    if (up_user == 1) {
                        update_user();

                        int ch_up_user;
                        cin>>ch_up_user;
                        if (ch_up_user == 1){
                            string new_nm;
                            cout<<"Enter the new name : ";
                            cin>>new_nm;
                            rt_user->setName(new_nm);
                            cout << "\nData was added successfully.\n";
                        }
                        else if(ch_up_user == 2){
                            int new_age;
                            cin>>new_age;
                            rt_user->setAge(new_age);
                            cout << "\nData was added successfully.\n";
                        }
                        else if(ch_up_user == 3){
                            string new_em;
                            cin>>new_em;
                            rt_user->setEmail(new_em);
                            cout << "\nData was added successfully.\n";
                        }
                        else if(ch_up_user == 4){
                            string new_pass;
                            cin>>new_pass;
                            rt_user->setPassword(new_pass);
                            cout << "\nData was added successfully.\n";
                        }
                        else if(ch_up_user == 5){
                            delete_user();
                            int del;
                            cin>>del;
                            if( del == 1 )
                            { ul.deleteUser( rt_user->getId() ); cout<<"\nThe user was deleted successfully.\n"; }
                        }

                    }// end if of update user

                }else{ cout<<"NOT FOUND.\n"; }

            }// end if of searching

        }// end else if of choosing search for a user

    }// end while
}

int main() {
    main_menu();

    int ch_1 = 1;
    while( ch_1 < 3 ) {
        cin >> ch_1;
        if( ch_1 >= 3 ){ break; }

        if (ch_1 == 1) { choosing_user_menu(9); }// end if of user_menu

        else if(ch_1 == 2){
            int ch_book = 1;
            while(ch_book < 5){
                book_menu();
                cin>>ch_book;

                if(ch_book == 1){
                    int book_nums;
                    cout<<"\nEnter the number of books you want to add : ";
                    cin>>book_nums;
                    while(book_nums--){
//                        User adding_author = bl.addBook();
//
//                        int add_author;
//                        cout<<"If you want to add author enter 1 or 0 if you don't : ";
//                        if(add_author == 1){
//                            int exist_author;
//                            cout<<"If this author existed before enter 1 or 0 if not : ";
//                            cin>>exist_author;
//                            if( exist_author == 1 ){
//                                int id;
//                                cout<<"Enter his ID : ";
//                                cin>>id;
//                                ( ul.searchById(id) == nullptr ) ? cout<<"\nNOT FOUND.\n" :
//                            }
//
//                            cin>>adding_author;
//
//                        }
                    }// end while of receiving books


                    cout<<"\nThe data was added successfully.\n";
                }// end if of creating a book

                else if(ch_book == 2){ cout<<bl; }

                else if(ch_book == 3){
                    search_book_menu();
                    int search_way;
                    cin>>search_way;

                    if(search_way == 1 || search_way == 2){
                        Book *b;
                        if(search_way == 1){
                            string title;
                            cout<<"Enter the name : ";
                            cin>>title;
                            b = bl.searchBook(title);
                        }else{
                            int ID;
                            cout<<"Enter the ID : ";
                            cin>>ID;
                            b = bl.searchBook(ID);
                        }// defining search way

                        if(b != nullptr) {
                            cout<<*b;
                            reach_book();
                            int up_book;
                            cin >> up_book;
                            if (up_book == 1) {
                                string new_tit;
                                cout<<"Enter the new title : ";
                                cin >> new_tit;
                                b->setTitle(new_tit);
                                cout << "\nThe data was added successfully.\n";
                            }

                            else if (up_book == 2) {
                                string new_cat;
                                cout<<"Enter the new category : ";
                                cin >> new_cat;
                                b->setCategory(new_cat);
                                cout << "\nThe data was added successfully.\n";
                            }

                            else if (up_book == 3) {
                                update_user();

                                if (up_book == 1){
                                    string new_nm;
                                    cout<<"Enter the new name : ";
                                    cin>>new_nm;
                                    b->getAuthor().setName(new_nm);
                                    cout << "\nData was added successfully.\n";
                                }
                                else if(up_book == 2){
                                    int new_age;
                                    cin>>new_age;
                                    b->getAuthor().setAge(new_age);
                                    cout << "\nData was added successfully.\n";
                                }
                                else if(up_book == 3){
                                    string new_em;
                                    cin>>new_em;
                                    b->getAuthor().setEmail(new_em);
                                    cout << "\nData was added successfully.\n";
                                }
                                else if(up_book == 4){
                                    string new_pass;
                                    cin>>new_pass;
                                    b->getAuthor().setPassword(new_pass);
                                    cout << "\nData was added successfully.\n";
                                }
                                else if(up_book == 5){
                                    delete_user();
                                    int del;
                                    cin>>del;
                                    if( del == 1 )
                                    { ul.deleteUser( b->getAuthor().getId() ); cout<<"\nThe user was deleted successfully.\n"; }
                                }

                            }// update author

                            else if(up_book == 4){ bl.deleteBook(b->getId()); cout<<"\nThe was removed.\n"; }

                            else if(up_book == 5){
                                double give_rate;
                                cout<<"Enter the rate : ";
                                cin>>give_rate;
                                b->setAvgRating(give_rate);
                            }

                            else if(up_book == 6){ cout<<"The average rating is "<<b->getAvgRating()<<endl; }

                            else if(up_book == 7){ bl.getBooksForUser( b->getAuthor() ); }

                        }// end if of choosing update way
                        else{ cout<<"NOT FOUND.\n"; }

                    }// end if of choosing search way

                }// end else if of searching for a book

                else if(ch_book == 4){ cout<<bl.getTheHighestRatedBook(); }

            }// end while of book menu

            main_menu();

        }// end else if of choosing book menu

        main_menu();

    }// end while of the program
    cout<<"\nGOOD BYE.\n";

    return 0;
}
