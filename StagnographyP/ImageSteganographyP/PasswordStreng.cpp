#include "PasswordStrength.h"

using namespace std;

PasswordStrength::PasswordStrength() :flag('rtue'), chack(), input(), imgName(), imgenc("new"), encrypted(nullptr) {}
PasswordStrength::~PasswordStrength() {}

ImgSteganogrAphyP img;

// Check password strength according to criteria
char PasswordStrength::printStrongPass(char* input, char chack)
{
	int n = strlen(input);
	int sum = 0;

	// Checking lower alphabet in string 
	int hasLower = 0, hasUpper = 0, hasDigit = 0, hasSpecialChar = 0;
	const char* normalChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 ";

	/*
	Quantity check - uppercase / lowercase letters, numbers and characters
	To calculate the score
	*/
	for (int i = 0; i < n; i++) {
		if (islower(input[i]))
			hasLower++;
		if (isupper(input[i]))
			hasUpper++;
		if (isdigit(input[i]))
			hasDigit++;

		bool specialChar = false;
		for (size_t j = 0; j < strlen(normalChars); j++) {
			if (input[i] == normalChars[j])
				specialChar = true;
		}
		if (!specialChar)
			hasSpecialChar++;
	}



	sum += n * 4;//sum + = (password length * 4)
	if (0 < hasUpper)
		sum += (n - hasUpper) * 2;//sum + = ((uppercase number - password length) * 2)
	if (0 < hasLower)
		sum += (n - hasLower) * 2; // sum + = ((number of lowercase letters - password length) * 2)
	sum += hasDigit * 4 + hasSpecialChar * 6;// sum + = (number of digits * 4) + (number of symbols * 6)
	sum += (hasDigit + hasSpecialChar) * 2;//sum + = ((number of symbols + digits in the middle of the password) * 2)

/*
Add 2 points for each requirement:
password length> = 8, special character,number, uppercase letter, lowercase letter.
*/
	if (n >= 8)
		sum += 2;
	if (hasDigit > 0)
		sum += 2;
	if (hasLower > 0)
		sum += 2;
	if (hasSpecialChar > 0)
		sum += 2;
	if (hasUpper > 0)
		sum += 2;
	//If the password consists of only letters then a sum - = (password length)
	if (n == hasLower + hasUpper)
		sum -= n;
	//If the password consists of numbers only then sum - = (password length)
	if (n == hasDigit)
		sum -= n;

	if ('0' == chack)
		cout << "\nThe strength of your password Before the Subtraction of the score is " << sum << '\n';

	int countlow = 0;
	int countsupr = 0;
	int countdig = 0;

	/*
	For the number of uppercase and lowercase letters and numbers
	sum - = (quantity * 2)
	*/
	for (size_t i = 0; i < n - 1; i++) {

		if (islower(input[i])) {
			if ((int)input[i] <= 119 && (int)input[i + 1] >= 97) {
				sum -= 2;
				countlow++;
			}
		}
		if (isupper(input[i])) {
			if ((int)input[i] <= 87 && (int)input[i + 1] >= 65) {
				sum -= 2;
				countsupr++;
			}
		}
		if (isdigit(input[i]))
			if ((int)input[i] <= 57 && (int)input[i + 1] >= 48) {
				sum -= 2;
				countdig++;
			}
	}


	/*
	 If there is a sequence of letters in ascending or descending order then sum - = (number of occurrences of any sequence * 3)
	-If there is a sequence of numbers in ascending or descending order then sum - = (the number of occurrences of any sequence * 3)
	*/
	int inrowdig = 0;
	int introwch = 0;
	for (size_t i = 1; i < n - 1; i++) {
		if (isdigit(input[i])) {
			if ((int)input[i] - (int)input[i + 1] == 1 && (int)input[i + 1] - (int)input[i] == -1) {
				sum -= 3;
				inrowdig++;
			}

		}
		else {
			if ((int)input[i] - (int)input[i + 1] == 1 && (int)input[i + 1] - (int)input[i] == -1) {
				sum -= 3;
				introwch++;
			}

		}
	}
	//Explain to the user about subtracting points for password strength
	if ('0' == chack) {
		cout << "subtracting:" << countlow * -2 << " subtracting points- The amount of lowercase letters\n";
		cout << "subtracting:" << countsupr * -2 << " subtracting points- The amount of capital letters\n";
		cout << "subtracting:" << countdig * -2 << " subtracting points-  The amount of digits\n";
		cout << "subtracting:" << inrowdig * -3 << " subtracting points- sequence of digit in  ascending or descending order\n";
		cout << "subtracting:" << introwch * -3 << " subtracting points- sequence of letters in ascending or descending order\n";

	}
	//In any case, we will keep the value range of the score up to a score of 100. But a user can not enter a password less than a score of 70.
	if (sum > 100)
		sum = 100;

	cout << "\nThe strength of your password is: " << sum << '\n';


	/*Strength type of password
	weak: 70-80
	moderate: 80-90
	Strong: 90-100
	*/
	// Strength of password 
	cout << "\nthe srtong of password: - ";
	if (sum > 90)
		cout << "Strong" << endl;
	else if (sum > 80 && sum <= 90)
		cout << "Moderate" << endl;
	else if (sum > 70 && sum <= 80)
		cout << "Weak\n" << endl;
	else {
		cout << "Your password is too weak. Please enter a new password \n";
		return '0';
	}

	if (sum < 100) {
		cout << "Do you want to improve the password strength score Press 0\n otherwise click any button\n";
		cin >> chack;
		return chack;
	}
}
////Options for the password
void PasswordStrength::passwordOption() {

	do {
		cout << "Press '0' if you want an explanation of the password strength \nOtherwise press any button to enter the password: \n";
		cin >> chack;
		if (chack == '0') {
			cout << "Password length must be at least 8 characters (up to 12 characters).\n";
			cout << " - The password can be uppercase(A - Z)\n";
			cout << " - The password can be lowercase(a - z)\n";
			cout << " - Password can contain digits(0 - 9)\n";
			cout << " - The password can contain symbols(such as!, @ ...)\n";

			cout << "\nA user cannot enter a password less than a score of 70.\n";
			cout << "weak: 70 - 80\n";
			cout << "moderate : 80 - 90\n";
			cout << "Strong : 90 - 100 \n";
		}
		cout << "Please enter your password\n";
		do {
			try {
				cin >> input;
				if (strlen(input) > 12)
					throw "Your password is longer than 12 characters.\nPlease enter a password between 8 and 12 characters ";
				if (strlen(input) < 8)
					throw "Your password is shorter than 8 characters. \nPlease enter a password between 8 and 12 characters\n";
			}
			catch (const char* str) {
				cout << str;
			}
			catch (...) {}
		} while (strlen(input) > 12 || strlen(input) < 8);
		cout << "Press '0' if you want to know what the score was about and what the password strength score is \n Otherwise press any button\n";
		cin >> chack;


	} while ('0' == printStrongPass(input, chack));
	flag = false;
}
//A function that asks for a password and an image to choose from
void PasswordStrength::getPasswordAndPhoto() {

	if (flag) {
		do {

			cout << "Please enter your password\n";
			do {
				try {
					cin >> input;
					if (strlen(input) > 12)
						throw "Your password is longer than 12 characters.\nPlease enter a password between 8 and 12 characters ";
					if (strlen(input) < 8)
						throw "Your password is shorter than 8 characters. \nPlease enter a password between 8 and 12 characters\n";
				}
				catch (const char* str) {
					cout << str;
				}
				catch (...) {}
			} while (strlen(input) > 12 || strlen(input) < 8);

		} while ('0' == printStrongPass(input, '1'));
	}

	cout << "Do you want to use the images in the database prass '0' .\nTo insert a new image prass '1' \n For default image Click any button :\n";
	cin >> chack;
	if (chack == 1) {
		cout << "Please enter the name of the image\n";
		cout << "    * You need to make sure the image is in the program folder\n";
		cout << "    ** andthe image should be in BMP format\n";

		try {
			cin >> imgName;
		}
		catch (...) {
			cout << "Image name too long Please change name to shorter name\n";
		}
		cout << "Enter the name of the image that contains the encrypted password\n";
		try {
			cin >> imgenc;
		}
		catch (...) {
			cout << "Image name too long Please change name to shorter name\n";
		}
	}
	else if (chack == '0') {
		cout << "To image of car Tap '0'\nTo image of Waterfall Tap '1'\nTo image of frog Tap '2'\n";
		enum image
		{
			car, Waterfall, frog
		};
		image chosenimg;
		int chose;
		do
		{

			cin >> chose;
			chosenimg = (image)chose;
			switch (chose)
			{
			case car:
				strcpy(imgName, "RCar");
				strcat(imgenc, imgName);
				break;
			case Waterfall:
				strcpy(imgName, "waterfall");
				strcat(imgenc, imgName);
				break;
			case frog:
				strcpy(imgName, "frog");
				strcat(imgenc, imgName);
				break;
			default:
				cout << "Enter numbers 0 or 1 or 2\n";
				break;
			}
		} while (chose != chosenimg);

	}
	else {

		strcpy(imgName, "lena");
		strcat(imgenc, imgName);
	}
	do
	{

		try {
			encrypted = encryptDecrypt(input);
			cout << "Encrypted:" << encrypted << "\n";

			img.ImgStegAnographyP(con.strToBinary(encrypted), imgName, imgenc);
			chack = '1';
		}
		catch (const char* str) {
			cout << str;
			try {
				cin >> imgName;
				cout << "Image name too long Please change name to shorter name\n";
			}
			catch (...) {
			}
		}

	} while (chack == '0');
}
//A function that extracts the password and presents it to the user
void PasswordStrength::extractPassAndPrint() {
	cout << encryptDecrypt(img.decipheringPss(imgenc));
}

