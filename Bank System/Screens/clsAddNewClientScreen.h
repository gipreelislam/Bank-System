#pragma once
#include <iostream>
#include "clsScreen.h"
#include "../people/clsClient.h"
#include "../Utilities/clsInputValidation.h"
#include <iomanip>

class clsAddNewClientScreen : protected clsScreen
{
private:
    static void _ReadClientInfo(clsClient& Client)
    {
        cout << "\nEnter FirstName: ";
        Client.FirstName = clsInputValidation::ReadString();

        cout << "\nEnter LastName: ";
        Client.LastName = clsInputValidation::ReadString();

        cout << "\nEnter Email: ";
        Client.Email = clsInputValidation::ReadString();

        cout << "\nEnter Phone: ";
        Client.Phone = clsInputValidation::ReadString();

        cout << "\nEnter PinCode: ";
        Client.PinCode = clsInputValidation::ReadString();

        cout << "\nEnter Account Balance: ";
        Client.AccountBalance = clsInputValidation::ReadFloatNumber();
    }

    static void _PrintClient(clsClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

public:

    static void ShowAddNewClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
        {
            return;// this will exit the function and it will not continue
        }


        _DrawScreenHeader("\t  Add New Client Screen");

        string AccountNumber = "";

        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidation::ReadString();
        while (clsClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number Is Already Used, Choose another one: ";
            AccountNumber = clsInputValidation::ReadString();
        }

        clsClient NewClient = clsClient::GetAddNewClientObject(AccountNumber);


        _ReadClientInfo(NewClient);

        clsClient::enSaveResults SaveResult;

        SaveResult = NewClient.Save();

        switch (SaveResult)
        {
        case  clsClient::enSaveResults::svSucceeded:
        {
            cout << "\nAccount Addeded Successfully :-)\n";
            _PrintClient(NewClient);
            break;
        }
        case clsClient::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError account was not saved because it's Empty";
            break;

        }
        case clsClient::enSaveResults::svFaildAccountNumberExists:
        {
            cout << "\nError account was not saved because account number is used!\n";
            break;

        }
        }
    }



};

