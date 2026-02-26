#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "global.h"
class clsLoginScreen :
    protected clsScreen
{
private:

public:
    static bool loginScreen() {
        system("cls");
        _drawScreenHeader("Login Screen");
        string username = clsInputValidate::readString("Enter User Name");
        string password = clsInputValidate::readString("Enter Password");

        int counter = 0;
        //int trails = 2;
        while (clsUser::find(username, password).isEmpty()) {

            counter++;
            if (counter == 3) {
                cout << "you are Locked After 3 Failed Trails" << endl;
                return false;
            }

            cout << endl << "Wrong Username/Password!!" << endl;
            cout << "You have " << 3 - counter << " Trails to login" << endl << endl;

            /*trails--;*/ 
            username = clsInputValidate::readString("Enter User Name");
            password = clsInputValidate::readString("Enter Password");

            
        }


        //CurrentUser = clsUser::find(username, password);
        clsUser CurrentUser = clsUser::find(username, password);
        CurrentUser.registerLogin();
        clsMainScreen::showMainMenu();
        return true;
    }
};

