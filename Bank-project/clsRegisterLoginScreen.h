#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>

class clsRegisterLoginScreen :
    protected clsScreen
{

public:
    static void registerLogin() {
        _drawScreenHeader("Login Register Screen");

        vector <clsUser::stRegisterLogin> vRegisters = clsUser::getLoginRegister();

        cout << "______________________________________________________________________________________________________________" << endl;
        cout << setw(25) << left << " | Time" << setw(15) << left << " | User Name" << setw(15)
            << left << " | Password" << setw(15) << left << " | Permission" << endl;
        cout << "______________________________________________________________________________________________________________" << endl;


        for (clsUser::stRegisterLogin& registerL : vRegisters) {
            cout << setw(25) << left << " | " + registerL.time << setw(15) << left << " | " + registerL.username
                << setw(15) << left << " | " + registerL.password  << setw(15) << left <<
                " | " + to_string(registerL.permission) << endl;
        }
    }
};

