#include <iostream>
#include "clsBankClient.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsLoginScreen.h"
using namespace std;


int main() {
	
	while (true) {
		if (!clsLoginScreen::loginScreen()) {
			break;
		}

	}
	
}