#include "conversion.h"
#pragma warning (disable:4996)

using namespace std;

//constructors
conversion::conversion() :_ch(nullptr), _sBin(nullptr) {}
conversion::~conversion() {
	if (_ch) {
		delete[] _ch;
		_ch = nullptr;
	}
	if (_sBin) {
		delete[] _sBin;
		_sBin = nullptr;
	}
}

//setter & getter
void conversion::ch(char* ch) { _ch = ch; }
void conversion::ch(int i, char ch) { _ch[i] = ch; }
char* conversion::ch() const { return _ch; }


//conversion binary to char
//For removing the password size - we need the first 8 bits we take out in the first bytes, 
//which is as above for the password size.
int conversion::binaryToChar(char* strbin) {
	//cout << strbin;
	int hex = 0;
	int count = -1;
	for (int i = 8; i >= 0; i--) {
		if (strbin[i] == '1')
			hex += pow(2, count);
		count++;
	}

	return hex;
}

//conversion binary to string
//For decoding from the 8th bit onwards, the rest of the bits of the password
char* conversion::binaryToStr(char* strbin) {
	//cout << strbin;

	int longStr = strlen(strbin);
	ch(new char[longStr]);


	int counter = 0;
	for (size_t i = 0; i < longStr; i++)
	{
		int hex = 0;
		int count = -1;
		for (int j = 8 * (counter + 1); j >= counter * 8; j--) {
			if (strbin[j] == '1')
				hex += pow(2, count);
			count++;
		}
		counter++;


		ch(i, (char)hex);
	}
	return ch();
}

//conversion string to binary
//For encrypting the password size first and then encrypting the encrypted password per image 
//(first 8 bits inserted for the password size)
char* conversion::strToBinary(const char* s)
{
	int n = strlen(s);

	string sbin = "";

	// Convert ASCII value to binary 
	for (int i = 0; i <= n + 1; i++)
	{

		string bin = "";
		int val;
		if (i == 0) {
			val = strlen(s);
		}
		else {
			// convert each char to 
			// ASCII value 
			val = int(s[i - 1]);
		}
		while (val > 0)
		{
			(val % 2) ? bin.push_back('1') :
				bin.push_back('0');
			val /= 2;
		}
		if (bin.size() <= 8 && !bin.empty()) {
			for (size_t i = bin.size(); i < 8; i++)
				bin.push_back('0');
		}
		reverse(bin.begin(), bin.end());
		//cout << bin << " ";
		sbin += bin;
	}
	//cout << '\n' << sbin;

	
	_sBin = new char[sbin.size() +1];
	strcpy(_sBin, sbin.c_str());
	_sBin[sbin.size()] = '\0';

	return _sBin;
}