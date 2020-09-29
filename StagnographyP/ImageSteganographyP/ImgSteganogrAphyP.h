#pragma once
#pragma warning (disable:4996)

#include<opencv2/opencv.hpp>
#include <iostream>
#include "conversion.h"
#include"PasswordStrength.h"

class ImgSteganogrAphyP
{
protected:
	char* strBin;

public:
	//constructores
	ImgSteganogrAphyP();
	~ImgSteganogrAphyP();

	/*
	 A function receives as input three sequences of characters:
	 The password is translated to STRBIN bits, name image before encryption, image name after encryption
	 The function performs password encryption into a new selected image.
	*/
	void ImgStegAnographyP(char*, char*, char*);

	/*
	  A function receives as input a sequence of characters: the name of the image encrypted with an encrypted password.
	  And returns as output - a sequence of characters that are the encrypted password in the image.
	*/
	char* decipheringPss(char*);

};

