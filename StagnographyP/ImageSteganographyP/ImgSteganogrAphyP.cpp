// ImageSteganographyP.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include"ImgSteganogrAphyP.h"

#include<opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

//constructores
ImgSteganogrAphyP::ImgSteganogrAphyP() :strBin(nullptr) {}

ImgSteganogrAphyP::~ImgSteganogrAphyP() {
	delete[] strBin;
	strBin = nullptr;
}

conversion con;

/*
	 A function receives as input three sequences of characters:
	 The password is translated to STRBIN bits, name image before encryption, image name after encryption
	 The function performs password encryption into a new selected image.
*/
void ImgSteganogrAphyP::ImgStegAnographyP(char* strBbn, char* imageName, char* newimage)
{

	//cout << "\nname\n" << name;
	int pixel = 0;
	int count = 0;

	try
	{
		strcat(imageName, ".bmp");//Insert a name for the encrypted image with the format
		Mat image = imread(imageName);//read file

		//Goes through the pixels and changes the pixel values as needed
		for (int y = 0; y < image.rows; y++)
		{
			for (int x = 0; x < image.cols; x++)
			{

				Vec3b& colorImge = image.at<Vec3b>(y, x);
				for (int color = 0; color < 3; color++) {

					if (count < strlen(strBbn)) {
						pixel = (int)image.at<Vec3b>(y, x)[color];

						if ((int)image.at<Vec3b>(y, x)[color] % 2 == 1 && strBbn[count] == '0')
							image.at<Vec3b>(y, x)[color] --;
						else if ((int)image.at<Vec3b>(y, x)[color] % 2 == 0 && strBbn[count] == '1')
							image.at<Vec3b>(y, x)[color] ++;
						pixel = (int)colorImge[color];
						count++;
					}
				}
				image.at<Vec3b>(y, x) = colorImge;

			}
		}
		imwrite(strcat(newimage, ".bmp"), image);

		namedWindow(imageName, WINDOW_NORMAL);
		imshow(imageName, image);//View the image
		waitKey(0);//Wait for a click from the user
		return;
	}

	catch (...) {
		throw "Failed to open image Please re-enter image name\n";
	}
}

/*
	  A function receives as input a sequence of characters: the name of the image encrypted with an encrypted password.
	  And returns as output - a sequence of characters that are the encrypted password in the image.
*/
char* ImgSteganogrAphyP::decipheringPss(char* newImage) {
	int count = 0;//Count the number of copy operations performed
	int pixel = 0;
	string sBin;
	Mat imageafter = imread(newImage);//Reading the encrypted image

	//Takes out the first 8 characters to know you are encrypted password size
	for (int y = 0; y < imageafter.rows; y++)
	{
		if (count > 7)
			break;
		for (int x = 0; x < imageafter.cols; x++)
		{
			// get pixel
			if (count > 7)
				break;

			Vec3b& color = imageafter.at<Vec3b>(y, x);
			for (int color = 0; color < 3; color++) {
				pixel = (int)imageafter.at<Vec3b>(y, x)[color];
				if (count > 7)
					break;
				if ((int)imageafter.at<Vec3b>(y, x)[color] % 2 == 1)
					sBin.push_back('1');
				else if ((int)imageafter.at<Vec3b>(y, x)[color] % 2 == 0)
					sBin.push_back('0');
				count++;
			}
		}
	}

	//Check password length
	char* sbin = new char[sBin.size()];
	strcpy(sbin, sBin.c_str());//Copies from password to password from string to character sequence

	// size password
	int longOfStr = con.binaryToChar(sbin);
	int maxToRead = (longOfStr + 1) * 8;

	count = 0;
	string strBin = "";

	//Deciphering the encrypted password from the image(in binary)
	for (int y = 0; y < imageafter.rows; y++)
	{
		if (count >= maxToRead)
			break;
		for (int x = 0; x < imageafter.cols; x++)
		{
			// get pixel
			if (count >= maxToRead)
				break;

			Vec3b& color = imageafter.at<Vec3b>(y, x);
			for (int color = 0; color < 3; color++) {
				if (count >= maxToRead)
					break;
				if (count > 7) {
					pixel = (int)imageafter.at<Vec3b>(y, x)[color];
					if ((int)imageafter.at<Vec3b>(y, x)[color] % 2 == 1)
						strBin.push_back('1');
					else if ((int)imageafter.at<Vec3b>(y, x)[color] % 2 == 0)
						strBin.push_back('0');
				}
				count++;
			}
		}
	}
	char* strbin = new char[strBin.size()];
	strcpy(strbin, strBin.c_str());

	cout << "\nafter the seganographly \n";
	//	cout << strBin << '\n';
	//	cout << strbin;

	namedWindow(newImage, WINDOW_NORMAL);
	imshow(newImage, imageafter);
	waitKey(0);

	return con.binaryToStr(strbin);//Returns the binary password before conversion
}
