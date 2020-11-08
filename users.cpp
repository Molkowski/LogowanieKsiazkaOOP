#include <iostream>
#include <fstream>
#include "users.h"

using namespace std;


    Users::Users(string id, string log, string pass)
    {
        userID=id;
        login=log;
        password=pass;
    }

    Users::~Users(){

    }

    string Users::getUserId() const{
    return userID;
    }

    string Users::getLogin() const{
    return login;
    }

    string Users::getPassword() const{
    return password;
    }
