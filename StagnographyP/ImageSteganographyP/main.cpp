#include<iostream>
#include<string.h>

using namespace std;
#include "PasswordStrength.h"
#include "ImgStegAnographyP.h"
#include "conversion.h"
#include "crypto.h"


using namespace std;
using namespace cv;



enum MenuOption {
	EXIT_MENU,
	PASSWORD_STRENGTH_CHACK,
	IMAGE_PASSWORD_ENCRYPTION,
	DECIPHRIG_A_PASSWORD_FROM_AN_IMAGE,

	// a neat trick for for-loop initial and final values
	FIRST_MENU_OPTION = EXIT_MENU,
	LAST_MENU_OPTION = DECIPHRIG_A_PASSWORD_FROM_AN_IMAGE
};

const char* const menuOptionStrings[] = {
	"exit the program",
	"Checking password strength and entering a password to encryption",
	"Password Encryption to Image",
	"To decode a password from an encrypted image",
};


int main(void) {

	conversion con;
	PasswordStrength pass;
	MenuOption chosen;

	// Everything happens inside of this do-while loop, until the user
	//     has decided to exit (or an error occurs).
	do {
		cout << endl << "Menu options:" << endl << endl;

		const int menuIndent = 10;

		// The user will see:
		for (chosen = FIRST_MENU_OPTION; chosen <= LAST_MENU_OPTION;
			chosen = (MenuOption)((int)chosen + 1)) {
			cout << setw(menuIndent) << " " << chosen << " -- ";
			cout << menuOptionStrings[chosen] << endl;
		}
		cout << endl;

		int chosenInt;
		cout << "Please choose a menu option: ";
		cin >> chosenInt;
		// After the user has input an int, it is cast to a
		//   MenuOption variable.
		chosen = (MenuOption)chosenInt;

		switch (chosen) {
		case EXIT_MENU:
			// adios
			cout << "thex for using the program\n";
			break;
		case PASSWORD_STRENGTH_CHACK:

			pass.passwordOption();
			break;

		case IMAGE_PASSWORD_ENCRYPTION:

			pass.getPasswordAndPhoto();
			break;

		case DECIPHRIG_A_PASSWORD_FROM_AN_IMAGE:

			pass.extractPassAndPrint();
			break;
		default:
			break;
		}
	} while (chosen != EXIT_MENU);


	return 0;
}