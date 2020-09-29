#pragma once
#pragma warning (disable:4996)

#include <iostream>
#include <string.h>
#include <cmath>
#include "conversion.h"
#include "ImgSteganogrAphyP.h"
#include "crypto.h"

class PasswordStrength
{
protected:
	conversion con;
	bool flag = true;
	char chack;
	char input[20];
	char imgName[20];
	char imgenc[20];
	char* encrypted;


public:
	//constructores
	PasswordStrength();
	~PasswordStrength();


	char printStrongPass(char*, char);// Check password strength according to criteria
	void passwordOption();//Options for the password
	void getPasswordAndPhoto();//A function that asks for a password and an image to choose from
	void extractPassAndPrint();//A function that extracts the password and presents it to the user
};



