#pragma once
#pragma warning (disable:4996)

#include <iostream>
#include <string.h>
#include <cmath>


class conversion
{
	//_ch,_sBin-Strings that receive characters after repetition
	char* _ch;

protected:
	char* _sBin;
public:
	//constructores
	conversion();
	~conversion();

	//setter & getter
	void ch(char*);
	void ch(int, char);
	char* ch()const;


	int binaryToChar(char*);//conversion binary to char

	char* binaryToStr(char*);//conversion binary to string

	char* strToBinary(const char*);//conversion string to binary

};
