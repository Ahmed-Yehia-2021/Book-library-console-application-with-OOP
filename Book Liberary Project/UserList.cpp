//
// Created by Ahmed.Yehia on 9/26/2022.
//

#include "UserList.h"

UserList :: UserList() : capacity(0), userCount(0) {}

UserList :: UserList(int capacity){
    this->capacity = capacity;
    users = new User[capacity];
    userCount = 0;
}

void UserList :: addUSer(int sz){
    while( sz-- ) {
        if (userCount < capacity) {
            cin>>users[userCount];
            users[userCount].setId(userCount + 1);
            userCount++;

        } else { cout << "The file is already full.\n"; break; }
    }
}

User* UserList :: searchByName(string nm){
    for( int i=0 ; i<userCount ; i++ ){
        if( users[i].getName() == nm ){ return &users[i]; }
    }
    return nullptr;
}

User* UserList :: searchById(int id){
    for( int i=0 ; i<userCount ; i++ ){
        if( users[i].getId() == id ){ return &users[i]; }
    }
    return nullptr;
}

void UserList :: deleteUser(int id){
    for( int i=0 ; i<userCount ; i++ )
        if( users[i].getId() == id ){
            while( i<userCount-1 ){
                users[i] = users[i+1];
                users[i].setId(i+1);
            }
            userCount--;
            capacity--;
            return;
        }//end if
    cout<<"Not Found.\n";
}

bool UserList :: isEmpty(){ return( userCount == 0 ); }

ostream &operator<<( ostream& output, const UserList& us ){
    for( int i=0 ; i<us.userCount ; i++ ){
        output<<us.users[i];
    }
    return output;
}

UserList :: ~UserList(){
    delete [] users;
}