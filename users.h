#include <iostream>

using namespace std;

class Users
{
    string userID;
    string login;
    string password;

public:
    Users (string="brak ID", string="Brak loginu", string="Brak hasla");
    ~Users();

    string getUserId() const;
    string getLogin() const;
    string getPassword () const;

    void setUserID(string);
    void setLogin(string);
    void setPassword(string);

};
