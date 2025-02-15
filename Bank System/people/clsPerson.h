#pragma once
#include <iostream>
#include <string>
using namespace std;

class clsPerson
{

private:

    string _firstName;
    string _lastName;
    string _email;
    string _phone;

public:

    clsPerson(string FirstName, string LastName, string Email, string Phone)
    {

        _firstName = FirstName;
        _lastName = LastName;
        _email = Email;
        _phone = Phone;
    }

    //Property Set
    void SetFirstName(string FirstName)
    {
        _firstName = FirstName;
    }

    //Property Get
    string GetFirstName()
    {
        return _firstName;
    }
    __declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;

    //Property Set
    void SetLastName(string LastName)
    {
        _lastName = LastName;
    }

    //Property Get
    string GetLastName()
    {
        return _lastName;
    }
    __declspec(property(get = GetLastName, put = SetLastName)) string LastName;

    //Property Set
    void SetEmail(string Email)
    {
        _email = Email;
    }

    //Property Get
    string GetEmail()
    {
        return _email;
    }
    __declspec(property(get = GetEmail, put = SetEmail)) string Email;

    //Property Set
    void SetPhone(string Phone)
    {
        _phone = Phone;
    }

    //Property Get
    string GetPhone()
    {
        return _phone;
    }
    __declspec(property(get = GetPhone, put = SetPhone)) string Phone;

    string FullName()
    {
        return _firstName + " " + _lastName;
    }

    void Print()
    {
        cout << "\nInfo:";
        cout << "\n___________________";
        cout << "\nFirstName: " << _firstName;
        cout << "\nLastName : " << _lastName;
        cout << "\nFull Name: " << FullName();
        cout << "\nEmail    : " << _email;
        cout << "\nPhone    : " << _phone;
        cout << "\n___________________\n";

    }

};

