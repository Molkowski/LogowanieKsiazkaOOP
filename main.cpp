#include <iostream>
#include <windows.h>
#include <vector>
#include <fstream>
#include "users.h"

using namespace std;

int main()
{
    int choice;

    vector <Users> usersList;

    void UserWriteToVector (vector <Users> &usersList);
    void LoginUser (vector <Users> &usersList);
    void AddingUser (vector <Users> &usersList);

    while (1)
    {
        UserWriteToVector (usersList);
        system("cls");
        cout << "Panel logowania" << endl;
        cout << "1. Logowanie " << endl;
        cout << "2. Rejestracja " << endl;
        cout << "3. Zakoncz program " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            LoginUser (usersList);
            break;
        case 2:
            AddingUser (usersList);
            break;
        case 3:
            exit(0);
            break;
        }
    }

    return 0;
}

void UserWriteToVector (vector <Users> &usersList)
{
    string id, log, pass;

    fstream file;
    string line;
    string user;
    string word;
    int lengthOfContact=0;

    int j=-1;


    file.open("UsersList.txt", ios::in);
    if (file.good()==false)
    {
        file.open("UsersList.txt", ios::out |ios::app);
    }
    while (getline(file,line))
    {
        user=line;
        lengthOfContact=line.length();
        for (int i=0; i<lengthOfContact; i++)
        {
            if (user[i]!= '|')
            {
                word = word + user[i];
            }
            else if (user[i]=='|')
            {
                ++j;
                if (j==0)
                {
                    id=word;
                }
                if (j==1)
                {
                    log=word;
                }
                if (j==2)
                {
                    pass=word;
                }
                word="";
            }
        }
        Users newUser(id, log, pass);
        usersList.push_back(newUser);
        j=-1;
    }
}

int UserCheckID (vector <Users> &usersList)
{
    int id=0;
    int sizeOfVector;
    string idOfLastUser;
    sizeOfVector=usersList.size();
    if (sizeOfVector==0)
    {
        id=0;
    }
    else
    {
        idOfLastUser=usersList[sizeOfVector-1].getUserId();
        id=atoi(idOfLastUser.c_str());
    }
    return id;
}

void LoginUser (vector <Users> &usersList)
{
    string login;
    string password;
    bool test;
    int UserId;
    int sizeOfVector;
    sizeOfVector=usersList.size();
    int k=0;

    while (1)
    {
        cout << "Podaj login: ";
        cin >> login;
        for (int i=0; i<sizeOfVector; i++)
        {
            if (login==usersList[i].getLogin())
            {
                k+=1;
            }
        }
        if (k==0)
        {
            cout << "Uzytkownik o takim loginie nie istnieje! Podaj poprawna nazwe uzytkownika " << endl;
        }
        else
        {
            break;
        }
    }

    int i=0;
    while (1)
    {
        if (login==usersList[i].getLogin())
        {
            usersList[i].getLogin();
            break;
        }
        i++;
    }

    cout << "Podaj haslo: ";
    cin >> password;
    while (1)
    {
        if (password==usersList[i].getPassword())
        {
            cout << "Zalogowano " << endl;
            test=1;
            system("pause");
            break;
        }
        else
        {
            cout << "Haslo nieprawidlowe" << endl;
            cout << "Podaj haslo: ";
            cin >> password;
        }
    }
    if(test==1)
    {
        UserId= atoi(usersList[i].getUserId().c_str());
    }
}

void AddingUser (vector <Users> &usersList)
{
    int ID=UserCheckID(usersList)+1;
    string login, password, auxiliary;
    int sizeOfVector;
    sizeOfVector=usersList.size();

    cout << "Podaj Login: ";
    getline(cin,auxiliary);

    getline(cin,login);
    for (int i=0; i<sizeOfVector; i++)
    {
        if (usersList[i].getLogin()==login)
        {
            cout << "Uzytkownik o takim nicku istnieje, wpisz ponownie inna nazwe " << endl;
            cout << "Podaj Login: ";
            getline(cin,login);
            i=0;
        }
    }

    cout << "Podaj haslo: ";
    getline(cin,password);

    fstream file;
    file.open("UsersList.txt", ios::out |ios::app);
    file<<ID <<"|";
    file<<login<<"|";;
    file<<password<<"|";
    file<<endl;
    file.close();
    system("pause");
}
