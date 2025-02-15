#pragma once
#include <iostream>
#include "clsScreen.h"
#include "../people/clsPerson.h"
#include "../people/clsClient.h"
#include "../Utilities/clsInputValidation.h"

class clsUpdateClientScreen :protected clsScreen
{
private:
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

    static void ReadClientInfo(clsClient& Client)
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

public:

    static void ShowUpdateClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
        {
            return;// this will exit the function and it will not continue
        }

        _DrawScreenHeader("\tUpdate Client Screen");

        string AccountNumber = "";

        cout << "\nPlease Enter client Account Number: ";
        AccountNumber = clsInputValidation::ReadString();

        while (!clsClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidation::ReadString();
        }

        clsClient Client1 = clsClient::Find(AccountNumber);
    
        _PrintClient(Client1);

        cout << "\nAre you sure you want to update this client y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            cout << "\n\nUpdate Client Info:";
            cout << "\n____________________\n";


            ReadClientInfo(Client1);

            clsClient::enSaveResults SaveResult;

            SaveResult = Client1.Save();

            switch (SaveResult)
            {
            case  clsClient::enSaveResults::svSucceeded:
            {
                cout << "\nAccount Updated Successfully :-)\n";
              
                _PrintClient(Client1);
                break;
            }
            case clsClient::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError account was not saved because it's Empty";
                break;

            }

            }

        }

    }
};

