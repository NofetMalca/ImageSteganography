Image Steganography by Nofet_Malca
===================


System-based program for Image Steganography using C++ in Environment-Visual Studio. 
The program performs steganography Encrypt & Decrypt password to / from an image,
It uses Least Significant Bit(LSB) algorithm for Image Steganography using a OpenCV library .

### Installation

1. Install visual studio 2019:
Make sure that latest version of visual studio is installed on your machine.
Refer hrefVS="https://visualstudio.microsoft.com/downloads/" for installation. 

2. Install Open-CV : 
Make sure that latest version of OpenCV is installed on your machine.
Refer hrefOCv="https://www.youtube.com/watch?v=M-VHaLHC4XI&list=PLvv4vffx7TzxHq7bdoZ2gAQOyBaiNl6e6&index=31&t=0s"
repository for installation.(OpenCV library-Image processing performance capability)

open the program ImageSteganographyP.sln:
Verify that the OpenCV environment variable is present (See link of hrefOCv above).

###System implementation - encryption and decryption of password to / from image

The project has 4 main classes:
PasswordStrength - A password strength check class.
Conversion - Class for various conversions.  
Crypto- Password encryption and decryption department.
ImaSteganogrAphyP- A class that encrypts the encrypted password into an image, and decrypts the password from the encrypted image.

The system has the main function -
the executable file of the program that allows the user to perform actions [see below].
 
### Before Running the Program

1. Use the default original image or
   Place your original .bmp/.png image in the ImageSteganographyP directory(Where the .cpp/.h files are located).
2. Use the default ImageAfterEncrypted or
   Place your Image After Encrypted .bmp/.png image in the ImageSteganographyP directory(Where the .cpp/.h files are located).

//In our program we will use image uploading - supporting BMP format.

### After Running the Program

1. Check password strength
   i. The user enters a password (while checking the correctness of the password input).
  ii. The user has the option to see the explanation about a strong password.
 iii. The user has the option to see the password score and details of the point subtraction calculation.
  iv. The user has the option to improve the password if he does not like the score.

2. Encrypt a password into an image
   i. Request the user to enter a password (while checking the password).
  ii. Encrypt the password with the encryption algorithm.
 iii. Show the user the password after encryption.
  iv. Request user to select the file where the encrypted password will be encrypted.
   v. User selects a name for the new image in which the password will be encrypted.
  vi. Create a file of the new image after encrypting the password encrypted within it.
 vii. The user can select the option of displaying the images before and after encrypting the image.

3. Deciphering the password from an image
   i. Request the user to enter the name of the image file in which the password has already been encrypted (of course an encrypted image according to this system method).
  ii. Deciphering the encrypted password from the image in which the password was encrypted.
 iii. Show the user the password before decrypting the encryption.
  iv. Decrypt the password from the encrypted password.
   v. Show the user the original password.
 
### Explain the functions

1.How to check password strength
  For the purpose of determining the strength of the password, we will keep a "score" variable that will calculate the score according to criteria in each change of the password.
  I used the site " http://www.passwordmeter.com/ " .

2.How to Encode the password 
  Password encryption by Exclusive-OR encryption

3.How to Decode the password 
  Password Deciphering by Exclusive-OR Deciphering
 
4. How to Encode the password to image
   In our project the password (in bits) + the password size (in bits) will be encoded into an image 
   using the LSB method in single-bit encoding.
   
   A new image will be created in ImageSteganographyP directory with the secret password hidden in it.

5. How to Decode the password from image
   To decrypt the password from an image, using the LSB method we will take the last bit of any pixel color - decompose the password size from the password itself 
   and then send the password for decoding.
  
   The hidden password will be displayed on your black screen.

### See in Action


Menu options:

          0 -- exit the program
          1 -- Checking password strength and entering a password to encryption
          2 -- Password Encryption for Image
          3 -- To decode a password from an encrypted image

Please choose a menu option: 1
Press '0' if you want an explanation of the password strength
Otherwise press any button to enter the password:
0
Password length must be at least 8 characters (up to 12 characters).
 - The password can be uppercase(A - Z)
 - The password can be lowercase(a - z)
 - Password can contain digits(0 - 9)
 - The password can contain symbols(such as!, @ ...)

A user cannot enter a password less than a score of 70.
weak: 70 - 80
moderate : 80 - 90
Strong : 90 - 100
Please enter your password
msh12457!
Press '0' if you want to know what the score was about and what the password strength score is
 Otherwise press any button
0

The strength of your password Before the Subtraction of the score is 94
subtracting:-4 subtracting points- The amount of lowercase letters
subtracting:0 subtracting points- The amount of capital letters
subtracting:-8 subtracting points-  The amount of digits
subtracting:0 subtracting points- sequence of digit in  ascending or descending order
subtracting:0 subtracting points- sequence of letters in ascending or descending order

The strength of your password is: 82

the srtong of password: - Moderate
Do you want to improve the password strength score Press 0
 otherwise click any button
0
Press '0' if you want an explanation of the password strength
Otherwise press any button to enter the password:
f
Please enter your password
Msh12457!
Press '0' if you want to know what the score was about and what the password strength score is
 Otherwise press any button
f

The strength of your password is: 100

the srtong of password: - Strong

Menu options:

          0 -- exit the program
          1 -- Checking password strength and entering a password to encryption
          2 -- Password Encryption for Image
          3 -- To decode a password from an encrypted image

Please choose a menu option: 2
Do you want to use the images in the database prass '0' .
To insert a new image prass '1'
 For default image Click any button :
0
To image of car Tap '0'
To image of Waterfall Tap '1'
To image of frog Tap '2'
0
Encrypted: 3.TzuqD

Menu options:

          0 -- exit the program
          1 -- Checking password strength and entering a password to encryption
          2 -- Password Encryption for Image
          3 -- To decode a password from an encrypted image

Please choose a menu option:  3

after the seganographly
Msh12457!
Menu options:

          0 -- exit the program
          1 -- Checking password strength and entering a password to encryption
          2 -- Password Encryption for Image
          3 -- To decode a password from an encrypted image

Please choose a menu option: 0
thex for using the program

C:\Users\Moshe\visualStudioProjects\ImageSteganographyP\x64\Debug\ImageSteganographyP.exe (process 18600) exited with code 3.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .


###Sources of information

To check password strength:
http://www.passwordmeter.com/


To use the OpenCV library:
1.
https://docs.opencv.org/2.4/doc/user_guide/ug_mat.html
2.
https://www.youtube.com/watch?v=M-VHaLHC4XI&list=PLvv4vffx7TzxHq7bdoZ2gAQOyBaiNl6e6&index=31&t=0s


Explanation of encryption and decoding password from / to image:
1.
https://www.garykessler.net/library/steganography.html
2.
https://www.researchgate.net/publication/51963913_Steganography_Algorithm_to_Hide_Secret_Message_inside_an_Image


To encrypt and decrypt a password:
https://en.wikipedia.org/wiki/XOR_cipher

