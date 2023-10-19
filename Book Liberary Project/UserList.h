//
// Created by Ahmed.Yehia on 9/26/2022.
//

#ifndef MAIN_CPP_USERLIST_H
#define MAIN_CPP_USERLIST_H

#include "User.h"

class UserList {
private:
    User* users;
    int capacity;
    int userCount;
public:
    UserList();
    UserList(int );

    void addUSer(int sz);

    User* searchByName(string );
    User* searchById(int );

    void deleteUser(int );

    bool isEmpty();

    friend ostream &operator<<( ostream &, const UserList & );

    ~UserList();
};


#endif //MAIN_CPP_USERLIST_H
