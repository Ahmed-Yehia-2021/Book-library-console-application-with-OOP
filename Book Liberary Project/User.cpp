//
// Created by Ahmed.Yehia on 9/22/2022.
//

#include "User.h"

int User :: count = 0;

User :: User() {
    name = "Unknown";
    age = 0;
    count++;
    id = count;
    password = "Unknown";
    email = "Unknown";
}

User :: User(string name, int age, string email, string password){
    this->name = name;
    this->age = age;
    this->email = email;
    this->password = password;
    count++;
    id = count;
}

User :: User(const User &u_cpy){
    name = u_cpy.name;
    age = u_cpy.age;
    password = u_cpy.password;
    email = u_cpy.email;
    id = u_cpy.id;
}

bool User :: operator==( const User &us ){
    if( name!=us.name || id!=us.id || password!=us.password || age!=us.age || email!=us.email  )
        return false;
    return true;
}

void User :: setName(string name){ this->name = name; }
string User :: getName() const { return name; }

void User :: setPassword(string password){ this->password = password; }
string User :: getPassword() const { return password; }

void User :: setEmail(string email){ this->email = email; }
string User :: getEmail() const { return email; }

void User :: setAge(int age){ this->age = age; }
int User :: getAge(){ return age; }

void User :: setId(int id){ this->id = id; }
int User :: getId(){ return id; }

void User :: Display(){
//    cout<<"\n***********************************************\n";
    cout<<"Name : "<<name<<endl;
    cout<<"Age : "<<age<<endl;
    cout<<"ID : "<<id<<endl;
    cout<<"Email : "<<email<<endl;
    cout<<"Password : "<<password<<endl;
}

istream &operator>>( istream &input, User &us ){
    cout<<"\nEnter the data of user_"<<us.id<<" :\n";
    cout<<" Name : ";           input>>us.name;
    cout<<"Age : ";             input>>us.age;
    cout<<"Email : ";           input>>us.email;
    cout<<"Password : ";        input>>us.password;
    return input;
}

ostream &operator<<( ostream &output, const User &us ){
    output<<"\n***********************************************\n";
    output<<"The data of user_"<<us.id<<" :\n";
    output<<"Name : "<<us.name<<endl;
    output<<"Age : "<<us.age<<endl;
    output<<"ID : "<<us.id<<endl;
    output<<"Email : "<<us.email<<endl;
    output<<"Password : "<<us.password<<endl;
    output<<"***********************************************\n\n";
    return output;
}


