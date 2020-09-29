#include "crypto.h"

//Function for encrypting and decrypting a password
/*
Define a key character, and for each character in the string you want to encrypt you apply the key.
Once you want to disable the encryption of the encrypted data,
you just go over the string and activate the key again.
*/

char* encryptDecrypt(char* toEncrypt) {
	char key[5] = { 'N', '@', 'F','e','400' }; //The key
	char* output = toEncrypt;

	for (int i = 0; i < strlen(toEncrypt); i++)
		output[i] = toEncrypt[i] ^ key[i % (sizeof(key) / sizeof(char))];//Activating Xor

	return output;

}